#pragma once

#include "DB.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

public ref class CercadorUsuari
{
public:

    // 🔹 YA EXISTENTE (login)
    static bool CercaPerEmail(String^ email, String^% dni, String^% password, String^% rol)
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

    // comprobar si email ya existe
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

    // comprobar si DNI ya existe
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

    // obtenir dnis castellers actius
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
            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                dnis->Add(reader["dni"]->ToString());
            }
        }
        catch (Exception^) {
            conn->Close();
		}
    
        return dnis;
	}
};