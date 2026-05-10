#pragma once

#include "EsdevenimentDTO.h"
#include "PassarellaEsdeveniment.h"

namespace Tronketis {

    public ref class CtrlCrearEsdeveniment {
    public:
        static void crearEsdeveniment(EsdevenimentDTO^ e);
    };
}