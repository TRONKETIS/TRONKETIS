#pragma once

#include "ParticipantDiadaDTO.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Tronketis {

	public ref class CtrlResumAssistenciaDiada
	{
	public:
		static List<ParticipantDiadaDTO^>^ obtenirParticipants(String^ nomDiada, DateTime dataDiada);
	};
}