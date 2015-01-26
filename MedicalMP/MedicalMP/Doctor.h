#pragma once

#include "stdafx.h"

namespace MedicalMP
{
    class Doctor : public Person
    {
    private:
        int _id,
            _departmentId;
        Grade _grade;
    public:
        Doctor(int id, int departmentId, int age, Grade grade, std::string firstName, std::string lastName);
        ~Doctor();

        int GetId();

        int GetDepartmentId();
        void SetDepartmentId(int value);

        Grade GetGrade();
        void SetGrade(Grade value);
    };
}