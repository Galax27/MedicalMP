#include "Patient.h"

Patient::Patient(int id, int age, string firstName, string lastName)
{
	_id = id;
	_age = age;
	_firstName = firstName;
	_lastName = lastName;
}

Patient::~Patient()
{
}

int Patient::getId()
{
	return this->_id;
}

int Patient::getAge()
{
	return this->_age;
}

void Patient::setAge(int value)
{
	this->_age = value;
}

string Patient::getFirstName()
{
	return this->_firstName;
}

void Patient::setFirstName(string value)
{
	this->_firstName = value;
}

string Patient::getLastName()
{
	return this->_lastName;
}

void Patient::setLastName(string value)
{
	this->_lastName = value;
}