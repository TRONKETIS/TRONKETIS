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

        int getId();
        String^ getNom();
        int getPisos();
        String^ getTipus();
    };

}
