#include "pch.h"
#include "AuthService.h"
#include "CercadorUsuari.h"


bool AuthService::Login(String^ email, String^ inputPass, String^% rol)
{
    String^ dbPass;

    bool exists = CercadorUsuari::CercaPerEmail(email, dbPass, rol);

    if (!exists)
    {
        rol = "ERROR_EMAIL";
        return false;
    }

    if (dbPass != inputPass)
    {
        rol = "ERROR_PASSWORD";
        return false;
    }

    return true;
}
