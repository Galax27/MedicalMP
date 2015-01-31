#include "stdafx.h"

namespace MedicalMP
{
	RequestsEngine::RequestsEngine()
	{
		Verbose = true;
		NumberOfThreads = 1;
	}

	void RequestsEngine::Run(RequestCollection* requests)
	{
		_requests = requests;

		if (Verbose) Logger::WriteLog(System::UNIT_TESTS + " " + std::to_string(_requests->Size()) + " to process.");

		omp_set_num_threads(NumberOfThreads);

		if (Verbose) Logger::WriteLog(System::UNIT_TESTS + System::HASHTAG + "Starting resolve requests using OpenMP..");
		if (Verbose) Logger::WriteLog(System::UNIT_TESTS + System::HASHTAG + "Number of threads used : " + std::to_string(NumberOfThreads));

		#pragma omp parallel
		{
			RunPatientRequests();
			RunDoctorRequests();
			RunDepartmentRequests();
			RunMedicalFileRequests();
		}
	}

	void RequestsEngine::RunPatientRequests()
	{
		#pragma omp for
		for (int i = 0; i < (int)_requests->PatientRequests.size(); ++i)
		{
			const int threadId(omp_get_thread_num());
			_requests->PatientRequests[i]->Execute();

			if (Verbose)
				LogRequest(threadId, _requests->PatientRequests[i]->GetElapsedTime(), "Patient", i);
		}
	}

	void RequestsEngine::RunDoctorRequests()
	{
		#pragma omp for
		for (int i = 0; i < (int)_requests->DoctorRequests.size(); ++i)
		{
			const int threadId(omp_get_thread_num());
			_requests->DoctorRequests[i]->Execute();

			if (Verbose)
				LogRequest(threadId, _requests->DoctorRequests[i]->GetElapsedTime(), "Doctor", i);
		}
	}

	void RequestsEngine::RunDepartmentRequests()
	{
		#pragma omp for
		for (int i = 0; i < (int)_requests->DepartmentRequests.size(); ++i)
		{
			const int threadId(omp_get_thread_num());
			_requests->DepartmentRequests[i]->Execute();

			if (Verbose)
				LogRequest(threadId, _requests->DepartmentRequests[i]->GetElapsedTime(), "Department", i);
		}
	}

	void RequestsEngine::RunMedicalFileRequests()
	{
		#pragma omp for
		for (int i = 0; i < (int)_requests->MedicalFilesRequests.size(); ++i)
		{
			const int threadId(omp_get_thread_num());
			_requests->MedicalFilesRequests[i]->Execute();

			if (Verbose)
				LogRequest(threadId, _requests->DepartmentRequests[i]->GetElapsedTime(), "MedicalFiles", i);
		}
	}

	void RequestsEngine::LogRequest(int threadId, double elapsedTime, std::string entity, int requestId)
	{
		Logger::WriteLog(
			System::UNIT_TESTS + System::HASHTAG
			+ System::THREAD_ID + std::to_string(threadId) + System::HASHTAG
			+ "Entity: " + entity + System::HASHTAG + 
			+ "Request Id: " + std::to_string(requestId) + System::HASHTAG + 
			+ "Time: " + std::to_string(elapsedTime)
			);
	}
}