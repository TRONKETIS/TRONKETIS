#pragma once

namespace Tronketis {

    public ref class EsdevenimentDTO {
    public:
        int id;
        System::String^ name;
        System::String^ date;
        System::String^ location;
        System::String^ description;
        System::String^ tipus;
    };
}