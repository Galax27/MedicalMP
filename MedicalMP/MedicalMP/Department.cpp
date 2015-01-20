#include "Department.h"

Department::Department(int id, string name)
{
	_id = id;
	_name = name;
}

Department::~Department()
{

}

int Department::GetId()
{
	return _id;
}

string Department::GetName()
{
	return _name;
}

void Department::SetName(string value)
{
	_name = value;
}