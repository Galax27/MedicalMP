#include "stdafx.h"

#include "TestsDB.h"

int main()
{
    std::srand((unsigned int)std::time(0)); 

    MedicalMP::UnitTests::Seed(100);
    MedicalMP::UnitTests::ParalelizeRequests();

    getchar();
}