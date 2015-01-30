#include "stdafx.h"

namespace MedicalMP
{
	void SampleRequests::Seed(RequestsContainer* container, Context* context)
	{
		container->PatientRequests.push_back(new SelectRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() > 50; }));
		container->PatientRequests.push_back(new SelectRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() > 50; }));
		container->PatientRequests.push_back(new SelectRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() > 52; }));
		container->PatientRequests.push_back(new SelectRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() > 52; }));
		container->PatientRequests.push_back(new SelectRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() > 52; }));
		container->PatientRequests.push_back(new SelectRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() > 50; }));
		container->PatientRequests.push_back(new SelectRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() > 53; }));
		container->PatientRequests.push_back(new SelectRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() > 50; }));
		container->PatientRequests.push_back(new SelectRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() > 55; }));
		container->PatientRequests.push_back(new SelectRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() > 51; }));

		container->PatientRequests.push_back(new DeleteRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() < 20; }));
		container->PatientRequests.push_back(new DeleteRequest<Patient*>(context->Patients, [&](Patient* p) { return p->GetAge() > 65; }));
	}
}