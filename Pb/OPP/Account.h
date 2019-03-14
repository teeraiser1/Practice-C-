#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account{
	private:
		int accID;
		char* cusName;
		int balance;
	public:
	Account(const int accID, const char* name, const int money);
	Account(const Account& targetAcc);
	~Account();
	int GetAccID() const;
	int GetBalance() const;
	char* GetName() const;
	int Withdrawal(const int money);
	virtual int Deposit(const int money) = 0;
	virtual void ShowAccInfo() const = 0;
};
#endif