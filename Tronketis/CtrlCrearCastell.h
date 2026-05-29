#pragma once
#include "CastellDTO.h"
using namespace System;

namespace Tronketis {

    public ref class CtrlCrearCastell {
    public:
        static bool Crear(int collaId, CastellDTO^ castell, String^% error);

    private:
        static bool validarDades(CastellDTO^ castell, String^% error);
        static bool nomDisponible(String^ nom, String^% error);
        static int minPisos(String^ tipus);
    };

}
