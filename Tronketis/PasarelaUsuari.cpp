#include "pch.h"
#include "PasarelaUsuari.h"

using namespace Tronketis;

void PasarelaUsuari::insertar(UsuariDTO^ u)
{
    MySqlConnection^ conn = DB::GetConnection();
    conn->Open();

    String^ query =
        "INSERT INTO usuari (dni, user_name, email_addr, user_pass, user_role) "
        "VALUES (@dni, @username, @email, @password, @rol)";

    MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

    cmd->Parameters->AddWithValue("@dni", u->dni);
    cmd->Parameters->AddWithValue("@username", u->username);
    cmd->Parameters->AddWithValue("@email", u->email);
    cmd->Parameters->AddWithValue("@password", u->password);
    cmd->Parameters->AddWithValue("@rol", u->rol);

    cmd->ExecuteNonQuery();
    conn->Close();
}

bool PasarelaUsuari::modificarUsuari(UsuariDTO^ u)
{
    MySqlConnection^ conn = DB::GetConnection();
    conn->Open();

    String^ query =
        "UPDATE usuari SET "
        "user_name=@username, "
        "email_addr=@email, "
        "user_pass=@password, "
        "user_role=@rol "
        "WHERE dni=@dni";

    MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

    cmd->Parameters->AddWithValue("@username", u->username);
    cmd->Parameters->AddWithValue("@email", u->email);
    cmd->Parameters->AddWithValue("@password", u->password);
    cmd->Parameters->AddWithValue("@rol", u->rol);
    cmd->Parameters->AddWithValue("@dni", u->dni);

    int rows = cmd->ExecuteNonQuery();
    conn->Close();

    return rows == 1;
}
