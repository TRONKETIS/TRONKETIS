#pragma once

#include "DB.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

public ref class CercadorColla
{
public:
    static bool InhabilitarColla(int idColla);
};