#include "pch.h"
#include "DB.h"
#include "CercadoraEsdeveniment.h"

using namespace Tronketis;

// Mètode que comprovarà si la combinació nom+data ja existeix a la DB
bool CercadoraEsdeveniment::existeixDiada(String^ name, String^ date)
{
    MySqlConnection^ conn = DB::GetConnection();
    bool existeix = false;

    try {
        conn->Open();

		//Retorna el nombre de diades que tenen el mateix nom i data
        String^ query = "SELECT COUNT(*) FROM diada WHERE name = @name AND date_diada = @date";

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

        cmd->Parameters->AddWithValue("@name", name);
        cmd->Parameters->AddWithValue("@date", date);

        int count = Convert::ToInt32(cmd->ExecuteScalar());

		//Si el nombre de diades és diferent de 0, vol dir que ja existeix una diada amb el mateix nom i data
        if (count > 0) {
            existeix = true;
        }

    }
    catch (MySqlException^ ex) {
        // Si hi ha un error de connexió, el llancem cap amunt
        throw ex;
    }
    finally {
        // Tanquem la connexió de forma segura
        if (conn->State == System::Data::ConnectionState::Open) {
            conn->Close();
        }
    }

    return existeix;
}