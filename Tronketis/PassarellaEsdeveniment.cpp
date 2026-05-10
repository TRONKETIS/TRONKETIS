#include "pch.h"
#include "PassarellaEsdeveniment.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

using namespace Tronketis;

void PassarellaEsdeveniment::insertar(EsdevenimentDTO^ e)
{
    MySqlConnection^ conn = DB::GetConnection();
    conn->Open();

    String^ query = "INSERT INTO diada (name, date_diada, location, descrip, tipus) "
        "VALUES (@name, @date_diada, @location, @descrip, @tipus)";

    MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

    cmd->Parameters->AddWithValue("@name", e->name);
    cmd->Parameters->AddWithValue("@date_diada", e->date);
    cmd->Parameters->AddWithValue("@location", e->location);
    cmd->Parameters->AddWithValue("@descrip", e->description);
    cmd->Parameters->AddWithValue("@tipus", e->tipus);

    cmd->ExecuteNonQuery();
    conn->Close();
}