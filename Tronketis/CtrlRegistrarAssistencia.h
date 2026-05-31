#pragma once

#include "ParticipacioDiadaDTO.h"

using namespace System;

namespace Tronketis {

    public ref class CtrlRegistrarAssistencia
    {
    public:

        static bool executar(
            ParticipacioDiadaDTO^ dto,
            String^% error
        );
    };

}
