#include<cstring>
#include<iostream>

using namespace std;

namespace COMP_POS
{
	enum {CLERK, SENIOR, ASSIST, MANGER};
	char STRING[4][10] = {"사원", "주임", "대리", "매니저"};
}

class NameCard
{
	char* name, *compName, *phoneNum;
	int pos;
	public:
		NameCard(const char* myName, const char* myCompName, const char* myPhoneNum, int myPos)
			: pos(myPos)
		{
			int templen = strlen(myName)+1;
			name = new char[templen];
			strcpy(name, myName);
			
			templen = strlen(myCompName)+1;
			compName = new char[templen];
			strcpy(compName, myCompName);
				
			templen = strlen(myPhoneNum)+1;
			phoneNum = new char[templen];
			strcpy(phoneNum, myPhoneNum);
		}
	
		NameCard(const NameCard& copy)
			:pos(copy.pos)
		{
			int len = strlen(name) + 1;
			name = new char[len];
			strcpy(name, copy.name);
			len = strlen(compName) + 1;
			compName = new char[len];
			strcpy(compName, copy.compName);
			len = strlen(phoneNum) + 1;
			phoneNum = new char[len];
			strcpy(phoneNum, copy.phoneNum);
		}
		void ShowNameCardInfo()
		{
			cout<<"이름 : "<<name<<endl;
			cout<<"회사 : "<<compName<<endl;
			cout<<"전화번호 : "<<phoneNum<<endl;
			cout<<"직급 : "<<COMP_POS::STRING[pos]<<endl;
		}
		~NameCard()
		{
			delete []name;
			delete []compName;
			delete []phoneNum;
		}
};

int main(void)
{
	NameCard manCler("Lee", "ASD", "123123", COMP_POS::CLERK);
	NameCard copy1=manCler;
	NameCard manSIN("KIN", "QWE", "456456", COMP_POS::SENIOR);
	NameCard copy2=manSIN;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}