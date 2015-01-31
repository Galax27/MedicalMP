#include "stdafx.h"

namespace MedicalMP
{
	Patient* PatientGenerator::Generate(int id)
	{
		auto patient = new Patient(
			id,
			rand() % 100,
			PeopleNames[rand() % PeopleNames.size()],
			PeopleNames[rand() % PeopleNames.size()],
			rand() % 2
			);

		return patient;
	}
}