#pragma once

#include "DB.h"


public ref class PasarelaMembre
{
public:
    static bool insertar(System::String^ dni,
        System::String^ collaName,
        System::String^ uniName,
        System::DateTime joinDate);
};


