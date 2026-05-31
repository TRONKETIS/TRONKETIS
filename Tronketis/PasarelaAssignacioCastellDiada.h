#pragma once

#include "DB.h"

using namespace System;

namespace Tronketis {

    public ref class PasarelaAssignacioCastellDiada
    {
    public:
        static bool inserir(String^ diadaName,
            DateTime dateDiada,
            int castellId,
            String^ collaName,
            String^ uniName,
            String^% error);
    };

}
