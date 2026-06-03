#include "pch.h"
#include "CtrlModificarUsuari.h"


bool Tronketis::CtrlModificarUsuari::modificar(UsuariDTO^ u, String^% error) {

    if (u->username->Length == 0) {
        error = "El nom no pot estar buit";
        return false;
    }

    if (!u->email->Contains("@")) {
        error = "El correu no és vàlid";
        return false;
    }

    if (u->rol != "Casteller" &&
        u->rol != "Administrador" &&
        u->rol != "CapColla") {
        error = "Rol no vàlid";
        return false;
    }

    UsuariDTO^ original = CercadorUsuari::buscaPorDNI(u->dni);

    if (original == nullptr) {
        error = "No s'ha trobat l'usuari original";
        return false;
    }

    if (u->email != original->email && CercadorUsuari::existeEmail(u->email)) {
        error = "Aquest email ja està registrat";
        return false;
    }

    PasarelaUsuari pas;
    bool ok = pas.modificarUsuari(u);

    if (!ok) {
        error = "Error actualitzant a la base de dades";
        return false;
    }

    return true;
}

