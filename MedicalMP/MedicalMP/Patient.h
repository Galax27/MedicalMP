#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"
#include <string>
using namespace std;

class Patient: public Person
{
	private:
		int _id;
		bool _isDeceased;

	public:
		Patient(int id, int age, string firstName, string lastName, bool isDeceased);
		~Patient();

		int GetId();
		bool GetIsDeceased();
		void SetIsDeceased(bool value);
};

#endif