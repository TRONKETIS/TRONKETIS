#include "pch.h"

#include "CercadorDiada.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    List<DiadaDTO^>^ CercadorDiada::obtenirTotes()
    {
        List<DiadaDTO^>^ llista =
            gcnew List<DiadaDTO^>();

        MySqlConnection^ conn =
            DB::GetConnection();

        try {

            conn->Open();

            String^ query =
                "SELECT * FROM diada";

            MySqlCommand^ cmd =
                gcnew MySqlCommand(query, conn);

            MySqlDataReader^ reader =
                cmd->ExecuteReader();

            while (reader->Read())
            {
                DiadaDTO^ dto =
                    gcnew DiadaDTO();

                dto->nom =
                    reader["name"]->ToString();

                dto->data =
                    Convert::ToDateTime(
                        reader["date_diada"]
                    );

                dto->ubicacio =
                    reader["location"]->ToString();

                dto->tipus =
                    reader["tipus"]->ToString();

                llista->Add(dto);
            }
        }
        finally {

            if (conn->State == ConnectionState::Open)
            {
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
            String^ query = "SELECT name, date_diada, location, CAST(NULL AS CHAR) as tipus FROM diada "
                            "WHERE MONTH(date_diada) = @month AND YEAR(date_diada) = @year"; // En MySQL diada parece no tener tipus en el CREATE pero lo pusisteis asi en obtenirTotes

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

                // Mantenemos la logica anterior por si 'tipus' no viene
                try {
                    dto->tipus = reader["tipus"] != DBNull::Value ? reader["tipus"]->ToString() : "";
                } catch(...) { dto->tipus = ""; }

                llista->Add(dto);
            }
        }
        catch (Exception^) {}
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
        return llista;
    }

}
