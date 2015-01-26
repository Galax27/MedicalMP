#pragma once

#include "stdafx.h"

namespace MedicalMP
{
    class Context
    {
    public:

        std::vector<Patient*> Patients;
        std::vector<Doctor*> Doctors;
        std::vector<MedicalFile*> MedicalFiles;
        std::vector<Department*> Departments;
    };
}
