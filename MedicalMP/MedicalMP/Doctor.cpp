#include "Doctor.h"

Doctor::Doctor(int id, int departmentId, int age, Grade grade, string firstName, string lastName)
	:Person(age, firstName, lastName)
{
	_id = id;
	_departmentId = departmentId;
	_grade = grade;
}

Doctor::~Doctor()
{
}

int Doctor::GetId()
{
	return _id;
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