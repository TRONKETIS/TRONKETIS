#include "pch.h"

#include "CtrlResumAssistenciaDiada.h"
#include "CercadorAssistenciaDiada.h"

namespace Tronketis {

	List<ParticipantDiadaDTO^>^ CtrlResumAssistenciaDiada::obtenirParticipants(String^ nomDiada, DateTime dataDiada)
	{
		return CercadorAssistenciaDiada::obtenirParticipants(nomDiada, dataDiada);
	}
}