#include"AccountHandler.h"
#include"BankingCommonDec1.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"
#include"AccountException.cpp"

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
	for(int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
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
			this->accArr[this->accNum++] = new NormalAccount(accID, cusName, balance, rate);
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
			this->accArr[this->accNum++] = new HighCreditAccount(accID, cusName, balance, rate, credit);
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
	
	try
	{
		if(money < 0)
			throw DepositException(0);
		for(int i = 0; i < this->accNum; i++)
		{
			if (this->accArr[i]->GetAccID() == accID)
			{
				this->accArr[i]->Deposit(money);
				cout<<"입금완료"<<endl;
				return ;
			}
		}
		throw CannotFindIDException(accID);
	}
	catch(AccountException& expn)
	{
		expn.ShowExceptionReason();
	}
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
	
	try
	{
		for(int i = 0; i < this->accNum; i++)
		{
			if (this->accArr[i]->GetAccID() == accID)
			{
				if (this->accArr[i]->GetBalance() >= money)
				{
					this->accArr[i]->Withdrawal(money);
					cout<<"출금완료"<<endl;
					return ;
				}
				else
					throw WithdrawalException(money, this->accArr[i]->GetBalance());
			}
		}
		throw CannotFindIDException(accID);
	}
	catch(AccountException& expn)
	{
		expn.ShowExceptionReason();
	}
	return ;
}
void AccountHandler::ShowAllAccount(void)
{
	cout<<endl<<"----계좌 출력----"<<endl;
	for(int i = 0; i < this->accNum; i++)
	{
		this->accArr[i]->ShowAccInfo();
		cout<<endl;
	}
}