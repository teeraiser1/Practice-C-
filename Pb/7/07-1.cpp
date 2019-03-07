#include<iostream>
#include<cstring>
using namespace std;

class Person
{
	int age;
	char name[50];
	public:
	Person(int age, char* name)
		:age(age)
	{
		strcpy(this->name, name);
	}
	void GetName()
	{
		cout<<name<<endl;
		return ;
	}
	void GetAge()
	{
		cout<<age<<endl;
		return ;
	}
};
class UnivStudent : public Person
{
	char major[50];
	public:
		UnivStudent(int age, char* name, char* major)
			:Person(age, name)
		{
			strcpy(this->major, major);
		}
		void GetInfo()
		{
			GetAge();
			GetName();			
			cout<<major<<endl;
			return ;
		}
};

int main(void)
{
	UnivStudent ustd1(20, "Lee", "QWE");
	ustd1.GetInfo();
}