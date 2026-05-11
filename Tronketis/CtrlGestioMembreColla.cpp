#include "pch.h"
#include "CtrlGestioMembreColla.h"

using namespace System;

bool Tronketis::CtrlGestioMembreColla::afegirMembre(String^ dni,
	String^ collaName,
	String^% error)
{
	bool correcte = false;
	error = "";

	if (String::IsNullOrWhiteSpace(dni)) {
		error += "Has de seleccionar un casteller.\n";
	}

	if (String::IsNullOrWhiteSpace(collaName)) {
		error += "Has de seleccionar una colla.\n";
	}

	if (error == "") {
		String^ uniName = "";

		if (!CercadorUsuari::existeDni(dni)) {
			error = "El usuario no existe.";
		}
		else if (!CercadorColla::obtenirUniPerNomColla(collaName, uniName)) {
			error = "La colla seleccionada no existe o no tiene universidad asociada.";
		}
		else if (CercadorMembre::existeixMembre(dni, collaName, uniName)) {
			error = "El miembro ya pertenece a esta colla.";
		}
		else if (CercadorMembre::teAlgunaColla(dni)) {
			error = "El miembro ya pertenece a alguna colla.";
		}
		else {
			correcte = PasarelaMembre::insertar(dni, collaName, uniName, DateTime::Now);

			if (!correcte) {
				error = "No se ha podido añadir el miembro a la colla.";
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