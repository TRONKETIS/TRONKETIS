#pragma once
#include "EventoDTO.h"
using namespace System::Collections::Generic;
using namespace System;

namespace Tronketis {

	public ref class CercadorEvento
	{
	public:
		static List<EventoDTO^>^ obtenirEventsPerMes(int month, int year);
	};
}