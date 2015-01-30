#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	class SampleData
	{
		private:
			static void SeedDepartments(Context* context);
			static void SeedDoctors(Context* context);
			static void SeedPatients(Context* context);
			static void SeedMedicalFiles(Context* context);
		public:
			static void Seed(Context* context);

	};
}