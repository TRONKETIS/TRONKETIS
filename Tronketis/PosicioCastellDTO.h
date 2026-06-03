#pragma once

using namespace System;

namespace Tronketis {

    public ref class PosicioCastellDTO
    {
    public:
        int numPis;
        int numPosicio;
        String^ castellerDni;
        String^ castellerNom;

        PosicioCastellDTO()
        {
            numPis = 0;
            numPosicio = 0;
            castellerDni = nullptr;
            castellerNom = nullptr;
        }
    };
}
