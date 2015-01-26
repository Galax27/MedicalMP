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

        int GetId();
        bool GetIsDeceased();
        void SetIsDeceased(bool value);
    };
}
