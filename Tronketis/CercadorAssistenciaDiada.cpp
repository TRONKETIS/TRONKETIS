#include "pch.h"

#include "CercadorAssistenciaDiada.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Collections::Generic;

namespace Tronketis {

	/*
	 * Obté tots els participants d'una diada concreta.
	 * Rep el nom i la data de la diada perquè aquests camps identifiquen la diada.
	 */
	List<ParticipantDiadaDTO^>^ CercadorAssistenciaDiada::obtenirParticipants(String^ nomDiada, DateTime dataDiada)
	{
		// Llista on es guardaran els participants trobats.
		List<ParticipantDiadaDTO^>^ llista =
			gcnew List<ParticipantDiadaDTO^>();

		// Obtenim la connexió amb la base de dades.
		MySqlConnection^ conn =
			DB::GetConnection();

		try {
			// Obrim la connexió abans d'executar la consulta.
			conn->Open();

			// Consulta SQL que obté els participants d'una diada.
			// Es fa JOIN amb usuari per poder mostrar el nom de l'usuari, no només el DNI.
			String^ query =
				"SELECT pd.dni AS dni, u.user_name AS nom_usuari, pd.state AS estat "
				"FROM participacio_diada pd "
				"JOIN usuari u ON pd.dni = u.dni "
				"WHERE pd.diada_name = @diada_name "
				"AND pd.date_diada = @date_diada "
				"ORDER BY u.user_name";

			// Creem la comanda SQL.
			MySqlCommand^ cmd =
				gcnew MySqlCommand(query, conn);

			// Assignem el nom de la diada al paràmetre de la consulta.
			cmd->Parameters->AddWithValue("@diada_name", nomDiada);

			// Assignem la data de la diada al paràmetre de la consulta.
			cmd->Parameters->AddWithValue("@date_diada", dataDiada);

			// ExecuteReader permet llegir totes les files retornades.
			MySqlDataReader^ reader =
				cmd->ExecuteReader();

			// Recorrem tots els participants retornats per la consulta.
			while (reader->Read())
			{
				// Creem un DTO per guardar les dades d'un participant.
				ParticipantDiadaDTO^ dto =
					gcnew ParticipantDiadaDTO();

				// Guardem el DNI del participant.
				dto->dni =
					reader["dni"]->ToString();

				// Guardem el nom d'usuari associat al DNI.
				dto->nomUsuari =
					reader["nom_usuari"]->ToString();

				// Guardem l'estat d'assistència: Apuntat, Confirmat o Cancelat.
				dto->estat =
					reader["estat"]->ToString();

				// Afegim el participant a la llista final.
				llista->Add(dto);
			}
		}
		finally {
			// Tanquem la connexió si continua oberta.
			if (conn->State == ConnectionState::Open)
			{
				conn->Close();
			}
		}

		// Retornem la llista de participants trobats.
		return llista;
	}
}