#include "stdafx.h"

namespace MedicalMP
{
	void SampleRequests::Seed(RequestCollection* container, Context* context)
	{
		for (int i = 0; i < 100; i++)
		{
			container->PatientRequests.push_back(new SelectRequest<Patient*>(context->Patients, [&](Patient* p) 
			{ 
				return p->GetAge() > Utils::GetRandomUnsigned(10)
					|| p->GetFirstName() == "andrei" 
					|| p->GetLastName() == "ion" ; 
			}));
		}

		for (int i = 0; i < 100; i++)
		{
			container->DoctorRequests.push_back(new SelectRequest<Doctor*>(context->Doctors, [&](Doctor* d)
			{
				return d->GetFirstName() == "andrei"
					|| d->GetLastName() == "ion";
			}));
		}

		for (int i = 0; i < 100; i++)
		{
			container->DepartmentRequests.push_back(new SelectRequest<Department*>(context->Departments, [&](Department* d)
			{
				return d->GetName() == "andrei";
			}));
		}

		for (int i = 0; i < 100; i++)
		{
			container->MedicalFilesRequests.push_back(new SelectRequest<MedicalFile*>(context->MedicalFiles, [&](MedicalFile* m)
			{
				return m->getDiagnostic() == Disease::BackPain;
			}));
		}
	}
}