#pragma once

#include "DB.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

public ref class CercadorUsuari
{
public:

    // 🔹 YA EXISTENTE (login)
    static bool CercaPerEmail(String^ email, String^% password, String^% rol)
    {
        MySqlConnection^ conn = DB::GetConnection();
        try {
            conn->Open();
        }
        catch (Exception^) {
            return false;
        }

        String^ query = "SELECT user_pass, user_role FROM usuari WHERE email_addr = @email";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@email", email);

        MySqlDataReader^ reader = cmd->ExecuteReader();

        if (!reader->Read()) {
            conn->Close();
            return false;
        }

        password = reader["user_pass"]->ToString();
        rol = reader["user_role"]->ToString();

        conn->Close();
        return true;
    }

    // 🔥 NUEVO: comprobar si email ya existe
    static bool existeEmail(String^ email)
    {
        MySqlConnection^ conn = DB::GetConnection();
        conn->Open();

        String^ query = "SELECT COUNT(*) FROM usuari WHERE email_addr = @email";
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@email", email);

        int count = Convert::ToInt32(cmd->ExecuteScalar());
        conn->Close();

        return count > 0;
    }

    // 🔥 NUEVO: comprobar si DNI ya existe
    static bool existeDni(String^ dni)
    {
        MySqlConnection^ conn = DB::GetConnection();
        conn->Open();

        String^ query = "SELECT COUNT(*) FROM usuari WHERE dni = @dni";
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@dni", dni);

        int count = Convert::ToInt32(cmd->ExecuteScalar());
        conn->Close();

        return count > 0;
    }
};