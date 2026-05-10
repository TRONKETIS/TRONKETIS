#pragma once

namespace Tronketis {
    public ref class CercadoraEsdeveniment {
    public:
        // Mètode que comprovarà si la combinació nom+data ja existeix a la DB
        bool existeixDiada(System::String^ name, System::String^ date);
    };
}