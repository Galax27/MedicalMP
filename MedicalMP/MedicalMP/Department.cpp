#include "stdafx.h"

namespace MedicalMP
{
    Department::Department(int id, std::string name)
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

    std::string Department::GetName()
    {
        return _name;
    }

    void Department::SetName(std::string value)
    {
        _name = value;
    }
}