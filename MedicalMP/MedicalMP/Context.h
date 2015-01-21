#ifndef CONTEXT_H
#define CONTEXT_H
#include<stdio.h>
#include<vector>
#include"Patient.h"
#include"Doctor.h"
#include"MedicalFile.h"
#include"Department.h"
using namespace std;
class Context
{
	private:
		bool patientValidation(Patient p);
	public:
		
		vector<Patient> Patients;
		vector<Doctor> Doctors;
		vector<MedicalFile> MedicalFiles;
		vector<Department> Departments;
};

#endif