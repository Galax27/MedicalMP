#include "stdafx.h"

#include "TestsDB.h"
using namespace MedicalMP;

int main()
{

	Context *context = new Context();
	RequestCollection *requests = new RequestCollection();
	SampleData::Seed(context);
	SampleRequests::Seed(requests, context);
	
	std::stringstream ss;
	ss << context->Patients->size() << " ";

	requests->PatientRequests[requests->PatientRequests.size()-1]->Execute(); //delete some items
	
	ss << context->Patients->size();
	Logger::WriteLog(ss.str());
	//MedicalMP::UnitTests::Seed(1000);
	//MedicalMP::UnitTests::ParalelizeRequests();

    getchar();
}