#pragma once
using namespace System;

namespace Tronketis {

    public ref class MembreDTO {
    public:
        property String^ dni;
        property String^ nom;   // username de la taula usuari

        MembreDTO() { dni = nullptr; nom = nullptr; }
    };

}
