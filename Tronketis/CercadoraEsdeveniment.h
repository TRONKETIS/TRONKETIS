#pragma once

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace Tronketis {

    public ref class CercadoraEsdeveniment {
    public:
        // Mètode que comprovarà si la combinació nom+data ja existeix a la DB
        bool existeixDiada(String^ name, String^ date);
    };
}