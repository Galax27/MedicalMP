#pragma once

#include "stdafx.h"

namespace MedicalMP
{
    class Patient : public Person
    {
    private:
        int _id;
        bool _isDeceased;

    public:
        Patient(int id, int age, std::string firstName, std::string lastName, bool isDeceased);
        ~Patient();
		bool Patient::operator==(const Patient& other);

        int GetId();
        bool GetIsDeceased();
        void SetIsDeceased(bool value);
    };
}
