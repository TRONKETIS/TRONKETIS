#pragma once

using namespace System;

ref class CtrlIniciarSesion
{
public:
    static bool Execute(String^ email, String^ password, String^% dni, String^% rol);
};