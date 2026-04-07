#pragma once

#include "UsuariDTO.h"
#include "CercadorUsuari.h"
#include "PasarelaUsuari.h"

using namespace System;

namespace Tronketis {

    public ref class CtrlRegistrarUsuari {
    public:
        bool registrar(UsuariDTO^ u, String^% error);
    };
}