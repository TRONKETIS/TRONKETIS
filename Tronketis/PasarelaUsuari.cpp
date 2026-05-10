#include "pch.h"
#include "PasarelaUsuari.h"
using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;
using namespace System;
void PasarelaUsuari::insertar(UsuariDTO^ u)
{
    MySqlConnection^ conn = DB::GetConnection();
    try {
        conn->Open();

        String^ query = "INSERT INTO usuari (dni, user_name, email_addr, user_pass, user_role) "
            "VALUES (@dni, @username, @email, @password, @rol)";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

        cmd->Parameters->AddWithValue("@dni", u->dni);
        cmd->Parameters->AddWithValue("@username", u->username);
        cmd->Parameters->AddWithValue("@email", u->email);
        cmd->Parameters->AddWithValue("@password", u->password);
        cmd->Parameters->AddWithValue("@rol", u->rol);

        cmd->ExecuteNonQuery();
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }
}

/*String^ PasarelaUsuari::obtenirRolUsuari(int usuariId)
{
    MySqlConnection^ conn = DB::GetConnection();
    try {
        conn->Open();

    cmd->ExecuteNonQuery();
    conn->Close();
}*/


bool PasarelaUsuari::Inhabilitar(String^ dni)
{
    MySqlConnection^ conn = DB::GetConnection();

    try {
        conn->Open();

        String^ query = "UPDATE usuari SET state = 'Inactive' WHERE dni = @dni";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@dni", dni);

        int rows = cmd->ExecuteNonQuery();

        conn->Close();

        return rows > 0;
    }
    catch (Exception^) {
        return false;
    }
}

System::Collections::Generic::List<UsuariDTO^>^ PasarelaUsuari::obtenirTots() {
    System::Collections::Generic::List<UsuariDTO^>^ lista = gcnew System::Collections::Generic::List<UsuariDTO^>();
    MySqlConnection^ conn = nullptr;
    try {
        conn = DB::GetConnection();
        conn->Open();

        // 🔹 Solo traemos a los usuarios que NO estén inhabilitados
        String^ query = "SELECT * FROM usuari WHERE(state != 'Inactive' OR state IS NULL) AND user_role = 'CapColla'";
       
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            UsuariDTO^ usuari = gcnew UsuariDTO();
            usuari->dni = reader->GetString("dni");

            // 🔹 Usamos user_name y username que coinciden con tu DTO y BD
            usuari->username = reader->GetString("user_name");

            lista->Add(usuari);
        }
        return lista;
    }
    catch (Exception^) {
        return lista;
    }
    finally {
        if (conn != nullptr && conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }
}


