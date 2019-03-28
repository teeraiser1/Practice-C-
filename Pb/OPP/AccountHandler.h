#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include"Account.h"
#include"BoundCheckArray.h"
#include"BoundCheckArray.cpp"

class AccountHandler
{
	private:
		BoundCheckArray<Account*> accArr;
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