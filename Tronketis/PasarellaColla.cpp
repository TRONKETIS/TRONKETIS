#include "pch.h"
#include "PasarelaColla.h"
#include "DB.h"
using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

namespace Tronketis {


    bool PasarelaColla::insertar(CollaDTO^ colla, String^% error) {
        MySqlConnection^ conn = nullptr;

        try {
            conn = DB::GetConnection();
            conn->Open();

            // Inserció simple sense transacció complexa
            String^ query = "INSERT INTO colla (name, location, uni_name, state) " +
                "VALUES (@name, @location, @uni_name, @state)";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@name", colla->nom);
            cmd->Parameters->AddWithValue("@location", colla->localitzacio);

            if (String::IsNullOrWhiteSpace(colla->univ)) {
                cmd->Parameters->AddWithValue("@uni_name", DBNull::Value);
            }
            else {
                cmd->Parameters->AddWithValue("@uni_name", colla->univ);
            }

            cmd->Parameters->AddWithValue("@state", "A");

            cmd->ExecuteNonQuery();

            // Obtenir l'ID
            cmd = gcnew MySqlCommand("SELECT LAST_INSERT_ID()", conn);
            colla->id = Convert::ToInt32(cmd->ExecuteScalar());

            return true;
        }
        catch (Exception^ ex) {
            error = "Error: " + ex->Message;
            return false;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
    }

    bool PasarelaColla::insertarConCap(CollaDTO^ colla, String^ dniCap, String^ telefon, String^% error) {
        bool correcte = false;
        error = "";
        MySqlConnection^ conn = nullptr;
        MySqlTransaction^ tx = nullptr;

        try {
            conn = DB::GetConnection();
            conn->Open();
            tx = conn->BeginTransaction();

            String^ qExisteixColla = "SELECT COUNT(*) FROM colla WHERE name = @name";
            MySqlCommand^ cmdExisteixColla = gcnew MySqlCommand(qExisteixColla, conn, tx);
            cmdExisteixColla->Parameters->AddWithValue("@name", colla->nom);

            int existeixColla = Convert::ToInt32(cmdExisteixColla->ExecuteScalar());
            if (existeixColla > 0) {
                error = "Ja existeix una colla amb aquest nom";
                tx->Rollback();
            }
            else {
                String^ qUsuari =
                    "SELECT COUNT(*) "
                    "FROM usuari "
                    "WHERE dni = @dni "
                    "AND user_role = 'CapColla' "
                    "AND (state != 'Inactive' OR state IS NULL)";

                MySqlCommand^ cmdUsuari = gcnew MySqlCommand(qUsuari, conn, tx);
                cmdUsuari->Parameters->AddWithValue("@dni", dniCap);

                int existeixUsuari = Convert::ToInt32(cmdUsuari->ExecuteScalar());
                if (existeixUsuari == 0) {
                    error = "El usuario seleccionado no existe, está inhabilitado o no tiene rol CapColla.";
                    tx->Rollback();
                }
                else {
                    String^ qCapAltraColla =
                        "SELECT name "
                        "FROM colla "
                        "WHERE cap_de_colla_dni = @dni "
                        "LIMIT 1";

                    MySqlCommand^ cmdCapAltraColla = gcnew MySqlCommand(qCapAltraColla, conn, tx);
                    cmdCapAltraColla->Parameters->AddWithValue("@dni", dniCap);

                    Object^ altraColla = cmdCapAltraColla->ExecuteScalar();
                    if (altraColla != nullptr && altraColla != DBNull::Value) {
                        error = "Este usuario ya es cap de la colla: " + altraColla->ToString();
                        tx->Rollback();
                    }
                    else {
                        String^ qMembreAltraColla =
                            "SELECT colla_name "
                            "FROM membre "
                            "WHERE dni = @dni "
                            "LIMIT 1";

                        MySqlCommand^ cmdMembreAltraColla = gcnew MySqlCommand(qMembreAltraColla, conn, tx);
                        cmdMembreAltraColla->Parameters->AddWithValue("@dni", dniCap);

                        Object^ membreAltraColla = cmdMembreAltraColla->ExecuteScalar();
                        if (membreAltraColla != nullptr && membreAltraColla != DBNull::Value) {
                            error = "Este usuario ya pertenece a la colla: " + membreAltraColla->ToString();
                            tx->Rollback();
                        }
                        else {
                            String^ qInsertColla =
                                "INSERT INTO colla (name, location, uni_name, state, cap_de_colla_dni) "
                                "VALUES (@name, @location, @uni_name, @state, @dniCap)";

                            MySqlCommand^ cmdInsertColla = gcnew MySqlCommand(qInsertColla, conn, tx);
                            cmdInsertColla->Parameters->AddWithValue("@name", colla->nom);
                            cmdInsertColla->Parameters->AddWithValue("@location", colla->localitzacio);

                            if (String::IsNullOrWhiteSpace(colla->univ)) {
                                cmdInsertColla->Parameters->AddWithValue("@uni_name", DBNull::Value);
                            }
                            else {
                                cmdInsertColla->Parameters->AddWithValue("@uni_name", colla->univ);
                            }

                            cmdInsertColla->Parameters->AddWithValue("@state", "A");
                            cmdInsertColla->Parameters->AddWithValue("@dniCap", dniCap);
                            cmdInsertColla->ExecuteNonQuery();

                            MySqlCommand^ cmdLastId = gcnew MySqlCommand("SELECT LAST_INSERT_ID()", conn, tx);
                            colla->id = Convert::ToInt32(cmdLastId->ExecuteScalar());

                            String^ qExisteixCasteller = "SELECT COUNT(*) FROM casteller WHERE dni = @dni";
                            MySqlCommand^ cmdExisteixCasteller = gcnew MySqlCommand(qExisteixCasteller, conn, tx);
                            cmdExisteixCasteller->Parameters->AddWithValue("@dni", dniCap);

                            int existeixCasteller = Convert::ToInt32(cmdExisteixCasteller->ExecuteScalar());
                            if (existeixCasteller == 0 && String::IsNullOrWhiteSpace(telefon)) {
                                error = "Este cap de colla todavía no está dado de alta como casteller. Introduce un teléfono.";
                                tx->Rollback();
                            }
                            else {
                                if (existeixCasteller == 0) {
                                    String^ qInsertCasteller =
                                        "INSERT INTO casteller (dni, tel_num) "
                                        "VALUES (@dni, @telefon)";

                                    MySqlCommand^ cmdInsertCasteller = gcnew MySqlCommand(qInsertCasteller, conn, tx);
                                    cmdInsertCasteller->Parameters->AddWithValue("@dni", dniCap);
                                    cmdInsertCasteller->Parameters->AddWithValue("@telefon", telefon);
                                    cmdInsertCasteller->ExecuteNonQuery();
                                }
                                else if (!String::IsNullOrWhiteSpace(telefon)) {
                                    String^ qUpdateTelefon =
                                        "UPDATE casteller "
                                        "SET tel_num = @telefon "
                                        "WHERE dni = @dni "
                                        "AND (tel_num IS NULL OR tel_num = '')";

                                    MySqlCommand^ cmdUpdateTelefon = gcnew MySqlCommand(qUpdateTelefon, conn, tx);
                                    cmdUpdateTelefon->Parameters->AddWithValue("@dni", dniCap);
                                    cmdUpdateTelefon->Parameters->AddWithValue("@telefon", telefon);
                                    cmdUpdateTelefon->ExecuteNonQuery();
                                }

                                String^ qInsertMembre =
                                    "INSERT INTO membre (dni, colla_name, uni_name, join_date) "
                                    "VALUES (@dni, @collaName, @uniName, @joinDate)";

                                MySqlCommand^ cmdInsertMembre = gcnew MySqlCommand(qInsertMembre, conn, tx);
                                cmdInsertMembre->Parameters->AddWithValue("@dni", dniCap);
                                cmdInsertMembre->Parameters->AddWithValue("@collaName", colla->nom);

                                if (String::IsNullOrWhiteSpace(colla->univ)) {
                                    cmdInsertMembre->Parameters->AddWithValue("@uniName", DBNull::Value);
                                }
                                else {
                                    cmdInsertMembre->Parameters->AddWithValue("@uniName", colla->univ);
                                }

                                cmdInsertMembre->Parameters->AddWithValue("@joinDate", DateTime::Now);
                                cmdInsertMembre->ExecuteNonQuery();

                                tx->Commit();
                                correcte = true;
                            }
                        }
                    }
                }
            }
        }
        catch (Exception^ ex) {
            if (tx != nullptr) {
                try { tx->Rollback(); }
                catch (Exception^) {}
            }
            error = "Error creando la colla con cap de colla: " + ex->Message;
            correcte = false;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }

        return correcte;
    }

    bool PasarelaColla::existeixNom(String^ nom) {
        MySqlConnection^ conn = nullptr;
        try {
            conn = DB::GetConnection();
            conn->Open();

            // 🔹 Utilitza 'name' en lloc de 'nom'
            String^ query = "SELECT COUNT(*) FROM colla WHERE name = @name";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@name", nom);

            int count = Convert::ToInt32(cmd->ExecuteScalar());
            return count > 0;
        }
        catch (Exception^ ex) {
            throw gcnew Exception("Error comprovant nom: " + ex->Message);
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
    }

    CollaDTO^ PasarelaColla::obtenirPerId(int id) {
        MySqlConnection^ conn = nullptr;
        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query = "SELECT * FROM colla WHERE id = @id";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@id", id);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
                CollaDTO^ colla = gcnew CollaDTO();
                colla->id = reader->GetInt32("id");
                colla->nom = reader->GetString("name");  // BD->name a DTO->nom

                if (!reader->IsDBNull(reader->GetOrdinal("logo"))) {
                    long bytes = reader->GetBytes(reader->GetOrdinal("logo"), 0, nullptr, 0, 0);
                    cli::array<Byte>^ buffer = gcnew cli::array<Byte>(bytes);
                    reader->GetBytes(reader->GetOrdinal("logo"), 0, buffer, 0, buffer->Length);
                    colla->logo = buffer;
                }

                colla->localitzacio = reader->GetString("location");  // BD->location a DTO->localitzacio

                if (!reader->IsDBNull(reader->GetOrdinal("uni_name"))) {
                    colla->univ = reader->GetString("uni_name");  // BD->uni_name a DTO->univ
                }

                // BD->state (A/I) a DTO->actiu (bool)
                String^ state = reader->GetString("state");
                colla->actiu = (state == "A" || state == "Active");

                return colla;
            }
            return nullptr;
        }
        catch (Exception^) {
            return nullptr;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
    }

    bool PasarelaColla::asignarCapDeColla(String^ nombreColla, String^ dniCap, String^ telefon, String^% error) {
        bool correcte = false;
        error = "";
        MySqlConnection^ conn = nullptr;
        MySqlTransaction^ tx = nullptr;

        try {
            conn = DB::GetConnection();
            conn->Open();
            tx = conn->BeginTransaction();

            // 1) El usuario debe existir, estar activo/no inhabilitado y tener rol CapColla.
            String^ qUsuari =
                "SELECT COUNT(*) "
                "FROM usuari "
                "WHERE dni = @dni "
                "AND user_role = 'CapColla' "
                "AND (state != 'Inactive' OR state IS NULL)";

            MySqlCommand^ cmdUsuari = gcnew MySqlCommand(qUsuari, conn, tx);
            cmdUsuari->Parameters->AddWithValue("@dni", dniCap);

            int existeixUsuari = Convert::ToInt32(cmdUsuari->ExecuteScalar());
            if (existeixUsuari == 0) {
                error = "El usuario seleccionado no existe, está inhabilitado o no tiene rol CapColla.";
                tx->Rollback();
            }
            else {
                // 2) El cap no puede estar asignado a otra colla.
                String^ qCapAltraColla =
                    "SELECT name "
                    "FROM colla "
                    "WHERE cap_de_colla_dni = @dni "
                    "AND name <> @name "
                    "LIMIT 1";

                MySqlCommand^ cmdCapAltraColla = gcnew MySqlCommand(qCapAltraColla, conn, tx);
                cmdCapAltraColla->Parameters->AddWithValue("@dni", dniCap);
                cmdCapAltraColla->Parameters->AddWithValue("@name", nombreColla);

                Object^ altraColla = cmdCapAltraColla->ExecuteScalar();
                if (altraColla != nullptr && altraColla != DBNull::Value) {
                    error = "Este usuario ya es cap de la colla: " + altraColla->ToString();
                    tx->Rollback();
                }
                else {
                    // 3) La colla debe existir y estar activa. Obtenemos su universidad.
                    String^ qColla =
                        "SELECT uni_name "
                        "FROM colla "
                        "WHERE name = @name "
                        "AND state = 'A'";

                    MySqlCommand^ cmdColla = gcnew MySqlCommand(qColla, conn, tx);
                    cmdColla->Parameters->AddWithValue("@name", nombreColla);

                    Object^ uniResult = cmdColla->ExecuteScalar();
                    if (uniResult == nullptr) {
                        error = "La colla seleccionada no existe o está inhabilitada.";
                        tx->Rollback();
                    }
                    else {
                        // 4) El cap no puede pertenecer ya a otra colla como miembro.
                        String^ qMembreAltraColla =
                            "SELECT colla_name "
                            "FROM membre "
                            "WHERE dni = @dni "
                            "AND colla_name <> @name "
                            "LIMIT 1";

                        MySqlCommand^ cmdMembreAltraColla = gcnew MySqlCommand(qMembreAltraColla, conn, tx);
                        cmdMembreAltraColla->Parameters->AddWithValue("@dni", dniCap);
                        cmdMembreAltraColla->Parameters->AddWithValue("@name", nombreColla);

                        Object^ membreAltraColla = cmdMembreAltraColla->ExecuteScalar();
                        if (membreAltraColla != nullptr && membreAltraColla != DBNull::Value) {
                            error = "Este usuario ya pertenece a la colla: " + membreAltraColla->ToString();
                            tx->Rollback();
                        }
                        else {
                            // 5) Para ser miembro, primero debe existir en casteller.
                            String^ qExisteixCasteller = "SELECT COUNT(*) FROM casteller WHERE dni = @dni";
                            MySqlCommand^ cmdExisteixCasteller = gcnew MySqlCommand(qExisteixCasteller, conn, tx);
                            cmdExisteixCasteller->Parameters->AddWithValue("@dni", dniCap);

                            int existeixCasteller = Convert::ToInt32(cmdExisteixCasteller->ExecuteScalar());
                            if (existeixCasteller == 0 && String::IsNullOrWhiteSpace(telefon)) {
                                error = "Este cap de colla todavía no está dado de alta como casteller. Introduce un teléfono.";
                                tx->Rollback();
                            }
                            else {
                                if (existeixCasteller == 0) {
                                    String^ qInsertCasteller =
                                        "INSERT INTO casteller (dni, tel_num) "
                                        "VALUES (@dni, @telefon)";

                                    MySqlCommand^ cmdInsertCasteller = gcnew MySqlCommand(qInsertCasteller, conn, tx);
                                    cmdInsertCasteller->Parameters->AddWithValue("@dni", dniCap);
                                    cmdInsertCasteller->Parameters->AddWithValue("@telefon", telefon);
                                    cmdInsertCasteller->ExecuteNonQuery();
                                }
                                else if (!String::IsNullOrWhiteSpace(telefon)) {
                                    String^ qUpdateTelefon =
                                        "UPDATE casteller "
                                        "SET tel_num = @telefon "
                                        "WHERE dni = @dni "
                                        "AND (tel_num IS NULL OR tel_num = '')";

                                    MySqlCommand^ cmdUpdateTelefon = gcnew MySqlCommand(qUpdateTelefon, conn, tx);
                                    cmdUpdateTelefon->Parameters->AddWithValue("@dni", dniCap);
                                    cmdUpdateTelefon->Parameters->AddWithValue("@telefon", telefon);
                                    cmdUpdateTelefon->ExecuteNonQuery();
                                }

                                // 6) Si todavía no es miembro de esta colla, lo añadimos a membre.
                                String^ qExisteixMembre =
                                    "SELECT COUNT(*) "
                                    "FROM membre "
                                    "WHERE dni = @dni "
                                    "AND colla_name = @name";

                                MySqlCommand^ cmdExisteixMembre = gcnew MySqlCommand(qExisteixMembre, conn, tx);
                                cmdExisteixMembre->Parameters->AddWithValue("@dni", dniCap);
                                cmdExisteixMembre->Parameters->AddWithValue("@name", nombreColla);

                                int existeixMembre = Convert::ToInt32(cmdExisteixMembre->ExecuteScalar());
                                if (existeixMembre == 0) {
                                    String^ qInsertMembre =
                                        "INSERT INTO membre (dni, colla_name, uni_name, join_date) "
                                        "VALUES (@dni, @collaName, @uniName, @joinDate)";

                                    MySqlCommand^ cmdInsertMembre = gcnew MySqlCommand(qInsertMembre, conn, tx);
                                    cmdInsertMembre->Parameters->AddWithValue("@dni", dniCap);
                                    cmdInsertMembre->Parameters->AddWithValue("@collaName", nombreColla);

                                    if (uniResult == DBNull::Value) {
                                        cmdInsertMembre->Parameters->AddWithValue("@uniName", DBNull::Value);
                                    }
                                    else {
                                        cmdInsertMembre->Parameters->AddWithValue("@uniName", uniResult->ToString());
                                    }

                                    cmdInsertMembre->Parameters->AddWithValue("@joinDate", DateTime::Now);
                                    cmdInsertMembre->ExecuteNonQuery();
                                }

                                // 7) Finalmente asignamos el cap a la colla.
                                String^ qUpdateColla =
                                    "UPDATE colla "
                                    "SET cap_de_colla_dni = @dni "
                                    "WHERE name = @name";

                                MySqlCommand^ cmdUpdateColla = gcnew MySqlCommand(qUpdateColla, conn, tx);
                                cmdUpdateColla->Parameters->AddWithValue("@dni", dniCap);
                                cmdUpdateColla->Parameters->AddWithValue("@name", nombreColla);

                                int files = cmdUpdateColla->ExecuteNonQuery();
                                if (files == 0) {
                                    error = "No se ha podido asignar el cap de colla.";
                                    tx->Rollback();
                                }
                                else {
                                    tx->Commit();
                                    correcte = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        catch (Exception^ ex) {
            if (tx != nullptr) {
                try { tx->Rollback(); }
                catch (Exception^) {}
            }
            error = "Error asignando cap de colla: " + ex->Message;
            correcte = false;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }

        return correcte;
    }

    System::Collections::Generic::List<CollaDTO^>^ PasarelaColla::obtenerTodas() {
        System::Collections::Generic::List<CollaDTO^>^ lista = gcnew System::Collections::Generic::List<CollaDTO^>();
        MySqlConnection^ conn = nullptr;
        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query = "SELECT * FROM colla";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                CollaDTO^ colla = gcnew CollaDTO();
                colla->nom = reader->GetString("name");
                lista->Add(colla);
            }
            return lista;
        }
        catch (Exception^ ex) {
            System::Windows::Forms::MessageBox::Show("Error oculto en Collas: " + ex->Message);
            return lista;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) conn->Close();
        }
    }

    bool PasarelaColla::actualitzar(CollaDTO^ colla, String^% error) {
        MySqlConnection^ conn = nullptr;

        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query = "UPDATE colla SET name = @name, location = @location, uni_name = @uni_name WHERE id = @id";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@name", colla->nom);
            cmd->Parameters->AddWithValue("@location", colla->localitzacio);

            if (String::IsNullOrWhiteSpace(colla->univ)) {
                cmd->Parameters->AddWithValue("@uni_name", DBNull::Value);
            }
            else {
                cmd->Parameters->AddWithValue("@uni_name", colla->univ);
            }

            cmd->Parameters->AddWithValue("@id", colla->id);

            cmd->ExecuteNonQuery();

            return true;
        }
        catch (Exception^ ex) {
            error = "Error: " + ex->Message;
            return false;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
    }

}