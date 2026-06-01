#pragma once
#include "PasarelaUsuari.h"
#include "PasarelaColla.h"

using namespace Tronketis;
using namespace System;
using namespace System::Collections::Generic; // 🔹 ESTO ES NECESARIO PARA USAR 'List'

public ref class CtrlAdminMenu
{
public:

    static void IrARegistrarUsuario()
    {

    }

    static bool InhabilitarUsuario(String^ dni)
    {
        return PasarelaUsuari::Inhabilitar(dni);
    }

    // 🔹 MÉTODOS AÑADIDOS QUE FALTABAN PARA QUE EL FORMULARIO FUNCIONE:

    static List<CollaDTO^>^ ObtenerListaCollas()
    {
        return PasarelaColla::obtenerTodas();
    }

    static List<UsuariDTO^>^ ObtenerListaUsuarios()
    {
        return PasarelaUsuari::obtenirTots();
    }

    // ------------------------------------------------------------------

    static bool AsignarCapDeColla(String^ nombreColla, String^ dniUsuario, String^ telefon, String^% error)
    {
        return PasarelaColla::asignarCapDeColla(nombreColla, dniUsuario, telefon, error);
    }
};