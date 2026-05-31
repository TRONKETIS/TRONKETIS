#pragma once

#include "DB.h"
#include "PasarelaCastell.h"
#include "CastellDTO.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    public ref class CercadorAssignacioCastellDiada
    {
    public:
        static bool existeixAssignacio(String^ diadaName,
            DateTime dateDiada,
            int castellId,
            String^ collaName);

        static List<PasarelaCastell^>^ obtenirCastellsAssignats(String^ diadaName,
            DateTime dateDiada,
            String^ collaName);
    };

}