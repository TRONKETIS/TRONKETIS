#pragma once

#include "AssaigDTO.h"

namespace Tronketis {

	using namespace System;

	public ref class CtrlCrearAssaig
	{
	public:
		static String^ CrearAssaig(DateTime data_hora, String^ colla_name, String^ colla_uni_name);
	};
}
