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
        if (conn->State == ConnectionState::Open) conn->Close();
    }
}

bool PasarelaUsuari::modificarUsuari(UsuariDTO^ u)
{
    MySqlConnection^ conn = DB::GetConnection();
    try {
        conn->Open();
        // SQL para actualizar los datos basados en el DNI (que no cambia)
        String^ query = "UPDATE usuari SET "
            "user_name = @username, "
            "email_addr = @email, "
            "user_pass = @password, "
            "user_role = @rol "
            "WHERE dni = @dni";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@username", u->username);
        cmd->Parameters->AddWithValue("@email", u->email);
        cmd->Parameters->AddWithValue("@password", u->password);
        cmd->Parameters->AddWithValue("@rol", u->rol);
        cmd->Parameters->AddWithValue("@dni", u->dni);

        int rows = cmd->ExecuteNonQuery();
        return rows == 1; // Retorna true si se modificó exactamente una fila
    }
    catch (Exception^ ex) {
        System::Windows::Forms::MessageBox::Show("Error al modificar: " + ex->Message);
        return false;
    }
    finally {
        if (conn->State == ConnectionState::Open) conn->Close();
    }
}

bool PasarelaUsuari::Inhabilitar(String^ dni)
{
    MySqlConnection^ conn = DB::GetConnection();
    try {
        conn->Open();
        String^ query = "UPDATE usuari SET state = 'Inactive' WHERE dni = @dni";
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@dni", dni);

        int rows = cmd->ExecuteNonQuery();
        return rows > 0;
    }
    catch (Exception^) {
        return false;
    }
    finally {
        if (conn->State == ConnectionState::Open) conn->Close();
    }
}