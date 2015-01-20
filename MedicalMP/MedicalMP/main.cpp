#include <stdio.h>
#include <string>
#include <ctime>
#include "Patient.h"
#include "MedicalFile.h"
#include "Doctor.h"
#include "Department.h"
using namespace std;

int main() {
	Patient *p;
	p = new Patient(1, 20, "Andrei", "Neculai", false);
	
	Doctor *doc;
	doc = new Doctor(1, 1, 30, Grade::Junior, "Constantin", "Tapean");
	
	Department *dep;
	dep = new Department(1, "Chirurgie");
	
	MedicalFile *mf;
	tm time;
	time.tm_year = 2000;
	time.tm_mon = 5;
	time.tm_mday = 30;
	mf = new MedicalFile(1, 1, 1, time, Disease::Cholesterol);
	mf->setDiagnostic(Disease::Acne, 1);
	
	printf("Patient age: %d\n", p->GetAge());
	printf("Doctor first name: %s\n", doc->GetFirstName().c_str());
	printf("Department name: %s\n", dep->GetName().c_str());
	printf("Medical file diagnostic: %d; Day:%d\n", mf->getDiagnostic(), mf->getDate().tm_mday);
	getchar();
}