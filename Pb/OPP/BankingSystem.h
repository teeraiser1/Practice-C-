#ifndef __BANKINGSYSTEM__
#define __BANKINGSYSTEM__
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#define NAME_LEN 20
#endif

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

AccountHandler::AccountHandler() :accNum(0)
{
	return ;
}
AccountHandler::~AccountHandler()
{
	delete[](this->account);
	return ;
}
void AccountHandler::ShowMenu(void)
{
	cout<<"-----Menu------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;;
	cout<<"선택 : ";
	return ;
}
void AccountHandler::OpenAccount(void)
{
	int accID, balance, rate, credit, choice;
	char cusName[NAME_LEN];
	cout<<"----계좌 개설----"<<endl;
	cout<<"1. Normal  2. Credit"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Normal"<<endl;
			cout<<"계좌ID : ";
			cin>>accID;
			cout<<"이름 : ";
			cin>>cusName;
			cout<<"입금액 : ";
			cin>>balance;
			cout<<"이자율 : ";
			cin>>rate;
			this->account[this->accNum++] = new NormalAccount(accID, cusName, balance, rate);
			break;
		case 2:
			cout<<"Credit"<<endl;
			cout<<"계좌ID : ";
			cin>>accID;
			cout<<"이름 : ";
			cin>>cusName;
			cout<<"입금액 : ";
			cin>>balance;
			cout<<"이자율 : ";
			cin>>rate;
			cout<<"신용등급 : ";
			cin>>credit;
			this->account[this->accNum++] = new HighCreditAccount(accID, cusName, balance, rate, credit);
			break;
	}
	return ;
}
void AccountHandler::Deposit(void)
{
	int accID, money;
	cout<<endl<<"-----입 금-----"<<endl;
	cout<<"계좌ID : ";
	cin>>accID;
	cout<<"입금액 : ";
	cin>>money;
	
	for(int i = 0; i < this->accNum; i++)
	{
		if (this->account[i]->GetAccID() == accID)
		{
			this->account[i]->Deposit(money);
			cout<<"입금완료"<<endl;
			return ;
		}
	}
	cout<<"ID오류"<<endl;
	
	return ;
}
void AccountHandler::Withdrawal(void)
{
	int accID, money;
	cout<<endl<<"-----출 금-----"<<endl;
	cout<<"계좌ID : ";
	cin>>accID;
	cout<<"출금액 : ";
	cin>>money;
	
	for(int i = 0; i < this->accNum; i++)
	{
		if (this->account[i]->GetAccID() == accID)
		{
			if (this->account[i]->GetBalance() >= money)
			{
				this->account[i]->Withdrawal(money);
				cout<<"출금완료"<<endl;
				break;
			}
			else
				cout<<"잔액부족"<<endl;
		}
	}
	cout<<"ID오류"<<endl;
	
	return ;
}
void AccountHandler::ShowAllAccount(void)
{
	cout<<endl<<"----계좌 출력----"<<endl;
	for(int i = 0; i < this->accNum; i++)
	{
		this->account[i]->ShowAccInfo();
		cout<<endl;
	}
}