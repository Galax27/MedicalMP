#include <string>
#include "Person.h"
#include "Grade.h"
using namespace std;

class Doctor: public Person
{
	private:
		int _id,
			_departmentId;
		Grade _grade;
	public:
		Doctor(int id, int departmentId, int age, Grade grade, string firstName, string lastName);
		~Doctor();

		int GetId();
		
		int GetDepartmentId();
		void SetDepartmentId(int value);

		Grade GetGrade();
		void SetGrade(Grade value);
};