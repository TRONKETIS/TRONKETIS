#pragma once
#include "DB.h"
#include "UsuariDTO.h"

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

    // 🔥 NUEVO: Buscar usuario completo por DNI
    static UsuariDTO^ buscaPorDNI(String^ dni)
    {
        UsuariDTO^ usuari = nullptr;
        MySqlConnection^ conn = DB::GetConnection();
        try {
            conn->Open();
            String^ query = "SELECT dni, user_name, email_addr, user_pass, user_role FROM usuari WHERE dni = @dni";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@dni", dni);
            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
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
            System::Windows::Forms::MessageBox::Show("Error en buscaPorDNI: " + ex->Message);
        }
        finally {
            if (conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
        return usuari;
    }
    // Añade esto a la clase CercadorUsuari
    static List<String^>^ obtenerTodosLosDnis() {
        List<String^>^ lista = gcnew List<String^>();
        MySqlConnection^ conn = DB::GetConnection();
        try {
            conn->Open();
            String^ query = "SELECT dni FROM usuari WHERE state = 'Active'"; // Solo usuarios activos
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                lista->Add(reader["dni"]->ToString());
            }
            reader->Close();
        }
        catch (Exception^ ex) {
            System::Windows::Forms::MessageBox::Show("Error al listar DNIs: " + ex->Message);
        }
        finally {
            if (conn->State == ConnectionState::Open) conn->Close();
        }
        return lista;
    }

    static bool CercaPerEmailAmbDni(String^ email, String^% dni, String^% password, String^% rol)
    {
        MySqlConnection^ conn = DB::GetConnection();
        try {
            conn->Open();
        }
        catch (Exception^) {
            return false;
        }

        String^ query = "SELECT dni, user_pass, user_role "
            "FROM usuari "
            "WHERE email_addr = @email AND state = 'Active'";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@email", email);

        MySqlDataReader^ reader = cmd->ExecuteReader();

        if (!reader->Read()) {
            conn->Close();
            return false;
        }

        dni = reader["dni"]->ToString();
        password = reader["user_pass"]->ToString();
        rol = reader["user_role"]->ToString();

        conn->Close();
        return true;
    }

    static Collections::Generic::List<String^>^ obtenirDnisCastellersActius()
    {
        Collections::Generic::List<String^>^ dnis = gcnew Collections::Generic::List<String^>();
        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();

            String^ query =
                "SELECT u.dni "
                "FROM usuari u "
                "INNER JOIN casteller c ON u.dni = c.dni "
                "LEFT JOIN membre m ON u.dni = m.dni "
                "WHERE u.user_role = 'Casteller' "
                "AND u.state = 'Active' "
                "AND m.dni IS NULL "
                "ORDER BY u.dni";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            MySqlCommand^% dummy = cmd; 
            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                dnis->Add(reader["dni"]->ToString());
            }
        }
        catch (Exception^) {
        }
        finally {
            conn->Close();
        }

        return dnis;
    }
};