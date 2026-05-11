#pragma once
using namespace System;

namespace Tronketis {

    public ref class PosicioCastellDTO {
    public:
        property int     id;
        property int     castellId;
        property int     collaId;
        property int     numPis;        // 1 = pinya (baix), N = cim (dalt)
        property int     numPosicio;    // 1..N dins del pis
        property String^ membreDni;     // nullptr = sense assignar
        property String^ membreNom;

        PosicioCastellDTO() {
            id = 0; castellId = 0; collaId = 0;
            numPis = 0; numPosicio = 0;
            membreDni = nullptr; membreNom = nullptr;
        }
    };

}
