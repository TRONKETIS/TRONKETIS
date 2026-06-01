#include "pch.h"
#include "CtrlCrearCastell.h"
#include "PasarelaCastell.h"
#include "CercadorCastell.h"
using namespace System;
using namespace Tronketis;

namespace Tronketis {

    bool CtrlCrearCastell::Crear(CastellDTO^ castell, String^% error) {

        if (!validarDades(castell, error)) return false;

        castell->nom = castell->nom->Trim();
        castell->colla = castell->colla->Trim();

        if (!nomDisponible(castell->nom, castell->colla, error)) return false;

        try {
            return PasarelaCastell::insertar(castell, error);
        }
        catch (Exception^ ex) {
            error = "Error de base de dades: " + ex->Message;
            return false;
        }
    }

    bool CtrlCrearCastell::validarDades(CastellDTO^ castell, String^% error) {

        if (castell == nullptr) {
            error = "No s'han rebut les dades del castell";
            return false;
        }

        if (String::IsNullOrWhiteSpace(castell->colla)) {
            error = "No s'ha pogut obtenir la colla del cap de colla";
            return false;
        }
        if (castell->colla->Trim()->Length > 20) {
            error = "El nom de la colla no pot superar els 20 caracters";
            return false;
        }
        if (String::IsNullOrWhiteSpace(castell->nom)) {
            error = "El nom del castell es obligatori";
            return false;
        }
        if (castell->nom->Trim()->Length > 100) {
            error = "El nom no pot superar els 100 caracters";
            return false;
        }
        if (String::IsNullOrWhiteSpace(castell->tipus)) {
            error = "El tipus del castell es obligatori";
            return false;
        }

        int min = minPisos(castell->tipus);
        if (castell->pisos < min || castell->pisos > 10) {
            error = String::Format("El nombre de pisos ha de ser entre {0} i 10", min);
            return false;
        }

        return true;
    }

    bool CtrlCrearCastell::nomDisponible(String^ nom, String^ colla, String^% error) {
        try {
            List<PasarelaCastell^>^ resultats =
                CercadorCastell::cercaPerNomIColla(nom->Trim(), colla->Trim());

            if (resultats->Count > 0) {
                error = "Ja existeix un castell amb aquest nom en aquesta colla";
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
