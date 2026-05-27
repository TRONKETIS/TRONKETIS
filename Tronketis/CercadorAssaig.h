#pragma once
#include "AssaigDTO.h"
using namespace System::Collections::Generic;
using namespace System;

namespace Tronketis {

	public ref class CercadorAssaig
	{
	public:
		static List<AssaigDTO^>^ obtenirAssaigsPerMesIColla(int month, int year, String^ collaName);
	};
}