#include "pch.h"
#include "CtrlConsultarAssaig.h"
#include "PasarelaAssaig.h"

namespace Tronketis {
    List<AssaigDTO^>^ CtrlConsultarAssaig::ConsultarAssaigs(String^ colla_name, String^ colla_uni_name)
    {
        if (String::IsNullOrWhiteSpace(colla_name) || String::IsNullOrWhiteSpace(colla_uni_name))
        {
            return gcnew List<AssaigDTO^>();
        }
        return PasarelaAssaig::GetAssaigsDeColla(colla_name, colla_uni_name);
    }
}