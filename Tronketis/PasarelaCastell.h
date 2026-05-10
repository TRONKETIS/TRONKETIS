#pragma once

#include "CastellDTO.h"

using namespace System;
//using namespace System::Collections::Generic;
//using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    public ref class PasarelaCastell
    {
    private:

        CastellDTO^ dto;

    public:

        PasarelaCastell(CastellDTO^ dto);
        static bool insertar(CastellDTO^ castell, String^% error);
        int getId();
        String^ getNom();
        int getPisos();
        String^ getTipus();
    };

}
