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
	context->Patients.push_back(new Patient(100, 45, "Andrei", "Antoni", false));
	context->Patients.push_back(new Patient(101, 38, "Alexandru", "Mateescu", false));
	context->Patients.push_back(new Patient(102, 43, "Bogdan", "Musat", false));
	context->Patients.push_back(new Patient(103, 65, "Berta", "Bolini", true));
	context->Patients.push_back(new Patient(104, 29, "Bianca", "Rotaru", false));
	context->Patients.push_back(new Patient(105, 18, "Colin", "Draganu", false));
	context->Patients.push_back(new Patient(106, 23, "Costel", "Vasile", false));
	context->Patients.push_back(new Patient(107, 55, "Dan", "Caciula", false));
	context->Patients.push_back(new Patient(108, 53, "Daniela", "Matache", true));
	context->Patients.push_back(new Patient(109, 47, "Darius", "Adelei", false));
	context->Patients.push_back(new Patient(110, 33, "Erica", "Nicola", false));
	
	context->Departments.push_back(new Department(1, "Chirurgie"));
}
