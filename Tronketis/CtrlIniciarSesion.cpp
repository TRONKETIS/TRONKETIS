#include "pch.h"
#include "CtrlIniciarSesion.h"
#include "AuthService.h"

bool CtrlIniciarSesion::Execute(String^ email, String^ password, String^% dni, String^% rol)
{
    return AuthService::Login(email, password, dni, rol);
}
