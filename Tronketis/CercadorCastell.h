#pragma once

#include "DB.h"
#include "PasarelaCastell.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;
using namespace Tronketis;

public ref class CercadorCastell
{
public:

    static List<PasarelaCastell^>^ cercaPerNom(String^ nom);
    static List<PasarelaCastell^>^ cercaPerNomIColla(String^ nom, String^ colla);
    static List<PasarelaCastell^>^ obtenirTots();
    static List<PasarelaCastell^>^ obtenirPerColla(String^ colla);
};
