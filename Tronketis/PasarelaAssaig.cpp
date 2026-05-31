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
    List<AssaigDTO^>^ PasarelaAssaig::GetAssaigsDeColla(String^ colla_name, String^ colla_uni_name)
    {
        List<AssaigDTO^>^ llista = gcnew List<AssaigDTO^>();
        MySqlConnection^ conn = DB::GetConnection();
        try
        {
            conn->Open();
            String^ query = "SELECT id, data_hora, colla_name, colla_uni_name " +
                "FROM assaig WHERE colla_name = @colla_name " +
                "AND colla_uni_name = @colla_uni_name " +
                "ORDER BY data_hora ASC";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@colla_name", colla_name);
            cmd->Parameters->AddWithValue("@colla_uni_name", colla_uni_name);
            MySqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read())
            {
                AssaigDTO^ a = gcnew AssaigDTO(
                    reader->GetInt32(0),
                    reader->GetDateTime(1),
                    reader->GetString(2),
                    reader->GetString(3)
                );
                llista->Add(a);
            }
            reader->Close();
        }
        catch (Exception^ ex)
        {
            Console::WriteLine("Error a PasarelaAssaig::GetAssaigsDeColla: " + ex->Message);
        }
        finally
        {
            if (conn != nullptr && conn->State == System::Data::ConnectionState::Open)
                conn->Close();
        }
        return llista;
    }
}
