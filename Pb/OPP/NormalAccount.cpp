#include"NormalAccount.h"

#include<iostream>
using std::cout;
using std::endl;

NormalAccount::NormalAccount(const int accID, const char* name, const int money, const int rate)
	:Account(accID, name, money), rate(rate)
{
	return ;
};
int NormalAccount::GetRate() const
{
	return this->rate;
}
int NormalAccount::Deposit(const int money)
{	
	Account::Deposit(money + money*(rate/100.0));
	return 1;
}
void NormalAccount::ShowAccInfo() const
{
	Account::ShowAccInfo();
	cout<<"이자율 : "<<rate<<endl;
 return ;
}

