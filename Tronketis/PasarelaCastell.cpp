#include "pch.h"
#include "PasarelaCastell.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

namespace Tronketis {

    bool PasarelaCastell::insertar(CastellDTO^ castell, String^% error) {
        MySqlConnection^ conn = nullptr;
        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query = "INSERT INTO castell (nom, tipus, num_pisos, colla) "
                "VALUES (@nom, @tipus, @num_pisos, @colla)";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@nom",      castell->nom);
            cmd->Parameters->AddWithValue("@tipus",    castell->tipus);
            cmd->Parameters->AddWithValue("@num_pisos", castell->pisos);
            cmd->Parameters->AddWithValue("@colla",    castell->colla);

            cmd->ExecuteNonQuery();

            cmd = gcnew MySqlCommand("SELECT LAST_INSERT_ID()", conn);
            castell->idCastell = Convert::ToInt32(cmd->ExecuteScalar());

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

    PasarelaCastell::PasarelaCastell(CastellDTO^ dto)
    {
        this->dto = dto;
    }
    int PasarelaCastell::getId()
    {
        return dto->idCastell;
    }

    String^ PasarelaCastell::getNom()
    {
        return dto->nom;
    }

    int PasarelaCastell::getPisos()
    {
        return dto->pisos;
    }

    String^ PasarelaCastell::getTipus()
    {
        return dto->tipus;
    }
}