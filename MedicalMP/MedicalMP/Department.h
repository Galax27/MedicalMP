#pragma once

#include "stdafx.h"

namespace MedicalMP
{
    class Department: public BaseEntity
    {
    private:
        std::string _name;

    public:
        Department(int id, std::string name);
        ~Department();

        std::string GetName();
        void SetName(std::string value);
    };
}