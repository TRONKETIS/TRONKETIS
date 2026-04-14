#pragma once

#include "DB.h"
#include "UsuariDTO.h"

using namespace Tronketis;

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    public ref class PasarelaUsuari
    {
    public:
        static void insertar(UsuariDTO^ u);
        static bool Inhabilitar(String^ dni);
    };

}