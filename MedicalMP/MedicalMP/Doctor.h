#pragma once

#include "stdafx.h"

namespace MedicalMP
{
    class Doctor : public BaseEntity, Person
    {
    private:
        int _departmentId;
        Grade _grade;
    public:
        Doctor(int id, int departmentId, int age, Grade grade, std::string firstName, std::string lastName);
        ~Doctor();

        int GetDepartmentId();
        void SetDepartmentId(int value);

        Grade GetGrade();
        void SetGrade(Grade value);
    };
}