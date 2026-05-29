#include "pch.h"
#include "PasarelaMuntatgeCastell.h"
#include "DB.h"
using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

namespace Tronketis {

    List<CastellerDTO^>^ PasarelaMuntatgeCastell::obtenirCastellersPerColla(int collaId) {
        MySqlConnection^ conn = nullptr;
        List<CastellerDTO^>^ llista = gcnew List<CastellerDTO^>();
        try {
            conn = DB::GetConnection();
            conn->Open();

            // casteller + usuari per nom, membre + colla per filtrar per colla
            String^ query =
                "SELECT c.dni, u.user_name "
                "FROM casteller c "
                "JOIN usuari u ON c.dni = u.dni "
                "JOIN membre m ON c.dni = m.dni "
                "JOIN colla co ON co.name = m.colla_name "
                "WHERE co.id = @colla_id "
                "ORDER BY u.user_name";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@colla_id", collaId);

            MySqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read()) {
                CastellerDTO^ dto   = gcnew CastellerDTO();
                dto->dniCasteller   = reader->GetString("dni");
                dto->nomUsuari      = reader->GetString("user_name");
                llista->Add(dto);
            }
            return llista;
        }
        catch (Exception^) { return llista; }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open)
                conn->Close();
        }
    }

    List<PosicioCastellDTO^>^ PasarelaMuntatgeCastell::obtenirAssignacions(int castellId, int collaId) {
        MySqlConnection^ conn = nullptr;
        List<PosicioCastellDTO^>^ llista = gcnew List<PosicioCastellDTO^>();
        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query =
                "SELECT pc.num_pis, pc.num_posicio, pc.casteller_dni, u.user_name "
                "FROM posicio_castell pc "
                "JOIN usuari u ON pc.casteller_dni = u.dni "
                "WHERE pc.castell_id = @cid AND pc.colla_id = @gid";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@cid", castellId);
            cmd->Parameters->AddWithValue("@gid", collaId);

            MySqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read()) {
                PosicioCastellDTO^ p = gcnew PosicioCastellDTO();
                p->numPis        = reader->GetInt32("num_pis");
                p->numPosicio    = reader->GetInt32("num_posicio");
                p->castellerDni  = reader->GetString("casteller_dni");
                p->castellerNom  = reader->GetString("user_name");
                llista->Add(p);
            }
            return llista;
        }
        catch (Exception^) { return llista; }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open)
                conn->Close();
        }
    }

    bool PasarelaMuntatgeCastell::guardarAssignacions(int castellId, int collaId,
        List<PosicioCastellDTO^>^ posicions, String^% error)
    {
        MySqlConnection^ conn = nullptr;
        MySqlTransaction^ tx  = nullptr;
        try {
            conn = DB::GetConnection();
            conn->Open();
            tx = conn->BeginTransaction();

            MySqlCommand^ del = gcnew MySqlCommand(
                "DELETE FROM posicio_castell WHERE castell_id = @cid AND colla_id = @gid",
                conn, tx);
            del->Parameters->AddWithValue("@cid", castellId);
            del->Parameters->AddWithValue("@gid", collaId);
            del->ExecuteNonQuery();

            for each (PosicioCastellDTO^ p in posicions) {
                if (String::IsNullOrEmpty(p->castellerDni)) continue;

                MySqlCommand^ ins = gcnew MySqlCommand(
                    "INSERT INTO posicio_castell "
                    "(castell_id, colla_id, num_pis, num_posicio, casteller_dni) "
                    "VALUES (@cid, @gid, @pis, @pos, @dni)",
                    conn, tx);
                ins->Parameters->AddWithValue("@cid", castellId);
                ins->Parameters->AddWithValue("@gid", collaId);
                ins->Parameters->AddWithValue("@pis", p->numPis);
                ins->Parameters->AddWithValue("@pos", p->numPosicio);
                ins->Parameters->AddWithValue("@dni", p->castellerDni);
                ins->ExecuteNonQuery();
            }

            tx->Commit();
            return true;
        }
        catch (Exception^ ex) {
            if (tx != nullptr) try { tx->Rollback(); } catch (...) {}
            error = "Error desant assignacions: " + ex->Message;
            return false;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open)
                conn->Close();
        }
    }

}
