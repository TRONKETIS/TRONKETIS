#include "pch.h"
#include "CtrlCrearAssaig.h"
#include "PasarelaAssaig.h"

namespace Tronketis {

	String^ CtrlCrearAssaig::CrearAssaig(DateTime data_hora, String^ colla_name, String^ colla_uni_name)
	{
		// 1. Validar que la fecha no sea anterior a hoy
		DateTime avui = DateTime::Now;

		// Podriamos comparar simplemente fechas (sin horas) o el DateTime completo,
		// Dependiendo de si se permite crear para hoy, uso Date para chequear días pasados.
		if (data_hora.Date < avui.Date)
		{
			return "Error: La data de l'assaig no pot ser anterior a avui.";
		}

		// Validar campos de colla
		if (String::IsNullOrWhiteSpace(colla_name) || String::IsNullOrWhiteSpace(colla_uni_name))
		{
			return "Error: S'ha de proporcionar el nom i la universitat de la colla.";
		}

		// 2. Crear DTO
		AssaigDTO^ nouAssaig = gcnew AssaigDTO();
		nouAssaig->DataHora = data_hora;
		nouAssaig->CollaName = colla_name;
		nouAssaig->CollaUniName = colla_uni_name;

		// 3. Inserir a la BD a través de la passarel·la
		bool okey = PasarelaAssaig::InsertarAssaig(nouAssaig);

		if (okey) {
			return "Assaig creat correctament!";
		}
		else {
			return "Error: No s'ha pogut crear l'assaig a la base de dades.";
		}
	}
}
