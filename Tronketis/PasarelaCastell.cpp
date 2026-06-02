#include "pch.h"
#include "PasarelaCastell.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

namespace Tronketis {

    /*
     * Insereix un nou castell a la base de dades.
     * Rep un CastellDTO amb les dades del castell i una variable error per retornar
     * informació en cas que la inserció falli.
     */
    bool PasarelaCastell::insertar(CastellDTO^ castell, String^% error) {

        // Inicialitzem la connexió a nullptr per poder comprovar-la després al finally.
        MySqlConnection^ conn = nullptr;

        try {
            // Obtenim la connexió amb la base de dades des de la classe DB.
            conn = DB::GetConnection();

            // Obrim la connexió abans d'executar consultes SQL.
            conn->Open();

            // Consulta SQL parametrizada per inserir un nou registre a la taula castell.
            // No s'inclou l'id perquè normalment és auto_increment a la base de dades.
            String^ query = "INSERT INTO castell (nom, tipus, num_pisos) "
                "VALUES (@nom, @tipus, @num_pisos)";

            // Creem la comanda SQL associada a la connexió oberta.
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            // Assignem el valor del nom del castell al paràmetre @nom.
            cmd->Parameters->AddWithValue("@nom", castell->nom);

            // Assignem el tipus del castell al paràmetre @tipus.
            cmd->Parameters->AddWithValue("@tipus", castell->tipus);

            // Assignem el nombre de pisos al paràmetre @num_pisos.
            cmd->Parameters->AddWithValue("@num_pisos", castell->pisos);

            // ExecuteNonQuery executa l'INSERT, ja que no esperem cap taula de resultats.
            cmd->ExecuteNonQuery();

            // Després d'inserir el castell, recuperem l'id generat automàticament per MySQL.
            // LAST_INSERT_ID() retorna l'últim identificador auto_increment creat en aquesta connexió.
            cmd = gcnew MySqlCommand("SELECT LAST_INSERT_ID()", conn);

            // Guardem l'id generat dins del DTO per poder-lo reutilitzar després.
            castell->idCastell = Convert::ToInt32(cmd->ExecuteScalar());

            // Si tot ha anat bé, retornem true.
            return true;
        }
        catch (Exception^ ex) {
            // Si es produeix qualsevol error, guardem el missatge a la variable error.
            error = "Error: " + ex->Message;

            // Retornem false per indicar que la inserció no s'ha pogut completar.
            return false;
        }
        finally {
            // El bloc finally s'executa sempre, tant si hi ha error com si no.
            // Això garanteix que la connexió no quedi oberta.
            if (conn != nullptr && conn->State == ConnectionState::Open) {
                conn->Close();
            }
        }
    }

    /*
     * Constructor de la passarel·la.
     * Desa internament el DTO rebut per poder accedir a les seves dades.
     */
    PasarelaCastell::PasarelaCastell(CastellDTO^ dto)
    {
        this->dto = dto;
    }

    // Retorna l'identificador del castell.
    int PasarelaCastell::getId()
    {
        return dto->idCastell;
    }

    // Retorna el nom del castell.
    String^ PasarelaCastell::getNom()
    {
        return dto->nom;
    }

    // Retorna el nombre de pisos del castell.
    int PasarelaCastell::getPisos()
    {
        return dto->pisos;
    }

    // Retorna el tipus del castell.
    String^ PasarelaCastell::getTipus()
    {
        return dto->tipus;
    }
}