#pragma once
#include "CastellerDTO.h"
#include "PosicioCastellDTO.h"
using namespace System;
using namespace System::Collections::Generic;

namespace Tronketis {

    public ref class CtrlAssignarCastellers {
    public:
        static List<CastellerDTO^>^ CarregarCastellers(int collaId);

        static bool Assignar(int castellId, int collaId,
            List<PosicioCastellDTO^>^ posicions, String^% error);

    private:
        static bool validarSenseDuplicats(List<PosicioCastellDTO^>^ posicions, String^% error);
    };

}
