#include <stdio.h>
#include <string>
#include <ctime>
#include "Patient.h"
#include "MedicalFile.h"
#include "Doctor.h"
#include "Department.h"
#include "Context.h"
#include "Seed.h"
using namespace std;

void Seed(Context* context)
{
	context->Departments.push_back(new Department(1, "Chirurgie"));
}