#include"Account.h"
#include<cstring>
#include<iostream>
using std::cout;
using std::endl;

Account::Account(const int accID, const char* name, const int money)
	:accID(accID), balance(money)
{
	cusName = new char[strlen(name)+1];
	strcpy(cusName, name);
	return ;
};
Account::Account(const Account& targetAcc)
	:accID(targetAcc.accID), balance(targetAcc.balance)
{
	cusName = new char[strlen(targetAcc.cusName)+1];
	strcpy(cusName, targetAcc.cusName);
}
Account::~Account()
{
	delete(cusName);
}
int Account::GetAccID() const
{
	return this->accID;
}
int Account::GetBalance() const
{
	return this->balance;
}
char* Account::GetName() const
{
	return cusName;
}
int Account::Withdrawal(const int money)
{
	if(money > balance)
		return 0;
	balance -= money;
	return 1;
}
int Account::Deposit(const int money)
{
	balance += money;
	return 1;
}
void Account::ShowAccInfo() const
{
	cout<<"계좌ID : "<<accID<<endl;
	cout<<"이름 : "<<cusName<<endl;
	cout<<"입금액 : "<<balance<<endl;
 return ;
}

