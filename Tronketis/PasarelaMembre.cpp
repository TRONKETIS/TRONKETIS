#include "pch.h"
#include "PasarelaMembre.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

/*
 * Insereix un nou membre dins d'una colla.
 * Aquesta funció relaciona un casteller, identificat pel seu DNI,
 * amb una colla concreta i la seva universitat.
 */
bool PasarelaMembre::insertar(String^ dni,
    String^ collaName,
    String^ uniName,
    DateTime joinDate)
{
    // Variable que indicarà si l'operació s'ha fet correctament o no.
    bool correcte = false;

    // Obtenim la connexió amb la base de dades.
    MySqlConnection^ conn = DB::GetConnection();

    try {
        // Obrim la connexió abans d'executar la consulta.
        conn->Open();

        // Consulta SQL per inserir un registre a la taula membre.
        // Es fan servir paràmetres per evitar concatenar dades directament a la consulta.
        String^ sql =
            "INSERT INTO membre (dni, colla_name, uni_name, join_date) "
            "VALUES (@dni, @collaName, @uniName, @joinDate)";

        // Creem la comanda SQL associada a la connexió oberta.
        MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

        // Assignem els valors rebuts als paràmetres de la consulta.
        cmd->Parameters->AddWithValue("@dni", dni);
        cmd->Parameters->AddWithValue("@collaName", collaName);
        cmd->Parameters->AddWithValue("@uniName", uniName);
        cmd->Parameters->AddWithValue("@joinDate", joinDate);

        // ExecuteNonQuery retorna el nombre de files afectades.
        // Si és 1, vol dir que s'ha inserit correctament un membre.
        correcte = (cmd->ExecuteNonQuery() == 1);
    }
    catch (Exception^ ex) {
        // Si hi ha qualsevol error durant la inserció, retornem false.
        // Per exemple: DNI duplicat, colla inexistent o error de connexió.
        correcte = false;
    }
    finally {
        // Tanquem la connexió per alliberar recursos.
        conn->Close();
    }

    // Retornem el resultat de l'operació.
    return correcte;
}

/*
 * Elimina un membre de la taula membre a partir del seu DNI.
 * Aquesta funció serveix per treure un casteller de la colla.
 */
bool PasarelaMembre::eliminarMembre(String^ dni)
{
    // Variable que indicarà si l'eliminació s'ha fet correctament.
    bool correcte = false;

    // Obtenim la connexió amb la base de dades.
    MySqlConnection^ conn = DB::GetConnection();

    try {
        // Obrim la connexió abans d'executar el DELETE.
        conn->Open();

        // Consulta SQL per eliminar un membre segons el seu DNI.
        String^ sql =
            "DELETE FROM membre "
            "WHERE dni = @dni";

        // Creem la comanda SQL.
        MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

        // Assignem el DNI rebut al paràmetre de la consulta.
        cmd->Parameters->AddWithValue("@dni", dni);

        // Si ExecuteNonQuery retorna 1, vol dir que s'ha eliminat una fila.
        correcte = (cmd->ExecuteNonQuery() == 1);
    }
    catch (Exception^ ex) {
        // Si hi ha un error, indiquem que l'operació no ha estat correcta.
        correcte = false;
    }
    finally {
        // Tanquem la connexió amb la base de dades.
        conn->Close();
    }

    // Retornem si s'ha eliminat correctament o no.
    return correcte;
}