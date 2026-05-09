#pragma once

#include "DB.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

public ref class CercadorMembre
{
public:
	static bool existeixMembre(String^ dni, String^ collaName, String^ uniName)
	{ 
		bool existeix = false;
		MySqlConnection^ conn = DB::GetConnection();

		try {
			conn->Open();
			String^ sql = "SELECT COUNT(*) FROM membre "
				"WHERE dni = @dni AND colla_name = @collaName AND uni_name = @uniName";
			MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
			cmd->Parameters->AddWithValue("@dni", dni);
			cmd->Parameters->AddWithValue("@collaName", collaName);
			cmd->Parameters->AddWithValue("@uniName", uniName);

			int count = Convert::ToInt32(cmd->ExecuteScalar());
			existeix = (count > 0);
		}
		catch (Exception^) {
			return false;
		}
		finally {
			conn->Close();
		}
		return existeix;
	}

	static bool existeixMembre(String^ dni)
	{
		bool existeix = false;
		MySqlConnection^ conn = DB::GetConnection();
		try {
			conn->Open();
			String^ sql = "SELECT COUNT(*) FROM membre WHERE dni = @dni";
			MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
			cmd->Parameters->AddWithValue("@dni", dni);
			int count = Convert::ToInt32(cmd->ExecuteScalar());
			existeix = (count > 0);
		}
		catch (Exception^) {
			return false;
		}
		finally {
			conn->Close();
		}
		return existeix;
	}

	static bool teAlgunaColla(String^ dni)
	{
		bool teColla = false;
		MySqlConnection^ conn = DB::GetConnection();

		try {
			conn->Open();
			String^ sql = "SELECT COUNT(*) FROM membre WHERE dni = @dni";
			MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
			cmd->Parameters->AddWithValue("@dni", dni);

			int count = Convert::ToInt32(cmd->ExecuteScalar());
			teColla = (count > 0);
		}
		catch (Exception^) {
			return false;
		}
		finally {
			conn->Close();
		}
		return teColla;
	}
};