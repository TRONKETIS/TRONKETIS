#pragma once

#include "PasarelaCastell.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace Tronketis;

ref class CtrlConsultarCastell
{
public:

    List<PasarelaCastell^>^
        consultarPerNom(String^ nom);
};
