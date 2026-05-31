#pragma once

#include "AssaigDTO.h"

namespace Tronketis {

	using namespace System;

	public ref class PasarelaAssaig
	{
	public:
		static bool InsertarAssaig(AssaigDTO^ assaig);
	};
}
