#include "pch.h"
#include "PasarelaParticipacioDiada.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    /*
     * Comprova si ja existeix una participació d'un casteller en una diada.
     * Serveix per evitar inserir registres duplicats a la taula participacio_diada.
     */
    bool PasarelaParticipacioDiada::existeix(
        String^ diadaName,
        DateTime dateDiada,
        String^ dni
    )
    {
        // Obtenim la connexió amb la base de dades.
        MySqlConnection^ conn = DB::GetConnection();

        try {

            // Obrim la connexió abans d'executar la consulta.
            conn->Open();

            // Consulta que compta quants registres coincideixen amb la diada, la data i el DNI.
            String^ query =
                "SELECT COUNT(*) "
                "FROM participacio_diada "
                "WHERE diada_name = @name "
                "AND date_diada = @date "
                "AND dni = @dni";

            // Creem la comanda SQL.
            MySqlCommand^ cmd =
                gcnew MySqlCommand(query, conn);

            // Assignem els valors als paràmetres de la consulta.
            cmd->Parameters->AddWithValue("@name", diadaName);
            cmd->Parameters->AddWithValue("@date", dateDiada);
            cmd->Parameters->AddWithValue("@dni", dni);

            // ExecuteScalar retorna un únic valor: en aquest cas, el COUNT(*).
            int count =
                Convert::ToInt32(cmd->ExecuteScalar());

            // Si el comptador és més gran que 0, la participació ja existeix.
            return count > 0;
        }
        finally {

            // Tanquem la connexió si encara està oberta.
            if (conn->State == ConnectionState::Open)
            {
                conn->Close();
            }
        }
    }

    /*
     * Registra una nova participació d'un casteller en una diada.
     * Desa el nom de la diada, la data, el DNI del casteller i l'estat d'assistència.
     */
    bool PasarelaParticipacioDiada::registrar(
        ParticipacioDiadaDTO^ dto,
        String^% error
    )
    {
        // Obtenim la connexió amb la base de dades.
        MySqlConnection^ conn = DB::GetConnection();

        try {

            // Obrim la connexió.
            conn->Open();

            // Consulta SQL per inserir una nova fila a participacio_diada.
            String^ query =
                "INSERT INTO participacio_diada "
                "(diada_name, date_diada, dni, state) "
                "VALUES "
                "(@name, @date, @dni, @state)";

            // Creem la comanda SQL associada a la connexió.
            MySqlCommand^ cmd =
                gcnew MySqlCommand(query, conn);

            // Assignem el nom de la diada.
            cmd->Parameters->AddWithValue("@name", dto->diadaName);

            // Assignem la data de la diada.
            cmd->Parameters->AddWithValue("@date", dto->dateDiada);

            // Assignem el DNI del casteller.
            cmd->Parameters->AddWithValue("@dni", dto->dni);

            // Assignem l'estat: Apuntat, Confirmat o Cancelat.
            cmd->Parameters->AddWithValue("@state", dto->estat);

            // Executem l'INSERT.
            cmd->ExecuteNonQuery();

            // Si no hi ha excepcions, la inserció s'ha fet correctament.
            return true;
        }
        catch (Exception^ ex) {

            // Guardem el missatge d'error per mostrar-lo des del controlador o formulari.
            error = ex->Message;

            // Retornem false per indicar que no s'ha pogut registrar.
            return false;
        }
        finally {

            // Tanquem la connexió per evitar deixar recursos oberts.
            if (conn->State == ConnectionState::Open)
            {
                conn->Close();
            }
        }
    }

    /*
     * Actualitza l'estat d'una participació ja existent.
     * S'utilitza quan un casteller ja estava registrat a la diada
     * i només es vol canviar el seu estat d'assistència.
     */
    bool PasarelaParticipacioDiada::actualitzarEstat(
        ParticipacioDiadaDTO^ dto,
        String^% error
    )
    {
        // Obtenim la connexió amb la base de dades.
        MySqlConnection^ conn = DB::GetConnection();

        try {

            // Obrim la connexió abans de fer l'UPDATE.
            conn->Open();

            // Consulta SQL que modifica únicament el camp state.
            String^ query =
                "UPDATE participacio_diada "
                "SET state = @state "
                "WHERE diada_name = @name "
                "AND date_diada = @date "
                "AND dni = @dni";

            // Creem la comanda SQL.
            MySqlCommand^ cmd =
                gcnew MySqlCommand(query, conn);

            // Nou estat que volem guardar.
            cmd->Parameters->AddWithValue("@state", dto->estat);

            // Identificador de la diada.
            cmd->Parameters->AddWithValue("@name", dto->diadaName);

            // Data de la diada.
            cmd->Parameters->AddWithValue("@date", dto->dateDiada);

            // DNI del casteller.
            cmd->Parameters->AddWithValue("@dni", dto->dni);

            // Executem l'UPDATE.
            cmd->ExecuteNonQuery();

            // Si no hi ha errors, retornem true.
            return true;
        }
        catch (Exception^ ex) {

            // Guardem l'error produït.
            error = ex->Message;

            // Retornem false perquè l'actualització ha fallat.
            return false;
        }
        finally {

            // Tanquem la connexió si continua oberta.
            if (conn->State == ConnectionState::Open)
            {
                conn->Close();
            }
        }
    }

}