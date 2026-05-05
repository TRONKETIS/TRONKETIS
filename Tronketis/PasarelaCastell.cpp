#include "pch.h"
#include "PasarelaCastell.h"
#include "DB.h"
using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

namespace Tronketis {

    bool PasarelaCastell::insertar(CastellDTO^ castell, String^% error) {
        MySqlConnection^ conn = nullptr;
        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query = "INSERT INTO castell (nom, tipus, num_pisos) "
                "VALUES (@nom, @tipus, @num_pisos)";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@nom", castell->nom);
            cmd->Parameters->AddWithValue("@tipus", castell->tipus);
            cmd->Parameters->AddWithValue("@num_pisos", castell->numPisos);

            cmd->ExecuteNonQuery();

            cmd = gcnew MySqlCommand("SELECT LAST_INSERT_ID()", conn);
            castell->id = Convert::ToInt32(cmd->ExecuteScalar());

            return true;
        }
        catch (Exception^ ex) {
            error = "Error: " + ex->Message;
            return false;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
    }

    bool PasarelaCastell::existeixNom(String^ nom) {
        MySqlConnection^ conn = nullptr;
        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query = "SELECT COUNT(*) FROM castell WHERE nom = @nom";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@nom", nom);

            int count = Convert::ToInt32(cmd->ExecuteScalar());
            return count > 0;
        }
        catch (Exception^ ex) {
            throw gcnew Exception("Error comprovant nom: " + ex->Message);
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
    }

    List<CastellDTO^>^ PasarelaCastell::obtenirTots() {
        MySqlConnection^ conn = nullptr;
        List<CastellDTO^>^ castells = gcnew List<CastellDTO^>();
        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query = "SELECT id, nom, tipus, num_pisos FROM castell ORDER BY tipus, num_pisos";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            MySqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read()) {
                CastellDTO^ c = gcnew CastellDTO();
                c->id       = reader->GetInt32("id");
                c->nom      = reader->GetString("nom");
                c->tipus    = reader->GetString("tipus");
                c->numPisos = reader->GetInt32("num_pisos");
                castells->Add(c);
            }
            return castells;
        }
        catch (Exception^) {
            return castells;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
    }

}
