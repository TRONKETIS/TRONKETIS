#pragma once
#include "CastellDTO.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    public ref class PasarelaCastell {
    public:
        static bool insertar(CastellDTO^ castell, String^% error);
        static bool existeixNom(String^ nom);
        static List<CastellDTO^>^ obtenirTots();
        static CastellDTO^ obtenirPerId(int id);
    };

}
