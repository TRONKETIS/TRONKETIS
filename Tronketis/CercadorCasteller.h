#pragma once

#include "CastellerDTO.h"

using namespace System::Collections::Generic;

namespace Tronketis {

    public ref class CercadorCasteller
    {
    public:

        static List<CastellerDTO^>^ obtenirTots();
    };

}
