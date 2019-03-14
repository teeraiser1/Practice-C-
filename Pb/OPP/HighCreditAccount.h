#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__
#include"NormalAccount.h"
#endif

class HighCreditAccount : public NormalAccount
{
	private:
		int credit;
	public:
		HighCreditAccount(const int accID, const char* name, const int money, const int rate, const int credit);
		int GetCredit() const;
		int Deposit(const int money);
		void ShowAccInfo() const;
};