#ifndef DEPARTAMENT_H
#define DEPARTAMENT_H
#include <string>
using namespace std;
class Department
{
private:
	int _id;
	string _name;
public:
	Department(int id, string name);
	~Department();

	int GetId();

	string GetName();
	void SetName(string value);
};

#endif