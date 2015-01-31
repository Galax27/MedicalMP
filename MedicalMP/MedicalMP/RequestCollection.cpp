#include "stdafx.h"

namespace MedicalMP
{
	int RequestCollection::Size()
	{
		return PatientRequests.size() + DepartmentRequests.size()
			+ DoctorRequests.size() + MedicalFilesRequests.size();
	}
}