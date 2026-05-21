#pragma once
#include "CercadorColla.h"
using namespace System;
using namespace System::Collections::Generic;

public ref class CtrlInhabilitarColla
{
public:
    static List<String^>^ obtenirCollesActives()
    {
        return CercadorColla::obtenirNomsColles();
    }

    static bool inhabilitar(String^ nomColla, String^% error)
    {
        if (nomColla == nullptr || nomColla->Trim() == "")
        {
            error = "Introdueix o selecciona una colla.";
            return false;
        }

        if (!CercadorColla::InhabilitarColla(nomColla))
        {
            error = "No s'ha trobat cap colla amb aquest nom.";
            return false;
        }

        error = "";
        return true;
    }
};