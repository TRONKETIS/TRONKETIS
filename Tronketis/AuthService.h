#pragma once

using namespace System;

public ref class AuthService
{
public:
    static bool Login(String^ email, String^ inputPass, String^% rol);
};
