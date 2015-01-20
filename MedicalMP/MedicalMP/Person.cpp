#include "Person.h"

Person::Person(int age, string firstName, string lastName)
{
	_age = age;
	_firstName = firstName;
	_lastName = lastName;
}

Person::~Person()
{

}

int Person::GetAge()
{
	return _age;
}

void Person::SetAge(int value)
{
	_age = value;
}

string Person::GetFirstName()
{
	return _firstName;
}

void Person::SetFirstName(string value)
{
	_firstName = value;
}

string Person::GetLastName()
{
	return _lastName;
}

void Person::SetLastName(string value)
{
	_lastName = value;
}