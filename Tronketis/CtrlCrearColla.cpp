#include "pch.h"
#include "CtrlCrearColla.h"
#include "PasarelaColla.h"
#include "PasarelaUsuari.h"
using namespace System;
using namespace System::Collections::Generic;
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

    bool CtrlCrearColla::CrearAmbCap(int usuariId, CollaDTO^ colla, String^ dniCap, String^ telefon, String^% error) {

        if (!validarDadesColla(colla, error)) {
            return false;
        }

        if (String::IsNullOrWhiteSpace(dniCap)) {
            error = "Has de seleccionar un cap de colla";
            return false;
        }

        colla->nom = colla->nom->Trim();
        colla->localitzacio = colla->localitzacio->Trim();
        if (colla->univ != nullptr) {
            colla->univ = colla->univ->Trim();
        }
        if (telefon != nullptr) {
            telefon = telefon->Trim();
        }

        try {
            return PasarelaColla::insertarConCap(colla, dniCap, telefon, error);
        }
        catch (Exception^ ex) {
            error = "Error de base de dades: " + ex->Message;
            return false;
        }
    }

    List<UsuariDTO^>^ CtrlCrearColla::ObtenirCapsDisponibles() {
        return PasarelaUsuari::obtenirTots();
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