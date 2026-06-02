#include "pch.h"
#include "PasarelaCasteller.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

/*
 * Insereix un nou casteller a la base de dades.
 * Rep com a paràmetre un CastellerDTO amb les dades necessàries.
 */
void PasarelaCasteller::insertar(CastellerDTO^ c)
{
    // Es demana una connexió a la base de dades a través de la classe DB.
    MySqlConnection^ conn = DB::GetConnection();

    try {

        // S'obre la connexió abans d'executar qualsevol consulta SQL.
        conn->Open();

        // Consulta SQL parametrizada per inserir un registre a la taula casteller.
        // No es concatenen valors directament per evitar problemes de seguretat.
        String^ query =
            "INSERT INTO casteller (dni, tel_num) "
            "VALUES (@dni, @telefon)";

        // Es crea la comanda SQL indicant la consulta i la connexió activa.
        MySqlCommand^ cmd =
            gcnew MySqlCommand(query, conn);

        // S'assigna el valor del DNI al paràmetre @dni.
        // Aquest camp identifica el casteller dins de la base de dades.
        cmd->Parameters->AddWithValue("@dni", c->dniCasteller);

        // El telèfon és un camp opcional.
        // Per això es comprova si està buit, nul o format només per espais.
        if (String::IsNullOrWhiteSpace(c->telefon))
        {
            // Si no s'ha indicat cap telèfon, es guarda NULL a la base de dades.
            // DBNull::Value representa un valor nul compatible amb SQL.
            cmd->Parameters->AddWithValue("@telefon", DBNull::Value);
        }
        else
        {
            // Si el telèfon existeix, s'insereix el valor rebut al DTO.
            cmd->Parameters->AddWithValue("@telefon", c->telefon);
        }

        // ExecuteNonQuery s'utilitza per consultes que no retornen resultats,
        // com INSERT, UPDATE o DELETE.
        cmd->ExecuteNonQuery();
    }
    finally {

        // El bloc finally s'executa sempre, tant si la consulta va bé com si falla.
        // Això garanteix que la connexió no quedi oberta accidentalment.
        if (conn->State == ConnectionState::Open)
        {
            // Es tanca la connexió per alliberar recursos.
            conn->Close();
        }
    }
}