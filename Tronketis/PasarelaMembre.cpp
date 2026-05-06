#include "PasarelaMembre.h"

bool PasarelaMembre::insertar(String^ dni, String^ collaName, String^ uniName, DateTime joinDate)
{
	bool correcte = false;
	MySqlConnection^ conn = DB::GetConnection();
	try {
		conn->Open();
		String^ sql = "INSERT INTO membre (dni, colla_name, uni_name, join_date) VALUES (@dni, @collaName, @uniName, @joinDate)";
		MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
		cmd->Parameters->AddWithValue("@dni", dni);
		cmd->Parameters->AddWithValue("@collaName", collaName);
		cmd->Parameters->AddWithValue("@uniName", uniName);
		cmd->Parameters->AddWithValue("@joinDate", joinDate);
		int files = cmd->ExecuteNonQuery();
		if(files == 1) {
			correcte = true;
		}
	}
	catch (Exception^) {
		return false;
	}
	finally {
		conn->Close();
	}
	return correcte;
}