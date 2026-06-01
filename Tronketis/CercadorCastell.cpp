#include "pch.h"
#include "CercadorCastell.h"

using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;

static PasarelaCastell^ construirPasarelaCastell(MySqlDataReader^ reader)
{
    CastellDTO^ dto = gcnew CastellDTO();

    dto->idCastell = Convert::ToInt32(reader["id"]);
    dto->nom = reader["nom"]->ToString();
    dto->pisos = Convert::ToInt32(reader["num_pisos"]);
    dto->tipus = reader["tipus"]->ToString();

    if (Convert::IsDBNull(reader["colla"])) dto->colla = "";
    else dto->colla = reader["colla"]->ToString();

    return gcnew PasarelaCastell(dto);
}

List<PasarelaCastell^>^ CercadorCastell::cercaPerNom(String^ nom)
{
    List<PasarelaCastell^>^ llista = gcnew List<PasarelaCastell^>();
    MySqlConnection^ conn = DB::GetConnection();

    try {
        conn->Open();

        String^ query =
            "SELECT id, nom, num_pisos, tipus, colla "
            "FROM castell "
            "WHERE nom = @nom";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@nom", nom);

        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            llista->Add(construirPasarelaCastell(reader));
        }
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }

    return llista;
}

List<PasarelaCastell^>^ CercadorCastell::cercaPerNomIColla(String^ nom, String^ colla)
{
    List<PasarelaCastell^>^ llista = gcnew List<PasarelaCastell^>();
    MySqlConnection^ conn = DB::GetConnection();

    try {
        conn->Open();

        String^ query =
            "SELECT id, nom, num_pisos, tipus, colla "
            "FROM castell "
            "WHERE nom = @nom AND colla = @colla";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@nom", nom);
        cmd->Parameters->AddWithValue("@colla", colla);

        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            llista->Add(construirPasarelaCastell(reader));
        }
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }

    return llista;
}

List<PasarelaCastell^>^ CercadorCastell::obtenirTots()
{
    List<PasarelaCastell^>^ llista = gcnew List<PasarelaCastell^>();
    MySqlConnection^ conn = DB::GetConnection();

    try {
        conn->Open();

        String^ query =
            "SELECT id, nom, num_pisos, tipus, colla "
            "FROM castell "
            "ORDER BY nom";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            llista->Add(construirPasarelaCastell(reader));
        }
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }

    return llista;
}

List<PasarelaCastell^>^ CercadorCastell::obtenirPerColla(String^ colla)
{
    List<PasarelaCastell^>^ llista = gcnew List<PasarelaCastell^>();
    MySqlConnection^ conn = DB::GetConnection();

    try {
        conn->Open();

        String^ query =
            "SELECT id, nom, num_pisos, tipus, colla "
            "FROM castell "
            "WHERE colla = @colla "
            "ORDER BY nom";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@colla", colla);

        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            llista->Add(construirPasarelaCastell(reader));
        }
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }

    return llista;
}
