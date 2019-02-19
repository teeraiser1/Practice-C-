#include<iostream>
#include<cstring>
using namespace std;

namespace COMP_POS
{
	enum {CLERK, SENIOR, ASSIST, MANGER};
	char STRING[4][10] = {"사원", "주임", "대리", "매니저"};
}

class NameCard
{
	char* name, *coopName, *phoneNum;
	int pos;
	public:
		NameCard(const char* myName, const char* myCoopName, const char* myPhoneNum, int myPos)
			: pos(myPos)
		{
			int templen = strlen(myName)+1;
			name = new char[templen];
			strcpy(name, myName);
			
			templen = strlen(myCoopName)+1;
			coopName = new char[templen];
			strcpy(coopName, myCoopName);
				
			templen = strlen(myPhoneNum)+1;
			phoneNum = new char[templen];
			strcpy(phoneNum, myPhoneNum);
		}
		void ShowNameCardInfo()
		{
			cout<<"이름 : "<<name<<endl;
			cout<<"회사 : "<<coopName<<endl;
			cout<<"전화번호 : "<<phoneNum<<endl;
			cout<<"직급 : "<<COMP_POS::STRING[pos]<<endl;
		}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}