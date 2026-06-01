#include "pch.h"
#include "CtrlAssignarCastellers.h"
#include "PasarelaMuntatgeCastell.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace Tronketis;

namespace Tronketis {

    List<CastellDTO^>^ CtrlAssignarCastellers::CarregarCastells(String^ collaName)
    {
        return PasarelaMuntatgeCastell::obtenirCastellsPerColla(collaName);
    }

    List<CastellerDTO^>^ CtrlAssignarCastellers::CarregarCastellers(String^ collaName)
    {
        return PasarelaMuntatgeCastell::obtenirCastellersPerColla(collaName);
    }

    bool CtrlAssignarCastellers::Assignar(
        int castellId,
        String^ collaName,
        List<PosicioCastellDTO^>^ posicions,
        String^% error
    )
    {
        if (String::IsNullOrEmpty(collaName)) {
            error = "No s'ha pogut identificar la colla.";
            return false;
        }

        if (castellId <= 0) {
            error = "Selecciona un castell valid.";
            return false;
        }

        if (!validarSenseDuplicats(posicions, error)) {
            return false;
        }

        return PasarelaMuntatgeCastell::guardarAssignacions(castellId, collaName, posicions, error);
    }

    bool CtrlAssignarCastellers::validarSenseDuplicats(List<PosicioCastellDTO^>^ posicions, String^% error)
    {
        List<String^>^ vistos = gcnew List<String^>();

        for each(PosicioCastellDTO ^ p in posicions) {
            if (String::IsNullOrEmpty(p->castellerDni)) {
                continue;
            }

            if (vistos->Contains(p->castellerDni)) {
                error = "Un mateix casteller no pot ocupar dues posicions al mateix castell.";
                return false;
            }

            vistos->Add(p->castellerDni);
        }

        return true;
    }
}
