#pragma once
#include "CastellerDTO.h"
#include "PosicioCastellDTO.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    public ref class PasarelaMuntatgeCastell {
    public:
        // Castellers de la colla (JOIN casteller + usuari + membre + colla)
        static List<CastellerDTO^>^ obtenirCastellersPerColla(int collaId);

        // Assignacions ja guardades per a aquest castell+colla
        static List<PosicioCastellDTO^>^ obtenirAssignacions(int castellId, int collaId);

        // Desa assignacions (DELETE + INSERT en transaccio)
        static bool guardarAssignacions(int castellId, int collaId,
            List<PosicioCastellDTO^>^ posicions, String^% error);
    };

}
