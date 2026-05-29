#include "pch.h"
#include "CercadorCastell.h"

using namespace System::Data;

List<PasarelaCastell^>^
CercadorCastell::cercaPerNom(String^ nom)
{
    List<PasarelaCastell^>^ llista =
        gcnew List<PasarelaCastell^>();

    MySqlConnection^ conn = DB::GetConnection();

    try {

        conn->Open();

        String^ query =
            "SELECT id, nom, num_pisos, tipus "
            "FROM castell "
            "WHERE nom = @nom";

        MySqlCommand^ cmd =
            gcnew MySqlCommand(query, conn);

        cmd->Parameters->AddWithValue("@nom", nom);

        MySqlDataReader^ reader =
            cmd->ExecuteReader();

        while (reader->Read())
        {
            CastellDTO^ dto =
                gcnew CastellDTO();

            dto->idCastell =
                Convert::ToInt32(reader["id"]);

            dto->nom =
                reader["nom"]->ToString();
            //MessageBox::Show(reader["num_pisos"]->ToString());
            dto->pisos =
                Convert::ToInt32(reader["num_pisos"]);

            dto->tipus =
                reader["tipus"]->ToString();

            PasarelaCastell^ p =
                gcnew PasarelaCastell(dto);

            llista->Add(p);
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