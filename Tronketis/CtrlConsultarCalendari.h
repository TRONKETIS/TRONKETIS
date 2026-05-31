#pragma once

#include "CercadorEvento.h"
#include "CercadorDiada.h"
#include "CercadorAssaig.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Tronketis {

	public ref class CtrlConsultarCalendari
	{
	public:
		static List<String^>^ obtenirActivitatsDelDia(DateTime dataSeleccionada, String^ rol, String^ collaName);
	};
}