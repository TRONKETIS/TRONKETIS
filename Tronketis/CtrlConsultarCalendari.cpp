#include "pch.h"
#include "CtrlConsultarCalendari.h"

namespace Tronketis {

	List<String^>^ CtrlConsultarCalendari::obtenirActivitatsDelDia(DateTime dataSeleccionada, String^ rol, String^ collaName)
	{
		List<String^>^ resultats = gcnew List<String^>();
		int month = dataSeleccionada.Month;
		int year = dataSeleccionada.Year;

		// 1. EVENTOS (para todo el mundo)
		List<EventoDTO^>^ eventosMes = CercadorEvento::obtenirEventsPerMes(month, year);
		for each (EventoDTO^ ev in eventosMes)
		{
			if (ev->EvDate.Date == dataSeleccionada.Date)
			{
				resultats->Add("[EVENT] " + ev->EvName + " (" + ev->EvDate.ToString("HH:mm") + ") - Lloc: " + ev->Location);
			}
		}

		// 2. DIADES (para todo el mundo)
		List<DiadaDTO^>^ diadesMes = CercadorDiada::obtenirDiadesPerMes(month, year);
		for each (DiadaDTO^ d in diadesMes)
		{
			if (d->data.Date == dataSeleccionada.Date)
			{
				resultats->Add("[DIADA] " + d->nom + " (" + d->data.ToString("HH:mm") + ") - Lloc: " + d->ubicacio);
			}
		}

		// 3. ASSAIGS (solo casteller y cap de colla)
		if (rol == "Casteller" || rol == "CapColla")
		{
			if (!String::IsNullOrEmpty(collaName))
			{
				List<AssaigDTO^>^ assaigsMes = CercadorAssaig::obtenirAssaigsPerMesIColla(month, year, collaName);
				for each (AssaigDTO^ as in assaigsMes)
				{
					if (as->DataHora.Date == dataSeleccionada.Date)
					{
						resultats->Add("[ASSAIG] Assaig de: " + as->CollaName + " (" + as->DataHora.ToString("HH:mm") + ")");
					}
				}
			}
		}

		return resultats;
	}
}