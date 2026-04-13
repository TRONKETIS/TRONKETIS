#pragma once

#include "DB.h"
#include "EsdevenimentDTO.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    public ref class PassarellaEsdeveniment
    {
    public:
        static void insertar(EsdevenimentDTO^ e);
    };

}