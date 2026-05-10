#pragma once

#include "ParticipacioDiadaDTO.h"

using namespace System;

namespace Tronketis {

    public ref class PasarelaParticipacioDiada
    {
    public:

        static bool registrar(
            ParticipacioDiadaDTO^ dto,
            String^% error
        );

        static bool actualitzarEstat(
            ParticipacioDiadaDTO^ dto,
            String^% error
        );

        static bool existeix(
            String^ diadaName,
            DateTime dateDiada,
            String^ dni
        );
    };

}
