#pragma once

#include "stdafx.h"

namespace MedicalMP
{
	class RequestCollection
	{
		public:
			std::vector <BaseRequest<Patient*>*> PatientRequests;
			std::vector <BaseRequest<Doctor*>*> DoctorRequests;
			std::vector <BaseRequest<MedicalFile*>*> MedicalFilesRequests;
			std::vector <BaseRequest<Department*>*> DepartmentRequests;

			int Size();
	};
}