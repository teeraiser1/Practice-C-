#include<iostream>
#include<cstring>
using namespace std;

class Person
{
	char* name;
	int age;
	public:
		Person(const char* myname, int myage)
		{
			int len = strlen(myname)+1;
			name = new char[len];
			strcpy(name, myname);
			age = myage;
		}
	~Person()
	{
		delete name;
	}
};

int main()
{
	Person man1("Lee dong woo", 29);
	return 0;
}