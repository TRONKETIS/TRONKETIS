#pragma once
#include "DB.h"
using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

public ref class CercadorUsuari
{
public:
    // Para el login (AuthService)
    static bool CercaPerEmail(String^ email, String^% password, String^% rol)
    {
        MySqlConnection^ conn = DB::GetConnection();
        try {
            conn->Open();
            String^ query = "SELECT user_pass, user_role FROM usuari WHERE email_addr = @mail";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@mail", email);
            MySqlDataReader^ reader = cmd->ExecuteReader();
            if (reader->Read()) {
                password = reader["user_pass"]->ToString();
                rol = reader["user_role"]->ToString();
                reader->Close();
                conn->Close();
                return true;
            }
            reader->Close();
            conn->Close();
            return false;
        }
        catch (Exception^ e) {
            System::Windows::Forms::MessageBox::Show("Error: " + e->Message);
            if (conn->State == ConnectionState::Open) conn->Close();
            return false;
        }
    }

    // Para consultar usuari (Form1)
    static bool CercaPerEmail(String^ email, String^% dni, String^% username, String^% password, String^% rol)
    {
        MySqlConnection^ conn = DB::GetConnection();
        try {
            conn->Open();
            String^ query = "SELECT dni, user_name, user_pass, user_role FROM usuari WHERE email_addr = @mail";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@mail", email);
            MySqlDataReader^ reader = cmd->ExecuteReader();
            if (reader->Read()) {
                dni = reader["dni"]->ToString();
                username = reader["user_name"]->ToString();
                password = reader["user_pass"]->ToString();
                rol = reader["user_role"]->ToString();
                reader->Close();
                conn->Close();
                return true;
            }
            reader->Close();
            conn->Close();
            return false;
        }
        catch (Exception^ e) {
            System::Windows::Forms::MessageBox::Show("Error: " + e->Message);
            if (conn->State == ConnectionState::Open) conn->Close();
            return false;
        }
    }

    // Para registrar: comprobar si email ya existe
    static bool existeEmail(String^ email)
    {
        MySqlConnection^ conn = DB::GetConnection();
        try {
            conn->Open();
            String^ query = "SELECT COUNT(*) FROM usuari WHERE email_addr = @mail";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@mail", email);
            int count = Convert::ToInt32(cmd->ExecuteScalar());
            conn->Close();
            return count > 0;
        }
        catch (Exception^ e) {
            System::Windows::Forms::MessageBox::Show("Error: " + e->Message);
            if (conn->State == ConnectionState::Open) conn->Close();
            return false;
        }
    }

    // Para registrar: comprobar si DNI ya existe
    static bool existeDni(String^ dni)
    {
        MySqlConnection^ conn = DB::GetConnection();
        try {
            conn->Open();
            String^ query = "SELECT COUNT(*) FROM usuari WHERE dni = @dni";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@dni", dni);
            int count = Convert::ToInt32(cmd->ExecuteScalar());
            conn->Close();
            return count > 0;
        }
        catch (Exception^ e) {
            System::Windows::Forms::MessageBox::Show("Error: " + e->Message);
            if (conn->State == ConnectionState::Open) conn->Close();
            return false;
        }
    }
};