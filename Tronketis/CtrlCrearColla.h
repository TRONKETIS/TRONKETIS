#pragma once
#include "CollaDTO.h"
using namespace System;

namespace Tronketis {

    public ref class CtrlCrearColla {
    public:
        static bool Crear(int usuariId, CollaDTO^ colla, String^% error);

    private:
        static bool validarDadesColla(CollaDTO^ colla, String^% error);
        static bool nomCollaDisponible(String^ nom, String^% error);
    };

}