#pragma once

using namespace System;

namespace Tronketis {

    public ref class UsuariDTO {
    public:
       property String^ dni;
       property String^ username;
        String^ email;
        String^ password;
        String^ rol;
    };
}