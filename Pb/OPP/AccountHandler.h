#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include"Account.h"

class AccountHandler
{
	private:
		Account* account[100];
		int accNum;		
	public:
		AccountHandler();
		~AccountHandler();
		void ShowMenu(void);
		void OpenAccount(void);
		void Deposit(void);
		void Withdrawal(void);
		void ShowAllAccount(void);
};

#endif