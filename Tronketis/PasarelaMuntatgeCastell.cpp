#include "pch.h"
#include "PasarelaMuntatgeCastell.h"
#include "DB.h"
using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

namespace Tronketis {

    // Retorna els membres d'una colla (JOIN membre + usuari, filtre per colla.id)
    List<MembreDTO^>^ PasarelaMuntatgeCastell::obtenirMembresPerColla(int collaId) {
        MySqlConnection^ conn = nullptr;
        List<MembreDTO^>^ membres = gcnew List<MembreDTO^>();
        try {
            conn = DB::GetConnection();
            conn->Open();

            // membre.colla_name enllaça amb colla.name
            String^ query =
                "SELECT m.dni, u.username AS nom "
                "FROM membre m "
                "JOIN usuari u ON m.dni = u.dni "
                "JOIN colla c ON c.name = m.colla_name "
                "WHERE c.id = @colla_id "
                "ORDER BY u.username";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@colla_id", collaId);

            MySqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read()) {
                MembreDTO^ m = gcnew MembreDTO();
                m->dni = reader->GetString("dni");
                m->nom = reader->GetString("nom");
                membres->Add(m);
            }
            return membres;
        }
        catch (Exception^) {
            return membres;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open)
                conn->Close();
        }
    }

    // Retorna les assignacions ja guardades per a aquest castell+colla
    List<PosicioCastellDTO^>^ PasarelaMuntatgeCastell::obtenirAssignacionsExistents(int castellId, int collaId) {
        MySqlConnection^ conn = nullptr;
        List<PosicioCastellDTO^>^ llista = gcnew List<PosicioCastellDTO^>();
        try {
            conn = DB::GetConnection();
            conn->Open();

            String^ query =
                "SELECT pc.id, pc.num_pis, pc.num_posicio, pc.membre_dni, u.username AS membre_nom "
                "FROM posicio_castell pc "
                "LEFT JOIN usuari u ON pc.membre_dni = u.dni "
                "WHERE pc.castell_id = @castell_id AND pc.colla_id = @colla_id";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@castell_id", castellId);
            cmd->Parameters->AddWithValue("@colla_id",   collaId);

            MySqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read()) {
                PosicioCastellDTO^ p = gcnew PosicioCastellDTO();
                p->id         = reader->GetInt32("id");
                p->castellId  = castellId;
                p->collaId    = collaId;
                p->numPis     = reader->GetInt32("num_pis");
                p->numPosicio = reader->GetInt32("num_posicio");
                p->membreDni  = reader->IsDBNull(reader->GetOrdinal("membre_dni"))
                    ? nullptr : reader->GetString("membre_dni");
                p->membreNom  = reader->IsDBNull(reader->GetOrdinal("membre_nom"))
                    ? nullptr : reader->GetString("membre_nom");
                llista->Add(p);
            }
            return llista;
        }
        catch (Exception^) {
            return llista;
        }
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

            // 1. Esborra les assignacions anteriors d'aquest castell+colla
            MySqlCommand^ del = gcnew MySqlCommand(
                "DELETE FROM posicio_castell WHERE castell_id = @cid AND colla_id = @gid",
                conn, tx);
            del->Parameters->AddWithValue("@cid", castellId);
            del->Parameters->AddWithValue("@gid", collaId);
            del->ExecuteNonQuery();

            // 2. Insereix les posicions assignades (omiteix les buides)
            for each (PosicioCastellDTO^ p in posicions) {
                if (String::IsNullOrEmpty(p->membreDni)) continue;

                MySqlCommand^ ins = gcnew MySqlCommand(
                    "INSERT INTO posicio_castell (castell_id, colla_id, num_pis, num_posicio, membre_dni) "
                    "VALUES (@cid, @gid, @pis, @pos, @dni)",
                    conn, tx);
                ins->Parameters->AddWithValue("@cid", castellId);
                ins->Parameters->AddWithValue("@gid", collaId);
                ins->Parameters->AddWithValue("@pis", p->numPis);
                ins->Parameters->AddWithValue("@pos", p->numPosicio);
                ins->Parameters->AddWithValue("@dni", p->membreDni);
                ins->ExecuteNonQuery();
            }

            tx->Commit();
            return true;
        }

        catch (Exception^ ex) {
            if (tx != nullptr) try { tx->Rollback(); } catch (...) {}
            error = "Error desant les assignacions: " + ex->Message;
            return false;
        }
        finally {
            if (conn != nullptr && conn->State == ConnectionState::Open)
                conn->Close();
        }
    }

}
