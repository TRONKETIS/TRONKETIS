#pragma once
using namespace System;

namespace Tronketis {

	public ref class EventoDTO {
	public:
		property String^ EvName;
		property DateTime EvDate;
		property String^ Location;
		property int AproxMem;

		EventoDTO() {
			EvName = "";
			EvDate = DateTime::Now;
			Location = "";
			AproxMem = 0;
		}
	};
}