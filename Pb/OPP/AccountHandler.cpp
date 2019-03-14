#include"AccountHandler.h"
#include"BankingCommonDec1.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

AccountHandler::AccountHandler() :accNum(0)
{
	return ;
}
AccountHandler::~AccountHandler()
{
	delete[](this->account);
	return ;
}
void AccountHandler::ShowMenu(void)
{
	cout<<"-----Menu------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;;
	cout<<"선택 : ";
	return ;
}
void AccountHandler::OpenAccount(void)
{
	int accID, balance, rate, credit, choice;
	char cusName[NAME_LEN];
	cout<<"----계좌 개설----"<<endl;
	cout<<"1. Normal  2. Credit"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Normal"<<endl;
			cout<<"계좌ID : ";
			cin>>accID;
			cout<<"이름 : ";
			cin>>cusName;
			cout<<"입금액 : ";
			cin>>balance;
			cout<<"이자율 : ";
			cin>>rate;
			this->account[this->accNum++] = new NormalAccount(accID, cusName, balance, rate);
			break;
		case 2:
			cout<<"Credit"<<endl;
			cout<<"계좌ID : ";
			cin>>accID;
			cout<<"이름 : ";
			cin>>cusName;
			cout<<"입금액 : ";
			cin>>balance;
			cout<<"이자율 : ";
			cin>>rate;
			cout<<"신용등급 : ";
			cin>>credit;
			this->account[this->accNum++] = new HighCreditAccount(accID, cusName, balance, rate, credit);
			break;
	}
	return ;
}
void AccountHandler::Deposit(void)
{
	int accID, money;
	cout<<endl<<"-----입 금-----"<<endl;
	cout<<"계좌ID : ";
	cin>>accID;
	cout<<"입금액 : ";
	cin>>money;
	
	for(int i = 0; i < this->accNum; i++)
	{
		if (this->account[i]->GetAccID() == accID)
		{
			this->account[i]->Deposit(money);
			cout<<"입금완료"<<endl;
			return ;
		}
	}
	cout<<"ID오류"<<endl;
	
	return ;
}
void AccountHandler::Withdrawal(void)
{
	int accID, money;
	cout<<endl<<"-----출 금-----"<<endl;
	cout<<"계좌ID : ";
	cin>>accID;
	cout<<"출금액 : ";
	cin>>money;
	
	for(int i = 0; i < this->accNum; i++)
	{
		if (this->account[i]->GetAccID() == accID)
		{
			if (this->account[i]->GetBalance() >= money)
			{
				this->account[i]->Withdrawal(money);
				cout<<"출금완료"<<endl;
				return ;
			}
			else
			{
				cout<<"잔액부족"<<endl;
				return ;
			}
		}
	}
	cout<<"ID오류"<<endl;
	
	return ;
}
void AccountHandler::ShowAllAccount(void)
{
	cout<<endl<<"----계좌 출력----"<<endl;
	for(int i = 0; i < this->accNum; i++)
	{
		this->account[i]->ShowAccInfo();
		cout<<endl;
	}
}