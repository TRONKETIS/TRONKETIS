#pragma once

#include "CercadorUsuari.h"

using namespace System;

public ref class AuthService
{
public:
    static bool Login(String^ email, String^ inputPass, String^% dni, String^% rol)
    {
        String^ dbPass;

        bool exists = CercadorUsuari::CercaPerEmailAmbDni(email, dni, dbPass, rol);

        if (!exists)
            return false;

        if (dbPass != inputPass)
            return false;

        return true;
    }
};