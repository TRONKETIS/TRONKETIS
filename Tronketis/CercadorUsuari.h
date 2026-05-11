#pragma once
#include "DB.h"


using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Collections::Generic;
using namespace Tronketis;

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
        conn->Open();

        String^ query = "SELECT COUNT(*) FROM usuari WHERE dni = @dni";
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@dni", dni);

        int count = Convert::ToInt32(cmd->ExecuteScalar());
        conn->Close();

        return count > 0;
    }
    // 🔥 NUEVO: Buscar usuario completo por DNI
    static UsuariDTO^ buscaPorDNI(String^ dni)
    {
        UsuariDTO^ usuari = nullptr;
        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();
            String^ query = "SELECT dni, user_name, email_addr, user_pass, user_role, state FROM usuari WHERE dni = @dni";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@dni", dni);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
                // Instanciamos el DTO con los datos de la base de datos
                usuari = gcnew UsuariDTO();
                usuari->dni = reader["dni"]->ToString();
                usuari->username = reader["user_name"]->ToString();
                usuari->email = reader["email_addr"]->ToString();
                usuari->password = reader["user_pass"]->ToString();
                usuari->rol = reader["user_role"]->ToString();
              
            }

            reader->Close();
        }
        catch (Exception^ ex) {
            // Opcional: Manejo de errores o logs
            throw ex;
        }
        finally {
            if (conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }

        return usuari; // Retorna el objeto si lo encuentra, o nullptr si no existe
    }
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