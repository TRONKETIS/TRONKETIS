#include "pch.h"
#include "PasarelaMembre.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

bool PasarelaMembre::insertar(String^ dni,
    String^ collaName,
    String^ uniName,
    DateTime joinDate)
{
    bool correcte = false;
    MySqlConnection^ conn = DB::GetConnection();

    try {
        conn->Open();

        String^ sql =
            "INSERT INTO membre (dni, colla_name, uni_name, join_date) "
            "VALUES (@dni, @collaName, @uniName, @joinDate)";

        MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
        cmd->Parameters->AddWithValue("@dni", dni);
        cmd->Parameters->AddWithValue("@collaName", collaName);
        cmd->Parameters->AddWithValue("@uniName", uniName);
        cmd->Parameters->AddWithValue("@joinDate", joinDate);

        correcte = (cmd->ExecuteNonQuery() == 1);
    }
    catch (Exception^ ex) {
        System::Windows::Forms::MessageBox::Show(ex->Message, "Error SQL");
        correcte = false;
    }
    finally {
        conn->Close();
    }

    return correcte;
}

bool PasarelaMembre::eliminarMembre(String^ dni)
{
    bool correcte = false;
    MySqlConnection^ conn = DB::GetConnection();
    try {
        conn->Open();
        String^ sql =
            "DELETE FROM membre "
            "WHERE dni = @dni";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
        cmd->Parameters->AddWithValue("@dni", dni);
        correcte = (cmd->ExecuteNonQuery() == 1);
    }
    catch (Exception^ ex) {
        System::Windows::Forms::MessageBox::Show(ex->Message, "Error SQL");
        correcte = false;
    }
    finally {
        conn->Close();
    }
    return correcte;
}