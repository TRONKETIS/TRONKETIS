#pragma once

#include "DB.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

public ref class CercadorUsuari
{
public:
    static bool CercaPerEmail(String^ email, String^% password, String^% rol)
    {
        MySqlConnection^ conn = DB::GetConnection();
        try{
            conn->Open();
        }
        catch (Exception^ e){
            return false;
        }

        String^ query = "SELECT user_pass, user_role FROM usuari WHERE email_addr = @email";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@email", email);

        MySqlDataReader^ reader = cmd->ExecuteReader();

        if (!reader->Read())
        {
            conn->Close();
            return false;
        }

        password = reader["user_pass"]->ToString();
        rol = reader["user_role"]->ToString();

        conn->Close();
        return true;
    }
};