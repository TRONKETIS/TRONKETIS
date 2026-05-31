#include "pch.h"
#include "CercadorAssignacioCastellDiada.h"

using namespace System::Data;

namespace Tronketis {

    bool CercadorAssignacioCastellDiada::existeixAssignacio(String^ diadaName,
        DateTime dateDiada,
        int castellId,
        String^ collaName)
    {
        bool existeix = false;
        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();

            String^ query =
                "SELECT COUNT(*) "
                "FROM assignacio_castell_diada "
                "WHERE diada_name = @diadaName "
                "AND date_diada = @dateDiada "
                "AND castell_id = @castellId "
                "AND colla_name = @collaName";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@diadaName", diadaName);
            cmd->Parameters->AddWithValue("@dateDiada", dateDiada);
            cmd->Parameters->AddWithValue("@castellId", castellId);
            cmd->Parameters->AddWithValue("@collaName", collaName);

            int count = Convert::ToInt32(cmd->ExecuteScalar());
            existeix = (count > 0);
        }
        finally {
            if (conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }

        return existeix;
    }

    List<PasarelaCastell^>^
        CercadorAssignacioCastellDiada::obtenirCastellsAssignats(String^ diadaName,
            DateTime dateDiada,
            String^ collaName)
    {
        List<PasarelaCastell^>^ llista =
            gcnew List<PasarelaCastell^>();

        MySqlConnection^ conn = DB::GetConnection();

        try {
            conn->Open();

            String^ query =
                "SELECT c.id, c.nom, c.num_pisos, c.tipus "
                "FROM assignacio_castell_diada acd "
                "INNER JOIN castell c ON acd.castell_id = c.id "
                "WHERE acd.diada_name = @diadaName "
                "AND acd.date_diada = @dateDiada "
                "AND acd.colla_name = @collaName "
                "ORDER BY c.nom";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@diadaName", diadaName);
            cmd->Parameters->AddWithValue("@dateDiada", dateDiada);
            cmd->Parameters->AddWithValue("@collaName", collaName);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read())
            {
                CastellDTO^ dto = gcnew CastellDTO();

                dto->idCastell = Convert::ToInt32(reader["id"]);
                dto->nom = reader["nom"]->ToString();
                dto->pisos = Convert::ToInt32(reader["num_pisos"]);
                dto->tipus = reader["tipus"]->ToString();

                PasarelaCastell^ p = gcnew PasarelaCastell(dto);

                llista->Add(p);
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