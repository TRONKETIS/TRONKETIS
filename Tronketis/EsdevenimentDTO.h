#pragma once

using namespace System;

namespace Tronketis {

    public ref class EsdevenimentDTO {
    public:
        int id;
        String^ name;
        String^ date;
        String^ location;
        String^ description;
        String^ tipus;
    };
}