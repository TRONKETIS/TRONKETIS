#pragma once

#include "CastellDTO.h"

using namespace System;

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
        String^ getColla();
    };

}
