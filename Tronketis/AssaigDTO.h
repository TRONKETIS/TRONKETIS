#pragma once
#include "pch.h"

using namespace System;

namespace Tronketis {
    public ref class AssaigDTO {
    public:
        int Id;
        DateTime DataHora;
        String^ CollaName;
        String^ CollaUniName;

        AssaigDTO() {
            Id = 0;
            DataHora = DateTime::Now;
            CollaName = "";
            CollaUniName = "";
        }

        AssaigDTO(int _id, DateTime _dataHora, String^ _collaName, String^ _collaUniName) {
            Id = _id;
            DataHora = _dataHora;
            CollaName = _collaName;
            CollaUniName = _collaUniName;
        }

    };
}

