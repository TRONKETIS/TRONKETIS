#include "pch.h"
#include "PasarelaMuntatgeCastell.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

namespace Tronketis {

    List<CastellDTO^>^ PasarelaMuntatgeCastell::obtenirCastellsPerColla(String^ collaName)
    {
        List<CastellDTO^>^ llista = gcnew List<CastellDTO^>();
        MySqlConnection^ conn = nullptr;

        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query =
                "SELECT id, nom, num_pisos, tipus "
                "FROM castell "
                "WHERE colla = @colla "
                "ORDER BY nom";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@colla", collaName);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                CastellDTO^ dto = gcnew CastellDTO();
                dto->idCastell = Convert::ToInt32(reader["id"]);
                dto->nom = reader["nom"]->ToString();
                dto->pisos = Convert::ToInt32(reader["num_pisos"]);
                dto->tipus = reader["tipus"]->ToString();
                llista->Add(dto);
            }
        }
        catch (Exception^) {
            // Retornem llista buida. El formulari ja mostra el missatge.
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }

        return llista;
    }

    List<CastellerDTO^>^ PasarelaMuntatgeCastell::obtenirCastellersPerColla(String^ collaName)
    {
        List<CastellerDTO^>^ llista = gcnew List<CastellerDTO^>();
        MySqlConnection^ conn = nullptr;

        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query =
                "SELECT c.dni, u.user_name "
                "FROM casteller c "
                "JOIN usuari u ON c.dni = u.dni "
                "JOIN membre m ON c.dni = m.dni "
                "WHERE m.colla_name = @colla "
                "ORDER BY u.user_name";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@colla", collaName);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                CastellerDTO^ dto = gcnew CastellerDTO();
                dto->dniCasteller = reader["dni"]->ToString();
                dto->nomUsuari = reader["user_name"]->ToString();
                llista->Add(dto);
            }
        }
        catch (Exception^) {
            // Retornem llista buida. El formulari ja mostra el missatge.
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }

        return llista;
    }

    List<PosicioCastellDTO^>^ PasarelaMuntatgeCastell::obtenirAssignacions(int castellId, String^ collaName)
    {
        List<PosicioCastellDTO^>^ llista = gcnew List<PosicioCastellDTO^>();
        MySqlConnection^ conn = nullptr;

        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query =
                "SELECT pc.num_pis, pc.num_posicio, pc.casteller_dni, u.user_name "
                "FROM posicio_castell pc "
                "JOIN usuari u ON pc.casteller_dni = u.dni "
                "WHERE pc.castell_id = @castell_id AND pc.colla_name = @colla";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@castell_id", castellId);
            cmd->Parameters->AddWithValue("@colla", collaName);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                PosicioCastellDTO^ dto = gcnew PosicioCastellDTO();
                dto->numPis = Convert::ToInt32(reader["num_pis"]);
                dto->numPosicio = Convert::ToInt32(reader["num_posicio"]);
                dto->castellerDni = reader["casteller_dni"]->ToString();
                dto->castellerNom = reader["user_name"]->ToString();
                llista->Add(dto);
            }
        }
        catch (Exception^) {
            // Si la taula no existeix o no hi ha dades, retornem buit.
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }

        return llista;
    }

    bool PasarelaMuntatgeCastell::guardarAssignacions(
        int castellId,
        String^ collaName,
        List<PosicioCastellDTO^>^ posicions,
        String^% error
    )
    {
        MySqlConnection^ conn = nullptr;
        MySqlTransaction^ tx = nullptr;

        try {
            conn = DB::GetConnection();
            conn->Open();
            tx = conn->BeginTransaction();

            MySqlCommand^ cmdCheck = gcnew MySqlCommand(
                "SELECT COUNT(*) FROM castell WHERE id = @castell_id AND colla = @colla",
                conn,
                tx
            );
            cmdCheck->Parameters->AddWithValue("@castell_id", castellId);
            cmdCheck->Parameters->AddWithValue("@colla", collaName);

            int existeix = Convert::ToInt32(cmdCheck->ExecuteScalar());
            if (existeix == 0) {
                error = "Aquest castell no pertany a la teva colla.";
                tx->Rollback();
                return false;
            }

            MySqlCommand^ cmdDelete = gcnew MySqlCommand(
                "DELETE FROM posicio_castell WHERE castell_id = @castell_id AND colla_name = @colla",
                conn,
                tx
            );
            cmdDelete->Parameters->AddWithValue("@castell_id", castellId);
            cmdDelete->Parameters->AddWithValue("@colla", collaName);
            cmdDelete->ExecuteNonQuery();

            for each (PosicioCastellDTO ^ p in posicions) {
                if (String::IsNullOrEmpty(p->castellerDni)) {
                    continue;
                }

                MySqlCommand^ cmdCheckMembre = gcnew MySqlCommand(
                    "SELECT COUNT(*) "
                    "FROM membre "
                    "WHERE dni = @dni AND colla_name = @colla",
                    conn,
                    tx
                );
                cmdCheckMembre->Parameters->AddWithValue("@dni", p->castellerDni);
                cmdCheckMembre->Parameters->AddWithValue("@colla", collaName);

                int membreCorrecte = Convert::ToInt32(cmdCheckMembre->ExecuteScalar());
                if (membreCorrecte == 0) {
                    error = "Hi ha un casteller que no pertany a aquesta colla.";
                    tx->Rollback();
                    return false;
                }

                MySqlCommand^ cmdInsert = gcnew MySqlCommand(
                    "INSERT INTO posicio_castell "
                    "(castell_id, colla_name, num_pis, num_posicio, casteller_dni) "
                    "VALUES (@castell_id, @colla, @num_pis, @num_posicio, @dni)",
                    conn,
                    tx
                );
                cmdInsert->Parameters->AddWithValue("@castell_id", castellId);
                cmdInsert->Parameters->AddWithValue("@colla", collaName);
                cmdInsert->Parameters->AddWithValue("@num_pis", p->numPis);
                cmdInsert->Parameters->AddWithValue("@num_posicio", p->numPosicio);
                cmdInsert->Parameters->AddWithValue("@dni", p->castellerDni);
                cmdInsert->ExecuteNonQuery();
            }

            tx->Commit();
            return true;
        }
        catch (Exception^ ex) {
            if (tx != nullptr) {
                try { tx->Rollback(); }
                catch (Exception^) {}
            }

            error = "Error guardant assignacions: " + ex->Message;
            return false;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
    }
}
