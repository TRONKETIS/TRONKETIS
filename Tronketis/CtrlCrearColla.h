#pragma once
#include "CollaDTO.h"
#include "UsuariDTO.h"
using namespace System;
using namespace System::Collections::Generic;

namespace Tronketis {

    public ref class CtrlCrearColla {
    public:
        static bool Crear(int usuariId, CollaDTO^ colla, String^% error);
        static bool CrearAmbCap(int usuariId, CollaDTO^ colla, String^ dniCap, String^ telefon, String^% error);
        static List<UsuariDTO^>^ ObtenirCapsDisponibles();

    private:
        static bool validarDadesColla(CollaDTO^ colla, String^% error);
        static bool nomCollaDisponible(String^ nom, String^% error);
    };

}