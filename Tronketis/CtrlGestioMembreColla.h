#pragma once

#include "CercadorMembre.h"
#include "PasarelaMembre.h"
#include "CercadorUsuari.h"

namespace Tronketis {
	using namespace System;

	public ref class CtrlGestioMembreColla
	{
	public:
		static bool afegirMembre(String^ dni, String^ collaName, String^ uniName, String^% error);
		static bool eliminarMembre(String^ dni, String^% error);
	};
}



