#include<iostream>
#include<cstring>

#define NAME_LEN 20

using std::cout;
using std::cin;
using std::endl;

void ShowMenu(void);
void OpenAccount(void);
void Deposit(void);
void Withdrawal(void);
void ShowAllAccount(void);


class Account{
	int accID;
	char* cusName;
	int balance;
	
	public:
	static int accNum;
	
	Account(const int accID, const char* name, const int money)
		:accID(accID), balance(money)
	{
		cusName = new char[strlen(name)+1];
		strcpy(cusName, name);
		return ;
	};
	~Account()
	{
		delete(cusName);
	}
	Account(const Account& targetAcc)
		:accID(targetAcc.accID), balance(targetAcc.balance)
	{
		cusName = new char[strlen(targetAcc.cusName)+1];
		strcpy(cusName, targetAcc.cusName);
	}
	int GetAccID() const
	{
		return this->accID;
	}
	int GetBalance() const
	{
		return this->balance;
	}
	char* GetName() const
	{
		return cusName;
	}
	int Withdrawal(const int money)
	{
		if(money > balance)
			return 0;
		balance -= money;
		return 1;
	}
	int Deposit(const int money)
	{
		balance += money;
		return 1;
	}
	void ShowAccInfo() const
	{
		cout<<"계좌ID : "<<accID<<endl;
		cout<<"이름 : "<<cusName<<endl;
		cout<<"입금액 : "<<balance<<endl<<endl;
	 return ;
	}
};

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
static Account* account[100];
int Account::accNum = 0;


int main(void)
{
	int choosenNum;
	
	while(1)
	{
		ShowMenu();
		cin>>choosenNum;
		switch(choosenNum)
		{
			case MAKE :
				OpenAccount();
				break;
			case DEPOSIT :
				Deposit();
				break;
			case WITHDRAW :
				Withdrawal();
				break;
			case INQUIRE :
				ShowAllAccount();
				break;
			case EXIT :
				return 0;
			default :
				cout<<"잘못된 입력입니다."<<endl<<endl;
		}
	}
	delete[](account);
	return 0;
}

void ShowMenu(void)
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
void OpenAccount(void)
{
	int accID, balance;
	char cusName[NAME_LEN];
	cout<<"----계좌 개설----"<<endl;
	cout<<"계좌ID : ";
	cin>>accID;
	cout<<"이름 : ";
	cin>>cusName;
	cout<<"입금액 : ";
	cin>>balance;
	account[Account::accNum++] = new Account(accID, cusName, balance);
	return ;
}
void Deposit(void)
{
	int accID, money;
	cout<<endl<<"-----입 금-----"<<endl;
	cout<<"계좌ID : ";
	cin>>accID;
	cout<<"입금액 : ";
	cin>>money;
	
	for(int i = 0; i < Account::accNum; i++)
	{
		if (account[i]->GetAccID() == accID)
		{
			account[i]->Deposit(money);
			cout<<"입금완료"<<endl;
			break;
		}
	}
	cout<<"ID오류"<<endl;
	
	return ;
}
void Withdrawal(void)
{
	int accID, money;
	cout<<endl<<"-----출 금-----"<<endl;
	cout<<"계좌ID : ";
	cin>>accID;
	cout<<"출금액 : ";
	cin>>money;
	
	for(int i = 0; i < Account::accNum; i++)
	{
		if (account[i]->GetAccID() == accID)
		{
			if (account[i]->GetBalance() >= money)
			{
				account[i]->Withdrawal(money);
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
void ShowAllAccount(void)
{
	cout<<endl<<"----계좌 출력----"<<endl;
	for(int i = 0; i < Account::accNum; i++)
	{
		account[i]->ShowAccInfo();
	}
}