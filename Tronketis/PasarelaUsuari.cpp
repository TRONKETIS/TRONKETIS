#include "pch.h"
#include "PasarelaUsuari.h"
using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

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

String^ PasarelaUsuari::obtenirRolUsuari(int usuariId)
{
    MySqlConnection^ conn = DB::GetConnection();
    try {
        conn->Open();

        String^ query = "SELECT user_role FROM usuari WHERE id = @id AND state = 'Active'";
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", usuariId);

        Object^ result = cmd->ExecuteScalar();

        return result != nullptr ? result->ToString() : nullptr;
    }
    catch (Exception^) {
        return nullptr;
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }
}

bool PasarelaUsuari::esAdministrador(int usuariId)
{
    String^ rol = obtenirRolUsuari(usuariId);
    return rol != nullptr && rol->ToLower() == "admin";
}