#pragma once

#include "AssaigDTO.h"

namespace Tronketis {

	using namespace System;
	using namespace System::Collections::Generic;
	public ref class PasarelaAssaig
	{
	public:
		static bool InsertarAssaig(AssaigDTO^ assaig);
		static List<AssaigDTO^>^ GetAssaigsDeColla(String^ colla_name, String^ colla_uni_name);

	};
}
