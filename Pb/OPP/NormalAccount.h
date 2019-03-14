#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__
#include"Account.h"

class NormalAccount : public Account
{
	private:
		int rate;
	public:
		NormalAccount(const int accID, const char* name, const int money, const int rate);
		int GetRate() const;
		int Deposit(const int money);
		void ShowAccInfo() const;
};
#endif