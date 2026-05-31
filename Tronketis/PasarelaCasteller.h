#pragma once

#include "DB.h"
#include "CastellerDTO.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

namespace Tronketis {

    public ref class PasarelaCasteller
    {
    public:

        static void insertar(CastellerDTO^ c);
    };

}