#pragma once

#include "stdafx.h"

namespace MedicalMP
{
    class Person
    {
    private:
        int _age;
        std::string _firstName;
        std::string _lastName;

    public:
        Person(int age, std::string firstName, std::string lastName);
		virtual ~Person() = 0;

        int GetAge();
        void SetAge(int value);

        std::string GetFirstName();
        void SetFirstName(std::string value);

        std::string GetLastName();
        void SetLastName(std::string value);
    };

	inline Person::~Person() {}
}
