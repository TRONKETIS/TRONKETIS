#include "pch.h"
#include "PasarelaCastell.h"

using namespace Tronketis;

PasarelaCastell::PasarelaCastell(CastellDTO^ dto)
{
    this->dto = dto;
}

int PasarelaCastell::getId()
{
    return dto->idCastell;
}

String^ PasarelaCastell::getNom()
{
    return dto->nom;
}

int PasarelaCastell::getPisos()
{
    return dto->pisos;
}

String^ PasarelaCastell::getTipus()
{
    return dto->tipus;
}