#pragma once

#include "CercadorMembre.h"
#include "PasarelaMembre.h"
#include "CercadorUsuari.h"

namespace Tronketis {
	using namespace System;

	public ref class CtrlAfegirMembreColla
	{
	public:
		static bool afegirMembre(String^ dni, String^ collaName, String^ uniName, String^% error);
	};
}



