#pragma once

#include "CercadorAssignacioCastellDiada.h"
#include "PasarelaAssignacioCastellDiada.h"
#include "CercadorColla.h"

using namespace System;

namespace Tronketis {

    public ref class CtrlAssignarCastellDiada
    {
    public:
        static bool assignarCastell(String^ diadaName,
            DateTime dateDiada,
            int castellId,
            String^ collaName,
            String^% error);
    };

}
