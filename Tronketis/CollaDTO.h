#pragma once
using namespace System;

namespace Tronketis {

    public ref class CollaDTO {
    public:
        property int id;
        property String^ nom;
        property cli::array<Byte>^ logo;
        property String^ localitzacio;
        property String^ univ;
        property bool actiu;

        CollaDTO() {
            id = 0;
            actiu = true;
            univ = nullptr;
            logo = nullptr;
        }
    };

}