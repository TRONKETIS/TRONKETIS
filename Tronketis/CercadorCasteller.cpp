#include "pch.h"

#include "CercadorCasteller.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    List<CastellerDTO^>^
        CercadorCasteller::obtenirTots()
    {
        List<CastellerDTO^>^ llista =
            gcnew List<CastellerDTO^>();

        MySqlConnection^ conn =
            DB::GetConnection();

        try {

            conn->Open();

            String^ query =
                "SELECT c.dni, u.user_name "
                "FROM casteller c "
                "JOIN usuari u "
                "ON c.dni = u.dni";

            MySqlCommand^ cmd =
                gcnew MySqlCommand(query, conn);

            MySqlDataReader^ reader =
                cmd->ExecuteReader();

            while (reader->Read())
            {
                CastellerDTO^ dto =
                    gcnew CastellerDTO();

                dto->dniCasteller =
                    reader["dni"]->ToString();

                dto->nomUsuari =
                    reader["user_name"]->ToString();

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

}
