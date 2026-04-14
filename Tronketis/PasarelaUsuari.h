#pragma once

#include "DB.h"
#include "UsuariDTO.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

public ref class PasarelaUsuari
{
public:
    static void insertar(UsuariDTO^ u);
    static String^ obtenirRolUsuari(int usuariId);
    static bool esAdministrador(int usuariId);
};