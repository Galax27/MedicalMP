#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
	private:
		int _age;
		string _firstName,
			_lastName;
	public:
		Person(int age, string firstName, string lastName);
		~Person();

		int GetAge();
		void SetAge(int value);

		string GetFirstName();
		void SetFirstName(string value);

		string GetLastName();
		void SetLastName(string value);
};
#endif