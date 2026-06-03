#include "pch.h"
#include "CercadorDiada.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    List<DiadaDTO^>^ CercadorDiada::obtenirTotes()
    {
        List<DiadaDTO^>^ llista = gcnew List<DiadaDTO^>();
        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();

            String^ query =
                "SELECT name, date_diada, location, descrip "
                "FROM diada "
                "ORDER BY date_diada";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read())
            {
                DiadaDTO^ dto = gcnew DiadaDTO();

                dto->nom = reader["name"]->ToString();
                dto->data = Convert::ToDateTime(reader["date_diada"]);
                dto->ubicacio = reader["location"] != DBNull::Value ? reader["location"]->ToString() : "";
                dto->descripcio = reader["descrip"] != DBNull::Value ? reader["descrip"]->ToString() : "";

                llista->Add(dto);
            }
        }
        finally {
            if (conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }

        return llista;
    }

    List<DiadaDTO^>^ CercadorDiada::obtenirDiadesPerMes(int month, int year)
    {
        List<DiadaDTO^>^ llista = gcnew List<DiadaDTO^>();
        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();

            String^ query =
                "SELECT name, date_diada, location, descrip "
                "FROM diada "
                "WHERE MONTH(date_diada) = @month AND YEAR(date_diada) = @year "
                "ORDER BY date_diada";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@month", month);
            cmd->Parameters->AddWithValue("@year", year);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read())
            {
                DiadaDTO^ dto = gcnew DiadaDTO();

                dto->nom = reader["name"]->ToString();
                dto->data = Convert::ToDateTime(reader["date_diada"]);
                dto->ubicacio = reader["location"] != DBNull::Value ? reader["location"]->ToString() : "";
                dto->descripcio = reader["descrip"] != DBNull::Value ? reader["descrip"]->ToString() : "";

                llista->Add(dto);
            }
        }
        finally {
            if (conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }

        return llista;
    }

    List<DiadaDTO^>^ CercadorDiada::obtenirDiadesDisponibles()
    {
        List<DiadaDTO^>^ llista = gcnew List<DiadaDTO^>();
        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();

            String^ query =
                "SELECT name, date_diada, location, descrip "
                "FROM diada "
                "WHERE date_diada >= NOW() "
                "ORDER BY date_diada";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read())
            {
                DiadaDTO^ dto = gcnew DiadaDTO();

                dto->nom = reader["name"]->ToString();
                dto->data = Convert::ToDateTime(reader["date_diada"]);
                dto->ubicacio = reader["location"] != DBNull::Value ? reader["location"]->ToString() : "";
                dto->descripcio = reader["descrip"] != DBNull::Value ? reader["descrip"]->ToString() : "";

                llista->Add(dto);
            }
        }
        finally {
            if (conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }

        return llista;
    }

}