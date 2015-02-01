#include "stdafx.h"

using namespace MedicalMP;

int main()
{

	Context *context = new Context();
	RequestCollection* requests = new RequestCollection();
	auto* requestsEngine = new RequestsEngine();
	SampleData::Seed(context);
	SampleRequests::Seed(requests, context);

	requestsEngine->NumberOfThreads = 5;
	requestsEngine->Run(requests);
	//MedicalMP::UnitTests::Seed(1000);
	//MedicalMP::UnitTests::ParalelizeRequests();

    getchar();
}