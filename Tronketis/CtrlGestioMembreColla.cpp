#include "pch.h"
#include "CtrlGestioMembreColla.h"

using namespace System;

bool Tronketis::CtrlGestioMembreColla::afegirMembre(String^ dni,
    String^ collaName,
    String^ uniName,
    String^% error)
{
	bool correcte = false;
	error = "";

	if (String::IsNullOrWhiteSpace(dni)) {
		error += "El DNI no puede estar vacio.\n";
	}

	if (String::IsNullOrWhiteSpace(collaName)) {
		error += "El nombre de la colla no puede estar vacio.\n";
	}

	if (String::IsNullOrWhiteSpace(uniName)) {
		error += "El nombre de la universidad no puede estar vacio.\n";
	}

	if (error == "") {
		if (!CercadorUsuari::existeDni(dni)) {
			error = "El usuario no existe";
		}
		else if (CercadorMembre::existeixMembre(dni, collaName, uniName)) {
			error = "El miembro ya pertenece a esta colla";
		}
		else if (CercadorMembre::teAlgunaColla(dni)) {
			error = "El miembro ya pertenece a alguna colla";
		}
		else {
			correcte = PasarelaMembre::insertar(dni, collaName, uniName, DateTime::Now);

			if (!correcte) {
				error = "Error al insertar el miembro en la colla";
			}
		}
	}

	return correcte;
}

bool Tronketis::CtrlGestioMembreColla::eliminarMembre(String^ dni, String^% error)
{
    bool correcte = false;
    error = "";

    if (String::IsNullOrWhiteSpace(dni)) {
        error = "El DNI no puede estar vacio";
    }
    else if (!CercadorMembre::existeixMembre(dni)) {
        error = "El usuario no pertenece a ninguna colla";
    }
    else {
        correcte = PasarelaMembre::eliminarMembre(dni);

        if (!correcte) {
            error = "Error al eliminar el miembro de la colla";
        }
    }

    return correcte;
}