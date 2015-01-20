#include <string>
using namespace std;

class Patient
{
private:
	int	_id,
		_age;
	string _firstName,
		_lastName;

public:
	Patient(int id, int age, string firstName, string lastName);
	~Patient();

	int getId();

	int getAge();
	void setAge(int value);

	string getFirstName();
	void setFirstName(string value);

	string getLastName();
	void setLastName(string value);

};