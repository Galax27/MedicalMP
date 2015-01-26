#pragma once

#include "stdafx.h"

namespace MedicalMP
{
    class Department
    {
    private:
        int _id;
        std::string _name;

    public:
        Department(int id, std::string name);
        ~Department();

        int GetId();

        std::string GetName();
        void SetName(std::string value);
    };
}