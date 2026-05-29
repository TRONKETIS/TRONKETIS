#pragma once
using namespace System;

namespace Tronketis {

    public ref class PosicioCastellDTO {
    public:
        property int     numPis;
        property int     numPosicio;
        property String^ castellerDni;   // nullptr = sense assignar
        property String^ castellerNom;

        PosicioCastellDTO() {
            numPis = 0; numPosicio = 0;
            castellerDni = nullptr; castellerNom = nullptr;
        }
    };

}
