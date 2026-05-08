#include "pch.h"
#include "PasarelaMembre.h"



bool PasarelaMembre::insertar(System::String^ dni,
    System::String^ collaName,
    System::String^ uniName,
    System::DateTime joinDate)
{
    bool correcte = false;
    MySql::Data::MySqlClient::MySqlConnection^ conn = DB::GetConnection();

    try {
        conn->Open();

        System::String^ sql =
            "INSERT INTO membre (dni, colla_name, uni_name, join_date) "
            "VALUES (@dni, @collaName, @uniName, @joinDate)";

        MySql::Data::MySqlClient::MySqlCommand^ cmd =
            gcnew MySql::Data::MySqlClient::MySqlCommand(sql, conn);

        cmd->Parameters->AddWithValue("@dni", dni);
        cmd->Parameters->AddWithValue("@collaName", collaName);
        cmd->Parameters->AddWithValue("@uniName", uniName);
        cmd->Parameters->AddWithValue("@joinDate", joinDate);

        int files = cmd->ExecuteNonQuery();

        if (files == 1) {
            correcte = true;
        }
    }
    catch (System::Exception^ ex) {
        System::Windows::Forms::MessageBox::Show(ex->Message);
        correcte = false;
    }
    finally {
        conn->Close();
    }

    return correcte;
}