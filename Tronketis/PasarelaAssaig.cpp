#include "pch.h"
#include "PasarelaAssaig.h"
#include "DB.h"

namespace Tronketis {

	bool PasarelaAssaig::InsertarAssaig(AssaigDTO^ assaig)
	{
		MySqlConnection^ conn = DB::GetConnection();
		bool success = false;

		try
		{
			conn->Open();
			String^ query = "INSERT INTO assaig (data_hora, colla_name, colla_uni_name) " +
				"VALUES (@data_hora, @colla_name, @colla_uni_name)";

			MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@data_hora", assaig->DataHora);
			cmd->Parameters->AddWithValue("@colla_name", assaig->CollaName);
			cmd->Parameters->AddWithValue("@colla_uni_name", assaig->CollaUniName);

			int result = cmd->ExecuteNonQuery();
			if (result > 0)
			{
				success = true;
			}
		}
		catch (Exception^ ex)
		{
			Console::WriteLine("Error a PasarelaAssaig::InsertarAssaig: " + ex->Message);
			success = false;
		}
		finally
		{
			if (conn != nullptr && conn->State == System::Data::ConnectionState::Open)
			{
				conn->Close();
			}
		}

		return success;
	}
}
