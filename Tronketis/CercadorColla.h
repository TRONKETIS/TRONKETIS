#pragma once

#include "DB.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Data;
using namespace System::Collections::Generic;

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


    static List<String^>^ obtenirNomsColles()
    {
        List<String^>^ colles = gcnew List<String^>();
        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();

            String^ query = "SELECT name FROM colla WHERE state = 'A' ORDER BY name";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                colles->Add(reader["name"]->ToString());
            }
        }
        catch (Exception^) {
        }
        finally {
            conn->Close();
        }

        return colles;
    }

    static bool obtenirUniPerNomColla(String^ collaName, String^% uniName)
    {
        bool trobada = false;
        uniName = "";

        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();

            String^ query = "SELECT uni_name FROM colla WHERE name = @name";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@name", collaName);

            Object^ resultat = cmd->ExecuteScalar();

            if (resultat != nullptr && resultat != DBNull::Value) {
                uniName = resultat->ToString();
                trobada = true;
            }
        }
        catch (Exception^) {
            trobada = false;
        }
        finally {
            conn->Close();
        }

        return trobada;
    }

    static bool obtenirCollaPerCap(String^ dniCap, String^% collaName)
    {
        bool trobada = false;
        collaName = "";

        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();

            String^ query = "SELECT name FROM colla WHERE cap_de_colla_dni = @dniCap";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@dniCap", dniCap);

            Object^ resultat = cmd->ExecuteScalar();

            if (resultat != nullptr && resultat != DBNull::Value) {
                collaName = resultat->ToString();
                trobada = true;
            }
        }
        catch (Exception^) {
            trobada = false;
        }
        finally {
            conn->Close();
        }

        return trobada;
    }



};