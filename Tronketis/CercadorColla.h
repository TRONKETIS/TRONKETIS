#pragma once
#include "DB.h"
using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Data;

public ref class CercadorColla
{
public:
    static bool InhabilitarColla(String^ nomColla)
    {
        MySqlConnection^ conn = DB::GetConnection();
        try {
            conn->Open();
            String^ query = "UPDATE colla SET state = 'I' WHERE name = @nom";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@nom", nomColla);
            int files = cmd->ExecuteNonQuery();
            conn->Close();
            return files > 0;
        }
        catch (Exception^ e) {
            System::Windows::Forms::MessageBox::Show("Error: " + e->Message);
            if (conn->State == ConnectionState::Open)
                conn->Close();
            return false;
        }
    }
};