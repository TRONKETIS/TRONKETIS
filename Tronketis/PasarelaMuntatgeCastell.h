#pragma once
#include "MembreDTO.h"
#include "PosicioCastellDTO.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    public ref class PasarelaMuntatgeCastell {
    public:
        // Retorna els membres de la colla (taula membre_colla)
        static List<MembreDTO^>^ obtenirMembresPerColla(int collaId);

        // Retorna les assignacions ja guardades per a aquest castell+colla
        static List<PosicioCastellDTO^>^ obtenirAssignacionsExistents(int castellId, int collaId);

        // Desa les assignacions (DELETE + INSERT en transaccio)
        static bool guardarAssignacions(int castellId, int collaId,
            List<PosicioCastellDTO^>^ posicions, String^% error);
    };

}
