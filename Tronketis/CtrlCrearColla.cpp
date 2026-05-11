#include "pch.h"
#include "CtrlCrearColla.h"
#include "PasarelaColla.h"
using namespace System;
using namespace Tronketis;

namespace Tronketis {

    bool CtrlCrearColla::Crear(int usuariId, CollaDTO^ colla, String^% error) {

        // 🔹 1. Validar dades de la colla
        if (!validarDadesColla(colla, error)) {
            return false;
        }

        // 🔹 2. Comprovar que el nom no estigui repetit
        if (!nomCollaDisponible(colla->nom, error)) {
            return false;
        }

        // 🔹 3. Normalitzar dades
        colla->nom = colla->nom->Trim();
        colla->localitzacio = colla->localitzacio->Trim();

        // 🔹 4. Inserir a la base de dades
        try {
            return PasarelaColla::insertar(colla, error);
        }
        catch (Exception^ ex) {
            error = "Error de base de dades: " + ex->Message;
            return false;
        }
    }

    bool CtrlCrearColla::validarDadesColla(CollaDTO^ colla, String^% error) {

        // Camps obligatoris
        if (String::IsNullOrWhiteSpace(colla->nom)) {
            error = "El nom de la colla és obligatori";
            return false;
        }
        if (String::IsNullOrWhiteSpace(colla->localitzacio)) {
            error = "La localització és obligatòria";
            return false;
        }

        // Longituds màximes
        if (colla->nom->Length > 100) {
            error = "El nom no pot superar els 100 caràcters";
            return false;
        }
        if (colla->localitzacio->Length > 200) {
            error = "La localització no pot superar els 200 caràcters";
            return false;
        }

        // Validar mida del logo (màx 5MB)
        if (colla->logo != nullptr && colla->logo->Length > 5 * 1024 * 1024) {
            error = "El logo no pot superar els 5MB";
            return false;
        }

        return true;
    }

    bool CtrlCrearColla::nomCollaDisponible(String^ nom, String^% error) {
        try {
            if (PasarelaColla::existeixNom(nom)) {
                error = "Ja existeix una colla amb aquest nom";
                return false;
            }
            return true;
        }
        catch (Exception^ ex) {
            // 🔹 Mostra l'error real per depurar
            error = "Error comprovant la disponibilitat del nom: " + ex->Message;
            return false;
        }
    }

}