#pragma once
#include "AssaigDTO.h"
#include <vector>
namespace Tronketis {
    using namespace System;
    using namespace System::Collections::Generic;
    public ref class CtrlConsultarAssaig
    {
    public:
        static List<AssaigDTO^>^ ConsultarAssaigs(String^ colla_name, String^ colla_uni_name);
    };
}