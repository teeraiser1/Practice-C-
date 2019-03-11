#include<iostream>
#include<cstring>
#include"BankingSystem.h"


using std::cout;
using std::cin;
using std::endl;

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

int main(void)
{
	int choosenNum;
	AccountHandler accountHandler;
	
	while(1)
	{
		accountHandler.ShowMenu();
		cin>>choosenNum;
		switch(choosenNum)
		{
			case MAKE :
				accountHandler.OpenAccount();
				break;
			case DEPOSIT :
				accountHandler.Deposit();
				break;
			case WITHDRAW :
				accountHandler.Withdrawal();
				break;
			case INQUIRE :
				accountHandler.ShowAllAccount();
				break;
			case EXIT :
				return 0;
			default :
				cout<<"잘못된 입력입니다."<<endl<<endl;
		}
	}
	return 0;
}