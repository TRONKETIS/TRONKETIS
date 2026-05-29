#include "pch.h"
#include "CtrlCrearCastell.h"
#include "PasarelaCastell.h"
#include "CercadorCastell.h"
using namespace System;
using namespace Tronketis;

namespace Tronketis {

    bool CtrlCrearCastell::Crear(int collaId, CastellDTO^ castell, String^% error) {

        if (!validarDades(castell, error)) return false;
        if (!nomDisponible(castell->nom, error)) return false;

        castell->nom   = castell->nom->Trim();
        castell->colla = collaId;

        try {
            return PasarelaCastell::insertar(castell, error);
        }
        catch (Exception^ ex) {
            error = "Error de base de dades: " + ex->Message;
            return false;
        }
    }

    bool CtrlCrearCastell::validarDades(CastellDTO^ castell, String^% error) {

        if (String::IsNullOrWhiteSpace(castell->nom)) {
            error = "El nom del castell és obligatori";
            return false;
        }
        if (castell->nom->Length > 100) {
            error = "El nom no pot superar els 100 caràcters";
            return false;
        }
        if (String::IsNullOrWhiteSpace(castell->tipus)) {
            error = "El tipus del castell és obligatori";
            return false;
        }

        int min = minPisos(castell->tipus);
        if (castell->pisos < min || castell->pisos > 10) {
            error = String::Format("El nombre de pisos ha de ser entre {0} i 10", min);
            return false;
        }

        return true;
    }

    bool CtrlCrearCastell::nomDisponible(String^ nom, String^% error) {
        try {
            List<PasarelaCastell^>^ resultats =
                CercadorCastell::cercaPerNom(nom->Trim());

            if (resultats->Count > 0) {
                error = "Ja existeix un castell amb aquest nom";
                return false;
            }
            return true;
        }
        catch (Exception^ ex) {
            error = "Error comprovant disponibilitat del nom: " + ex->Message;
            return false;
        }
    }

    int CtrlCrearCastell::minPisos(String^ tipus) {
        return (tipus == "pilar") ? 3 : 4;
    }

}
