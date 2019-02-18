#include<iostream>
#include<cstring>
using namespace std;

class NameCard
{
	char* name, *coopName, *phoneNum;
	int pos;
	public:
		NameCard(char* myName, char* myCoopName, char* myPhoneNum, int myPos)
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
	
};

enum {CLERK, SENIOR, ASSIST, MANGER} COMP_POS;

