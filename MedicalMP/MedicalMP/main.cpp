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

int main() {

	Context* c = new Context();
	
	Seed(c);

	printf("%s", c->Departments[0]->GetName().c_str());

	getchar();
}