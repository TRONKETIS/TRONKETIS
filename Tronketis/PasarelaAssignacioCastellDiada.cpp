#include "pch.h"
#include "PasarelaAssignacioCastellDiada.h"

using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    bool PasarelaAssignacioCastellDiada::inserir(String^ diadaName,
        DateTime dateDiada,
        int castellId,
        String^ collaName,
        String^ uniName,
        String^% error)
    {
        bool correcte = false;
        error = "";

        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();

            String^ query =
                "INSERT INTO assignacio_castell_diada "
                "(diada_name, date_diada, castell_id, colla_name, uni_name) "
                "VALUES (@diadaName, @dateDiada, @castellId, @collaName, @uniName)";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@diadaName", diadaName);
            cmd->Parameters->AddWithValue("@dateDiada", dateDiada);
            cmd->Parameters->AddWithValue("@castellId", castellId);
            cmd->Parameters->AddWithValue("@collaName", collaName);
            cmd->Parameters->AddWithValue("@uniName", uniName);

            int files = cmd->ExecuteNonQuery();

            correcte = (files == 1);
        }
        catch (Exception^ ex) {
            error = ex->Message;
            correcte = false;
        }
        finally {
            if (conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }

        return correcte;
    }

}