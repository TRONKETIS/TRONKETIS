#pragma once

#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

public ref class CercadorUsuari
{
public:
    static bool CercaPerUsername(String^ username, String^% dni, String^% password, String^% rol)
    {
        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();

            String^ query = "SELECT dni, user_pass, user_role FROM usuari WHERE user_name = @user";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@user", username);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
                dni = reader["dni"]->ToString();
                password = reader["user_pass"]->ToString();
                rol = reader["user_role"]->ToString();

                reader->Close();
                conn->Close();
                return true;
            }
            else {
                reader->Close();
                conn->Close();
                return false;
            }
        }
        catch (Exception^ e) {
            System::Windows::Forms::MessageBox::Show("Error: " + e->Message);

            if (conn->State == ConnectionState::Open)
                conn->Close();

            return false;
        }
    }
};
