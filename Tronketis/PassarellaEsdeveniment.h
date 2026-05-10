#pragma once

#include "DB.h"
#include "EsdevenimentDTO.h"

namespace Tronketis {

    public ref class PassarellaEsdeveniment
    {
    public:
        static void insertar(EsdevenimentDTO^ e);
    };

}