#pragma once
using namespace System;

namespace Tronketis {

    public ref class CastellDTO {
    public:
        property int id;
        property String^ nom;
        property String^ tipus;     // "2d", "3d", "4d", "pilar"
        property int numPisos;

        CastellDTO() {
            id = 0;
            numPisos = 0;
            nom = nullptr;
            tipus = nullptr;
        }
    };

}
