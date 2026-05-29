#include "pch.h"
#include "PasarelaCasteller.h"


using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

void PasarelaCasteller::insertar(CastellerDTO^ c)
{
    MySqlConnection^ conn = DB::GetConnection();

    try {

        conn->Open();

        String^ query =
            "INSERT INTO casteller (dni, tel_num) "
            "VALUES (@dni, @telefon)";

        MySqlCommand^ cmd =
            gcnew MySqlCommand(query, conn);

        cmd->Parameters->AddWithValue("@dni", c->dniCasteller);

        if (String::IsNullOrWhiteSpace(c->telefon))
        {
            cmd->Parameters->AddWithValue("@telefon", DBNull::Value);
        }
        else
        {
            cmd->Parameters->AddWithValue("@telefon", c->telefon);
        }

        cmd->ExecuteNonQuery();
    }
    finally {

        if (conn->State == ConnectionState::Open)
        {
            conn->Close();
        }
    }
}