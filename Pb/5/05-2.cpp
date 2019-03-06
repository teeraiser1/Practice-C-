#include<iostream>
#include<cstring>
using namespace std;

class Person
{
	char* name;
	int age;
	public:
	Person(char* myname, int myage)
	{
		int len=strlen(myname)+1;
		name = new char[len];
		strcpy(name, myname);
		age=myage;
	}
	void ShowPoersonInfo() const
	{
		cout<<name<<endl;
		cout<<age<<endl;
	}
	~Person()
	{
		delete []name;
		cout<<"ASDSDSA"<<endl;
	}
};

int main(void)
{
	Person man1("Lee dong", 20);
	Person man2 = man1;
	man1.ShowPoersonInfo();
	man2.ShowPoersonInfo();
	return 0;
}