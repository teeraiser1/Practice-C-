#include"HighCreditAccount.h"

#include<iostream>
using std::cout;
using std::endl;

HighCreditAccount::HighCreditAccount(const int accID, const char* name, const int money, const int rate, const int credit)
	:NormalAccount(accID, name, money, rate), credit(credit)
{
	return ;
}
int HighCreditAccount::GetCredit() const
{
	return this->credit;
}
int HighCreditAccount::Deposit(const int money)
{
	int additionalRate;
	switch(credit)
	{
		case 1:
			additionalRate = 7;
			break;
		case 2:
			additionalRate = 4;
			break;
		case 3:
			additionalRate = 2;
			break;
	}
	Account::Deposit(money + money*((GetRate()+additionalRate)/100.0));
	return 1;
}
void HighCreditAccount::ShowAccInfo() const
{	
	NormalAccount::ShowAccInfo();
	cout<<"신용등급 : "<<credit<<endl;
 return ;
}