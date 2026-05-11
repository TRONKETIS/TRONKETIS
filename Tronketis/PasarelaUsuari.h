#pragma once

#include "DB.h"
#include "UsuariDTO.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

namespace Tronketis {

    public ref class PasarelaUsuari
    {
    public:
        static void insertar(UsuariDTO^ u);
        static bool Inhabilitar(String^ dni);
    };

}
public ref class PasarelaUsuari
{
public:
    static void insertar(UsuariDTO^ u);
	static bool modificarUsuari(UsuariDTO^ u);
};