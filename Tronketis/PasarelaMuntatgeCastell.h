#pragma once

#include "CastellDTO.h"
#include "CastellerDTO.h"
#include "PosicioCastellDTO.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Tronketis {

    public ref class PasarelaMuntatgeCastell
    {
    public:
        static List<CastellDTO^>^ obtenirCastellsPerColla(String^ collaName);
        static List<CastellerDTO^>^ obtenirCastellersPerColla(String^ collaName);
        static List<PosicioCastellDTO^>^ obtenirAssignacions(int castellId, String^ collaName);

        static bool guardarAssignacions(
            int castellId,
            String^ collaName,
            List<PosicioCastellDTO^>^ posicions,
            String^% error
        );
    };
}
