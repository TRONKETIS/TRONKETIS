#pragma once

#include "EsdevenimentDTO.h"
#include "PassarellaEsdeveniment.h"

using namespace System;

namespace Tronketis {

    public ref class CtrlCrearEsdeveniment {
    public:
        void crearEsdeveniment(EsdevenimentDTO^ e);
    };
}