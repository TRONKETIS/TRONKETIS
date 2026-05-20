#pragma once

using namespace System;

namespace Tronketis {

    public ref class UsuariDTO {
    public:
        String^ dni;
        String^ username;
        String^ email;
        String^ password;
        String^ rol;
    };
}
