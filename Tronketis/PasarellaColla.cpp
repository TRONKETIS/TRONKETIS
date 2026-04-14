#include "pch.h"
#include "PasarelaColla.h"
#include "DB.h"
using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

namespace Tronketis {

    
    bool PasarelaColla::insertar(CollaDTO^ colla, String^% error) {
        MySqlConnection^ conn = nullptr;

        try {
            conn = DB::GetConnection();
            conn->Open();

            // Inserció simple sense transacció complexa
            String^ query = "INSERT INTO colla (name, location, uni_name, state) " +
                "VALUES (@name, @location, @uni_name, @state)";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@name", colla->nom);
            cmd->Parameters->AddWithValue("@location", colla->localitzacio);

            if (String::IsNullOrWhiteSpace(colla->univ)) {
                cmd->Parameters->AddWithValue("@uni_name", DBNull::Value);
            }
            else {
                cmd->Parameters->AddWithValue("@uni_name", colla->univ);
            }

            cmd->Parameters->AddWithValue("@state", "A");

            cmd->ExecuteNonQuery();

            // Obtenir l'ID
            cmd = gcnew MySqlCommand("SELECT LAST_INSERT_ID()", conn);
            colla->id = Convert::ToInt32(cmd->ExecuteScalar());

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

    bool PasarelaColla::existeixNom(String^ nom) {
        MySqlConnection^ conn = nullptr;
        try {
            conn = DB::GetConnection();
            conn->Open();

            // 🔹 Utilitza 'name' en lloc de 'nom'
            String^ query = "SELECT COUNT(*) FROM colla WHERE name = @name";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@name", nom);

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

    CollaDTO^ PasarelaColla::obtenirPerId(int id) {
        MySqlConnection^ conn = nullptr;
        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query = "SELECT * FROM colla WHERE id = @id";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@id", id);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
                CollaDTO^ colla = gcnew CollaDTO();
                colla->id = reader->GetInt32("id");
                colla->nom = reader->GetString("name");  // BD->name a DTO->nom

                if (!reader->IsDBNull(reader->GetOrdinal("logo"))) {
                    long bytes = reader->GetBytes(reader->GetOrdinal("logo"), 0, nullptr, 0, 0);
                    cli::array<Byte>^ buffer = gcnew cli::array<Byte>(bytes);
                    reader->GetBytes(reader->GetOrdinal("logo"), 0, buffer, 0, buffer->Length);
                    colla->logo = buffer;
                }

                colla->localitzacio = reader->GetString("location");  // BD->location a DTO->localitzacio

                if (!reader->IsDBNull(reader->GetOrdinal("uni_name"))) {
                    colla->univ = reader->GetString("uni_name");  // BD->uni_name a DTO->univ
                }

                // BD->state (A/I) a DTO->actiu (bool)
                String^ state = reader->GetString("state");
                colla->actiu = (state == "A" || state == "Active");

                return colla;
            }
            return nullptr;
        }
        catch (Exception^) {
            return nullptr;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
    }

}