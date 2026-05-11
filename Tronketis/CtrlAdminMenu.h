#pragma once
#include "PasarelaUsuari.h"

using namespace Tronketis;
using namespace System;

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
};
