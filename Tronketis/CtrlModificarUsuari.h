#pragma once

#include "UsuariDTO.h"
#include "CercadorUsuari.h"
#include "PasarelaUsuari.h"

using namespace System;

namespace Tronketis {

    public ref class CtrlModificarUsuari {
    public:
        bool modificar(UsuariDTO^ u, String^% error);
    };
}
