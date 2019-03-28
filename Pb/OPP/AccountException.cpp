#ifndef __ACCOUNTEXCEPTION_H__
#define __ACCOUNTEXCEPTION_H__

#include<iostream>

class AccountException
{
	public:
		virtual void ShowExceptionReason() = 0;
};

class CannotFindIDException : public AccountException
{
	private:
		int accID;
	public:
	CannotFindIDException(int accID) : accID(accID)
	{  };
	void ShowExceptionReason()
	{
		std::cout<<"ID("<<accID<<")를 찾을 수 없습니다."<<std::endl;
	}
};
class DepositException : public AccountException
{
	private:
		int money;
	public:
		DepositException(int money) : money(money)
		{  };
		void ShowExceptionReason()
		{
			std::cout<<"예금액이 0보다 작습니다."<<std::endl;
		}
};
class WithdrawalException : public AccountException
{
	private:
		int money, balance;
	public:
		WithdrawalException(int money, int balance) : money(money), balance(balance)
		{  };
		void ShowExceptionReason()
		{
			std::cout<<"인출액("<<money<<")이 잔액("<<balance<<")보다 많습니다."<<std::endl;
		}
};

#endif