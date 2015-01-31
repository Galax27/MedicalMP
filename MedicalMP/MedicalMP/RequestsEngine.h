#pragma once
#include "stdafx.h"

namespace MedicalMP
{
	class RequestsEngine
	{
		private:
			RequestCollection* _requests;
			void RunPatientRequests();
			void RunDoctorRequests();
			void RunDepartmentRequests();
			void RunMedicalFileRequests();
	
			void LogRequest(int threadId, double elapsedTime, std::string entity, int requestId);

		public:
			RequestsEngine();
			void Run(RequestCollection* requests);
			bool Verbose;
			int NumberOfThreads;
	};
}