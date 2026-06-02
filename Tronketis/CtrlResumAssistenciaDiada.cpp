#include "pch.h"

#include "CtrlResumAssistenciaDiada.h"
#include "CercadorAssistenciaDiada.h"

namespace Tronketis {

	// Obté la llista de participants d'una diada concreta.
	// El controlador delega la cerca al CercadorAssistenciaDiada,
	// que és qui accedeix a les dades d'assistència.
	List<ParticipantDiadaDTO^>^ CtrlResumAssistenciaDiada::obtenirParticipants(String^ nomDiada, DateTime dataDiada)
	{
		// Retornem els participants trobats segons el nom i la data de la diada.
		return CercadorAssistenciaDiada::obtenirParticipants(nomDiada, dataDiada);
	}
}