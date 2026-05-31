#pragma once
#include "pch.h"

using namespace System;

namespace Tronketis {

	public ref class AssaigDTO
	{
	public:
		property int Id;
		property DateTime DataHora;
		property String^ CollaName;
		property String^ CollaUniName;

		AssaigDTO()
		{
			Id = 0;
			DataHora = DateTime::Now;
			CollaName = "";
			CollaUniName = "";
		}

		AssaigDTO(int id, DateTime data_hora, String^ colla_name, String^ colla_uni_name)
		{
			Id = id;
			DataHora = data_hora;
			CollaName = colla_name;
			CollaUniName = colla_uni_name;
		}

	};
}

