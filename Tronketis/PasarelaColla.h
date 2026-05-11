#pragma once
#include "CollaDTO.h"
using namespace System;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    public ref class PasarelaColla {
    public:

        static bool insertar(CollaDTO^ colla, String^% error);

        static bool existeixNom(String^ nom);

        static CollaDTO^ obtenirPerId(int id);

        static bool actualitzar(CollaDTO^ colla, String^% error);
    };

}