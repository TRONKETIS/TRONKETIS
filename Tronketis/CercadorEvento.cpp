#include "pch.h"
#include "CercadorEvento.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

	List<EventoDTO^>^ CercadorEvento::obtenirEventsPerMes(int month, int year)
	{
		List<EventoDTO^>^ llista = gcnew List<EventoDTO^>();
		MySqlConnection^ conn = DB::GetConnection();

		try {
			conn->Open();
			// Buscar eventos en el mes y año dado
			String^ query = "SELECT ev_name, ev_date, location, aprox_mem FROM evento "
							"WHERE MONTH(ev_date) = @month AND YEAR(ev_date) = @year";

			MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@month", month);
			cmd->Parameters->AddWithValue("@year", year);

			MySqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read())
			{
				EventoDTO^ dto = gcnew EventoDTO();
				dto->EvName = reader["ev_name"]->ToString();
				dto->EvDate = Convert::ToDateTime(reader["ev_date"]);
				dto->Location = reader["location"] != DBNull::Value ? reader["location"]->ToString() : "";
				dto->AproxMem = Convert::ToInt32(reader["aprox_mem"]);
				llista->Add(dto);
			}
		}
		catch (Exception^ ex) {
			Console::WriteLine("Error a CercadorEvento::obtenirEventsPerMes: " + ex->Message);
		}
		finally {
			if (conn != nullptr && conn->State == ConnectionState::Open) {
				conn->Close();
			}
		}

		return llista;
	}
}