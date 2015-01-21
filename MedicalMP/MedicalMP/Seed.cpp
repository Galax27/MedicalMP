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
	//Patients
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
	
	//Doctors
	context->Doctors.push_back(new Doctor(100, 3, 47, Middle, "Augustin", "Cimbru"));
	context->Doctors.push_back(new Doctor(101, 5, 39, Middle, "Remus", "Petala"));
	context->Doctors.push_back(new Doctor(102, 1, 50, Middle, "Stefan", "Petrescu"));
	context->Doctors.push_back(new Doctor(103, 2, 60, Senior, "Marcela", "Horia"));
	context->Doctors.push_back(new Doctor(104, 6, 32, Junior, "Anton", "Balauta"));
	context->Doctors.push_back(new Doctor(105, 4, 55, Senior, "Neli", "Spataru"));
	
	//MeidcalFiles
	tm time; time.tm_year = 2003; time.tm_mon = 10; time.tm_mday = 25;
	context->MedicalFiles.push_back(new MedicalFile(100, 100, 1, time, Cholesterol));
	tm time; time.tm_year = 2007; time.tm_mon = 11; time.tm_mday = 12;
	context->MedicalFiles.push_back(new MedicalFile(101, 101, 1, time, EatingDisorder));
	tm time; time.tm_year = 2004; time.tm_mon = 5; time.tm_mday = 16;
	context->MedicalFiles.push_back(new MedicalFile(102, 102, 1, time, Headache));
	tm time; time.tm_year = 2000; time.tm_mon = 8; time.tm_mday = 21;
	context->MedicalFiles.push_back(new MedicalFile(103, 103, 1, time, Tuberculosis));
	tm time; time.tm_year = 2008; time.tm_mon = 3; time.tm_mday = 15;
	context->MedicalFiles.push_back(new MedicalFile(104, 104, 1, time, Infertility));
	tm time; time.tm_year = 2011; time.tm_mon = 11; time.tm_mday = 12;
	context->MedicalFiles.push_back(new MedicalFile(105, 105, 1, time, Allergy));
	tm time; time.tm_year = 2012; time.tm_mon = 4; time.tm_mday = 7;
	context->MedicalFiles.push_back(new MedicalFile(106, 106, 1, time, Pneumonia));
	tm time; time.tm_year = 2004; time.tm_mon = 6; time.tm_mday = 8;
	context->MedicalFiles.push_back(new MedicalFile(107, 107, 1, time, Obesity));
	tm time; time.tm_year = 2006; time.tm_mon = 3; time.tm_mday = 27;
	context->MedicalFiles.push_back(new MedicalFile(108, 108, 1, time, LungCancer));
	tm time; time.tm_year = 2003; time.tm_mon = 10; time.tm_mday = 19;
	context->MedicalFiles.push_back(new MedicalFile(109, 109, 1, time, Migraine));
	tm time; time.tm_year = 2008; time.tm_mon = 5; time.tm_mday = 12;
	context->MedicalFiles.push_back(new MedicalFile(101, 101, 1, time, EarProblems));
	
	//Departments
	context->Departments.push_back(new Department(1, "Chirurgie"));
	context->Departments.push_back(new Department(2, "Cardiologie"));
	context->Departments.push_back(new Department(3, "Hematologie"));
	context->Departments.push_back(new Department(4, "Neurologie"));
	context->Departments.push_back(new Department(5, "Ortopedie"));
	context->Departments.push_back(new Department(6, "Oftalmologie"));
}
