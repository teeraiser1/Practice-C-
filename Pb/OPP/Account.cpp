#include"Account.h"
#include<cstring>
#include<iostream>
using std::cout;
using std::endl;

Account::Account(const int accID, const char* name, const int money)
	:accID(accID), balance(money)
{
	cusName = name;
	return ;
};
Account::Account(const Account& targetAcc)
	:accID(targetAcc.accID), balance(targetAcc.balance)
{
	cusName = targetAcc.cusName;
}
Account::~Account()
{   }
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
	return cusName.GetString();
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
	cout<<"이름 : "<<cusName.GetString()<<endl;
	cout<<"입금액 : "<<balance<<endl;
 return ;
}
Account& Account::operator=(const Account& acc)
{
	this->accID = acc.accID;
	this->balance = acc.balance;
	this->cusName = acc.cusName;
	return *this;
}

