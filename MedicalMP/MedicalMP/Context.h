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

	public:
		Context();
		~Context();
		
		vector<Patient> Patients;
		vector<Doctor> Doctors;
		vector<MedicalFile> MedicalFiles;
		vector<Department> Departments;
};