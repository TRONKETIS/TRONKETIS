#include "pch.h"

#include "CercadorAssistenciaDiada.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Collections::Generic;

namespace Tronketis {

	List<ParticipantDiadaDTO^>^ CercadorAssistenciaDiada::obtenirParticipants(String^ nomDiada, DateTime dataDiada)
	{
		List<ParticipantDiadaDTO^>^ llista =
			gcnew List<ParticipantDiadaDTO^>();

		MySqlConnection^ conn =
			DB::GetConnection();

		try {
			conn->Open();

			String^ query =
				"SELECT pd.dni AS dni, u.user_name AS nom_usuari, pd.state AS estat "
				"FROM participacio_diada pd "
				"JOIN usuari u ON pd.dni = u.dni "
				"WHERE pd.diada_name = @diada_name "
				"AND pd.date_diada = @date_diada "
				"ORDER BY u.user_name";

			MySqlCommand^ cmd =
				gcnew MySqlCommand(query, conn);

			cmd->Parameters->AddWithValue("@diada_name", nomDiada);
			cmd->Parameters->AddWithValue("@date_diada", dataDiada);

			MySqlDataReader^ reader =
				cmd->ExecuteReader();

			while (reader->Read())
			{
				ParticipantDiadaDTO^ dto =
					gcnew ParticipantDiadaDTO();

				dto->dni =
					reader["dni"]->ToString();

				dto->nomUsuari =
					reader["nom_usuari"]->ToString();

				dto->estat =
					reader["estat"]->ToString();

				llista->Add(dto);
			}
		}
		finally {
			if (conn->State == ConnectionState::Open)
			{
				conn->Close();
			}
		}

		return llista;
	}
}