#pragma once

#include "DiadaDTO.h"

using namespace System::Collections::Generic;

namespace Tronketis {

    public ref class CercadorDiada
    {
    public:
        static List<DiadaDTO^>^ obtenirTotes();
        static List<DiadaDTO^>^ obtenirDiadesPerMes(int month, int year);
        static List<DiadaDTO^>^ obtenirDiadesDisponibles();
    };

}