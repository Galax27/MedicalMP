#include "stdafx.h"

namespace MedicalMP
{
    Doctor::Doctor(int id, int departmentId, int age, Grade grade, std::string firstName, std::string lastName)
        :BaseEntity(id), Person(age, firstName, lastName)
    {
        _departmentId = departmentId;
        _grade = grade;
    }

    Doctor::~Doctor()
    {
    }

    int Doctor::GetDepartmentId()
    {
        return _departmentId;
    }

    void Doctor::SetDepartmentId(int value)
    {
        _departmentId = value;
    }

    Grade Doctor::GetGrade()
    {
        return _grade;
    }

    void Doctor::SetGrade(Grade value)
    {
        _grade = value;
    }
}