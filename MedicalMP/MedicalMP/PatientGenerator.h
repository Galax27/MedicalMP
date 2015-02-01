#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	class PatientGenerator
	{
		public:
			static Patient* Generate(int id);
	};
}