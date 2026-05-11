#include "pch.h"
#include "CtrlConsultarCastell.h"
#include "CercadorCastell.h"

List<PasarelaCastell^>^
CtrlConsultarCastell::consultarPerNom(String^ nom)
{
    return CercadorCastell::cercaPerNom(nom);
}