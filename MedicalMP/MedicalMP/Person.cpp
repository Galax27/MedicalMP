#include "stdafx.h"

namespace MedicalMP
{
    Person::Person(int age, std::string firstName, std::string lastName)
    {
        _age = age;
        _firstName = firstName;
        _lastName = lastName;
    }

    Person::~Person()
    {

    }

    int Person::GetAge()
    {
        return _age;
    }

    void Person::SetAge(int value)
    {
        _age = value;
    }

    std::string Person::GetFirstName()
    {
        return _firstName;
    }

    void Person::SetFirstName(std::string value)
    {
        _firstName = value;
    }

    std::string Person::GetLastName()
    {
        return _lastName;
    }

    void Person::SetLastName(std::string value)
    {
        _lastName = value;
    }
}