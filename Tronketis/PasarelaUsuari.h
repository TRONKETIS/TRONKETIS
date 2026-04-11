#pragma once

#include "DB.h"
#include "UsuariDTO.h"

using namespace Tronketis;

using namespace System;
using namespace MySql::Data::MySqlClient;

public ref class PasarelaUsuari
{
public:
    static void insertar(UsuariDTO^ u);
	static bool modificarUsuari(UsuariDTO^ u);
};