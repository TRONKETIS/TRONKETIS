#include "pch.h"
#include "CtrlRegistrarUsuari.h"

namespace Tronketis {

    bool CtrlRegistrarUsuari::registrar(UsuariDTO^ u, String^% error) {

        // 🔹 1. Validaciones básicas
        if (u->dni == "" || u->username == "" ||
            u->email == "" || u->password == "" ||
            u->rol == "") {

            error = "Todos los campos son obligatorios";
            return false;
        }

        // 🔹 Email válido
        if (!u->email->Contains("@")) {
            error = "Email no válido";
            return false;
        }

        // 🔹 Password mínima
        if (u->password->Length < 4) {
            error = "La contrasenya es demasiado corta";
            return false;
        }

        // 🔹 2. Comprobar duplicados
        //CercadorUsuari^ cercador = gcnew CercadorUsuari();

        if (CercadorUsuari::existeEmail(u->email)) {
            error = "El email ya esta registrado";
            return false;
        }

        if (CercadorUsuari::existeDni(u->dni)) {
            error = "El DNI ya esta registrado";
            return false;
        }

        // 🔹 3. Insertar usuario
        PasarelaUsuari::insertar(u);

        return true;
    }
}