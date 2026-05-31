#include "pch.h"
#include "PasarelaParticipacioDiada.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    bool PasarelaParticipacioDiada::existeix(
        String^ diadaName,
        DateTime dateDiada,
        String^ dni
    )
    {
        MySqlConnection^ conn = DB::GetConnection();

        try {

            conn->Open();

            String^ query =
                "SELECT COUNT(*) "
                "FROM participacio_diada "
                "WHERE diada_name = @name "
                "AND date_diada = @date "
                "AND dni = @dni";

            MySqlCommand^ cmd =
                gcnew MySqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@name", diadaName);
            cmd->Parameters->AddWithValue("@date", dateDiada);
            cmd->Parameters->AddWithValue("@dni", dni);

            int count =
                Convert::ToInt32(cmd->ExecuteScalar());

            return count > 0;
        }
        finally {

            if (conn->State == ConnectionState::Open)
            {
                conn->Close();
            }
        }
    }

    bool PasarelaParticipacioDiada::registrar(
        ParticipacioDiadaDTO^ dto,
        String^% error
    )
    {
        MySqlConnection^ conn = DB::GetConnection();

        try {

            conn->Open();

            String^ query =
                "INSERT INTO participacio_diada "
                "(diada_name, date_diada, dni, state) "
                "VALUES "
                "(@name, @date, @dni, @state)";

            MySqlCommand^ cmd =
                gcnew MySqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@name", dto->diadaName);
            cmd->Parameters->AddWithValue("@date", dto->dateDiada);
            cmd->Parameters->AddWithValue("@dni", dto->dni);
            cmd->Parameters->AddWithValue("@state", dto->estat);

            cmd->ExecuteNonQuery();

            return true;
        }
        catch (Exception^ ex) {

            error = ex->Message;
            return false;
        }
        finally {

            if (conn->State == ConnectionState::Open)
            {
                conn->Close();
            }
        }
    }

    bool PasarelaParticipacioDiada::actualitzarEstat(
        ParticipacioDiadaDTO^ dto,
        String^% error
    )
    {
        MySqlConnection^ conn = DB::GetConnection();

        try {

            conn->Open();

            String^ query =
                "UPDATE participacio_diada "
                "SET state = @state "
                "WHERE diada_name = @name "
                "AND date_diada = @date "
                "AND dni = @dni";

            MySqlCommand^ cmd =
                gcnew MySqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@state", dto->estat);
            cmd->Parameters->AddWithValue("@name", dto->diadaName);
            cmd->Parameters->AddWithValue("@date", dto->dateDiada);
            cmd->Parameters->AddWithValue("@dni", dto->dni);

            cmd->ExecuteNonQuery();

            return true;
        }
        catch (Exception^ ex) {

            error = ex->Message;
            return false;
        }
        finally {

            if (conn->State == ConnectionState::Open)
            {
                conn->Close();
            }
        }
    }

}
