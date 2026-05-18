#include "pch.h"
#include "CtrlRegisterCasteller.h"
#include "PasarelaCasteller.h"
#include "CastellerDTO.h"

using namespace Tronketis;

void CtrlRegisterCasteller::registrarCasteller(
    String^ dni,
    String^ telefon)
{
    CastellerDTO^ c = gcnew CastellerDTO();

    c->dniCasteller = dni;
    c->telefon = telefon;

    PasarelaCasteller::insertar(c);
}