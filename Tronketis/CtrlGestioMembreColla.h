#pragma once

#include "CercadorMembre.h"
#include "PasarelaMembre.h"
#include "CercadorUsuari.h"
#include "CercadorColla.h"

namespace Tronketis {
	using namespace System;

	public ref class CtrlGestioMembreColla
	{
	public:
		static bool afegirMembre(String^ dni, String^ collaName, String^% error);
		static bool eliminarMembre(String^ dni, String^ collaName, String^% error);
	};
}