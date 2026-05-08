#pragma once

#include "DB.h"

using namespace System;

public ref class PasarelaMembre
{
public:
    static bool insertar(String^ dni,
        String^ collaName,
        String^ uniName,
        DateTime joinDate);
};


