#include "pch.h"
#include "CtrlAssignarCastellDiada.h"

namespace Tronketis {

    bool CtrlAssignarCastellDiada::assignarCastell(String^ diadaName,
        DateTime dateDiada,
        int castellId,
        String^ collaName,
        String^% error)
    {
        bool correcte = false;
        error = "";

        if (String::IsNullOrWhiteSpace(diadaName)) {
            error += "Has de seleccionar una diada.\n";
        }

        if (castellId <= 0) {
            error += "Has de seleccionar un castell.\n";
        }

        if (String::IsNullOrWhiteSpace(collaName)) {
            error += "No hi ha cap colla assignada.\n";
        }

        if (error == "") {
            String^ uniName = "";

            if (!CercadorColla::obtenirUniPerNomColla(collaName, uniName)) {
                error = "No s'ha pogut obtenir la universitat de la colla.";
            }
            else if (CercadorAssignacioCastellDiada::existeixAssignacio(
                diadaName, dateDiada, castellId, collaName)) {
                error = "Aquest castell ja està assignat a aquesta diada.";
            }
            else {
                correcte = PasarelaAssignacioCastellDiada::inserir(
                    diadaName, dateDiada, castellId, collaName, uniName, error);

                if (!correcte && error == "") {
                    error = "No s'ha pogut assignar el castell a la diada.";
                }
            }
        }

        return correcte;
    }

}