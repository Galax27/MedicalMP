#include "stdafx.h"

namespace MedicalMP
{
	RequestsEngine::RequestsEngine()
	{
		Verbose = true;
		NumberOfThreads = 1;
	}

	void RequestsEngine::Run(RequestCollection requests)
	{
		_requests = requests;

		if (Verbose) Logger::WriteLog(System::UNIT_TESTS + " " + std::to_string(_requests.Size()) + " to process.");

		omp_set_num_threads(NumberOfThreads);

		if (Verbose) Logger::WriteLog(System::UNIT_TESTS + System::HASHTAG + "Starting resolve requests using OpenMP..");
		if (Verbose) Logger::WriteLog(System::UNIT_TESTS + System::HASHTAG + "Number of threads used : " + std::to_string(k_NumThreads));

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
		for (int i = 0; i < (int)_requests.PatientRequests.size(); ++i)
		{
			const int threadID(omp_get_thread_num());

			_requests.PatientRequests[i]->Execute();
		}
	}

	void RequestsEngine::RunDoctorRequests()
	{
		#pragma omp for
		for (int i = 0; i < (int)_requests.DoctorRequests.size(); ++i)
		{
			const int threadID(omp_get_thread_num());
			_requests.DoctorRequests[i]->Execute();
		}
	}

	void RequestsEngine::RunDepartmentRequests()
	{
		#pragma omp for
		for (int i = 0; i < (int)_requests.DepartmentRequests.size(); ++i)
		{
			const int threadID(omp_get_thread_num());
			_requests.DepartmentRequests[i]->Execute();
		}
	}

	void RequestsEngine::RunMedicalFileRequests()
	{
		#pragma omp for
		for (int i = 0; i < (int)_requests.MedicalFilesRequests.size(); ++i)
		{
			const int threadID(omp_get_thread_num());
			_requests.MedicalFilesRequests[i]->Execute();
		}
	}
}