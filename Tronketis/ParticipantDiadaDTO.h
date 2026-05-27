#pragma once

using namespace System;

namespace Tronketis {

	public ref class ParticipantDiadaDTO
	{
	public:
		property String^ dni;
		property String^ nomUsuari;
		property String^ estat;

		ParticipantDiadaDTO()
		{
			dni = "";
			nomUsuari = "";
			estat = "";
		}

		ParticipantDiadaDTO(String^ dni, String^ nomUsuari, String^ estat)
		{
			this->dni = dni;
			this->nomUsuari = nomUsuari;
			this->estat = estat;
		}
	};
}