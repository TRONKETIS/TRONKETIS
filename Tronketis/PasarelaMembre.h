#pragma once

#include "DB.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

ref class PasarelaMembre
{
public:
	static bool insertar(String^ dni, String^ collaName, String^ uniName, DateTime joinDate);
};
