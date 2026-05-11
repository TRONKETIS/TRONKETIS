#include "pch.h"
#include "CtrlAssignarCastellers.h"
#include "PasarelaMuntatgeCastell.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace Tronketis;

namespace Tronketis {

    List<MembreDTO^>^ CtrlAssignarCastellers::CarregarMembres(int collaId) {
        return PasarelaMuntatgeCastell::obtenirMembresPerColla(collaId);
    }

    bool CtrlAssignarCastellers::Assignar(int castellId, int collaId,
        List<PosicioCastellDTO^>^ posicions, String^% error)
    {
        if (!validarSenseDuplicats(posicions, error)) return false;

        try {
            return PasarelaMuntatgeCastell::guardarAssignacions(castellId, collaId, posicions, error);
        }
        catch (Exception^ ex) {
            error = "Error de base de dades: " + ex->Message;
            return false;
        }
    }

    // Cap membre (dni) pot aparèixer dues vegades en el mateix castell
    bool CtrlAssignarCastellers::validarSenseDuplicats(List<PosicioCastellDTO^>^ posicions, String^% error) {
        List<String^>^ vistos = gcnew List<String^>();
        for each (PosicioCastellDTO^ p in posicions) {
            if (String::IsNullOrEmpty(p->membreDni)) continue;
            if (vistos->Contains(p->membreDni)) {
                error = "Un mateix casteller no pot ocupar dues posicions a la vegada";
                return false;
            }
            vistos->Add(p->membreDni);
        }
        return true;
    }

}
