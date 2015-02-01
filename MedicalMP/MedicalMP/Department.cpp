#include "stdafx.h"

namespace MedicalMP
{
	Department::Department(int id, std::string name) : BaseEntity(id)
    {
        _name = name;
    }
	
	Department::~Department()
	{

	}

    std::string Department::GetName()
    {
        return _name;
    }

    void Department::SetName(std::string value)
    {
        _name = value;
    }
}