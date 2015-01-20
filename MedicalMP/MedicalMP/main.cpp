#include <stdio.h>
#include <string>
#include "Patient.h"
using namespace std;

int main() {
	Patient *p;
	p = new Patient(1, 20, "Neculai", "Andrei");

	printf("%d", p->getAge());
	getchar();
}