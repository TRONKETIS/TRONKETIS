#pragma once

#include "CercadorMembre.h"
#include "PasarelaMembre.h"
#include "CercadorUsuari.h"

using namespace System;

ref class CtrlAfegirMembreColla
{
public:
	static bool afegirMembre(String^ dni, String^ collaName, String^ uniName, String^% error);
};
