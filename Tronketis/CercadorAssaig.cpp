#include "pch.h"
#include "CercadorAssaig.h"
#include "DB.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

	List<AssaigDTO^>^ CercadorAssaig::obtenirAssaigsPerMesIColla(int month, int year, String^ collaName)
	{
		List<AssaigDTO^>^ llista = gcnew List<AssaigDTO^>();
		MySqlConnection^ conn = DB::GetConnection();

		try {
			conn->Open();
			// Buscar eventos en el mes y año dado para tu colla
			String^ query = "SELECT id, data_hora, colla_name, colla_uni_name FROM assaig "
							"WHERE MONTH(data_hora) = @month AND YEAR(data_hora) = @year "
							"AND colla_name = @collaName";

			MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@month", month);
			cmd->Parameters->AddWithValue("@year", year);
			cmd->Parameters->AddWithValue("@collaName", collaName);

			MySqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read())
			{
				AssaigDTO^ dto = gcnew AssaigDTO(
					Convert::ToInt32(reader["id"]),
					Convert::ToDateTime(reader["data_hora"]),
					reader["colla_name"]->ToString(),
					reader["colla_uni_name"]->ToString()
				);
				llista->Add(dto);
			}
		}
		catch (Exception^ ex) {
			Console::WriteLine("Error a CercadorAssaig::obtenirAssaigsPerMesIColla: " + ex->Message);
		}
		finally {
			if (conn != nullptr && conn->State == ConnectionState::Open) {
				conn->Close();
			}
		}

		return llista;
	}
}