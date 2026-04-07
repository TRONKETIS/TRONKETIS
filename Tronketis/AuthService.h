#pragma once

#include "CercadorUsuari.h"

using namespace System;

public ref class AuthService
{
public:
    static bool Login(String^ email, String^ inputPass, String^% rol)
    {
        String^ dbPass;

        bool exists = CercadorUsuari::CercaPerEmail(email, dbPass, rol);

        if (!exists)
            return false;

        if (dbPass != inputPass)
            return false;

        return true;
    }
};