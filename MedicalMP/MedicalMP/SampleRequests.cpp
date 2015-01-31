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
	}
}