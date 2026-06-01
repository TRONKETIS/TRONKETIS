#pragma once

#include "CastellDTO.h"
#include "CastellerDTO.h"
#include "PosicioCastellDTO.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Tronketis {

    public ref class CtrlAssignarCastellers
    {
    public:
        static List<CastellDTO^>^ CarregarCastells(String^ collaName);
        static List<CastellerDTO^>^ CarregarCastellers(String^ collaName);

        static bool Assignar(
            int castellId,
            String^ collaName,
            List<PosicioCastellDTO^>^ posicions,
            String^% error
        );

    private:
        static bool validarSenseDuplicats(List<PosicioCastellDTO^>^ posicions, String^% error);
    };
}
