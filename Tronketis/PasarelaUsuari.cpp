#include "pch.h"
#include "PasarelaUsuari.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

/*
 * Insereix un nou usuari a la base de dades.
 * Rep un UsuariDTO amb totes les dades necessàries per crear el registre.
 */
void PasarelaUsuari::insertar(UsuariDTO^ u)
{
    // Obtenim una connexió a la base de dades.
    MySqlConnection^ conn = DB::GetConnection();

    try {
        // Obrim la connexió abans d'executar l'INSERT.
        conn->Open();

        // Consulta SQL per inserir un nou usuari.
        // S'utilitzen paràmetres per evitar concatenar valors directament.
        String^ query = "INSERT INTO usuari (dni, user_name, email_addr, user_pass, user_role) "
            "VALUES (@dni, @username, @email, @password, @rol)";

        // Creem la comanda SQL associada a la connexió oberta.
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

        // Assignem cada valor del DTO al seu paràmetre corresponent.
        cmd->Parameters->AddWithValue("@dni", u->dni);
        cmd->Parameters->AddWithValue("@username", u->username);
        cmd->Parameters->AddWithValue("@email", u->email);
        cmd->Parameters->AddWithValue("@password", u->password);
        cmd->Parameters->AddWithValue("@rol", u->rol);

        // Executem la consulta. ExecuteNonQuery s'utilitza per INSERT, UPDATE i DELETE.
        cmd->ExecuteNonQuery();
    }
    finally {
        // Tanquem la connexió si continua oberta.
        if (conn->State == ConnectionState::Open) conn->Close();
    }
}

/*
 * Modifica les dades d'un usuari existent.
 * El DNI s'utilitza com a identificador i no es modifica.
 */
bool PasarelaUsuari::modificarUsuari(UsuariDTO^ u)
{
    // Obtenim la connexió amb la base de dades.
    MySqlConnection^ conn = DB::GetConnection();

    try {
        // Obrim la connexió.
        conn->Open();

        // Consulta SQL per actualitzar les dades de l'usuari.
        // El WHERE dni = @dni assegura que només es modifica l'usuari indicat.
        String^ query = "UPDATE usuari SET "
            "user_name = @username, "
            "email_addr = @email, "
            "user_pass = @password, "
            "user_role = @rol "
            "WHERE dni = @dni";

        // Creem la comanda SQL.
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

        // Assignem els nous valors de l'usuari.
        cmd->Parameters->AddWithValue("@username", u->username);
        cmd->Parameters->AddWithValue("@email", u->email);
        cmd->Parameters->AddWithValue("@password", u->password);
        cmd->Parameters->AddWithValue("@rol", u->rol);

        // Assignem el DNI per identificar quin usuari s'ha de modificar.
        cmd->Parameters->AddWithValue("@dni", u->dni);

        // ExecuteNonQuery retorna el nombre de files modificades.
        int rows = cmd->ExecuteNonQuery();

        // Retornem true només si s'ha modificat exactament una fila.
        return rows == 1;
    }
    catch (Exception^ ex) {
        // Mostrem un missatge amb l'error produït durant la modificació.
        System::Windows::Forms::MessageBox::Show("Error al modificar: " + ex->Message);

        // Retornem false perquè l'operació ha fallat.
        return false;
    }
    finally {
        // Tanquem la connexió si continua oberta.
        if (conn->State == ConnectionState::Open) conn->Close();
    }
}

/*
 * Inhabilita un usuari canviant el seu estat a 'Inactive'.
 * No elimina l'usuari físicament de la base de dades.
 */
bool PasarelaUsuari::Inhabilitar(String^ dni)
{
    // Obtenim la connexió amb la base de dades.
    MySqlConnection^ conn = DB::GetConnection();

    try {
        // Obrim la connexió.
        conn->Open();

        // Consulta SQL per marcar l'usuari com a inactiu.
        String^ query = "UPDATE usuari SET state = 'Inactive' WHERE dni = @dni";

        // Creem la comanda SQL.
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

        // Assignem el DNI de l'usuari que volem inhabilitar.
        cmd->Parameters->AddWithValue("@dni", dni);

        // ExecuteNonQuery retorna quantes files han estat afectades.
        int rows = cmd->ExecuteNonQuery();

        // Si s'ha modificat almenys una fila, la inhabilitació ha funcionat.
        return rows > 0;
    }
    catch (Exception^) {
        // Si hi ha qualsevol error, retornem false.
        return false;
    }
}

/*
 * Obté tots els usuaris actius amb rol CapColla.
 * Aquesta funció s'utilitza, per exemple, per assignar caps de colla.
 */
System::Collections::Generic::List<UsuariDTO^>^ PasarelaUsuari::obtenirTots() {

    // Creem la llista que retornarem amb els usuaris trobats.
    System::Collections::Generic::List<UsuariDTO^>^ lista =
        gcnew System::Collections::Generic::List<UsuariDTO^>();

    // Inicialitzem la connexió a nullptr per controlar-la al finally.
    MySqlConnection^ conn = nullptr;

    try {
        // Obtenim i obrim la connexió amb la base de dades.
        conn = DB::GetConnection();
        conn->Open();

        // Consulta que només retorna usuaris actius o sense estat definit.
        // També filtra perquè només apareguin els usuaris amb rol CapColla.
        String^ query = "SELECT * FROM usuari WHERE(state != 'Inactive' OR state IS NULL) AND user_role = 'CapColla'";

        // Creem la comanda SQL.
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

        // ExecuteReader permet llegir múltiples files retornades per la consulta.
        MySqlDataReader^ reader = cmd->ExecuteReader();

        // Recorrem totes les files retornades.
        while (reader->Read()) {
            // Creem un DTO per cada usuari trobat.
            UsuariDTO^ usuari = gcnew UsuariDTO();

            // Assignem el DNI de la fila actual.
            usuari->dni = reader->GetString("dni");

            // Assignem el nom d'usuari.
            usuari->username = reader->GetString("user_name");

            // Afegim l'usuari a la llista de resultats.
            lista->Add(usuari);
        }

        // Retornem la llista d'usuaris trobats.
        return lista;
    }
    catch (Exception^) {
        // En cas d'error, retornem la llista tal com estigui.
        // Pot estar buida si no s'ha pogut carregar cap usuari.
        return lista;
    }
    finally {
        // Tanquem la connexió si s'ha creat i encara està oberta.
        if (conn != nullptr && conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }
}