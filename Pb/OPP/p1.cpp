#include<iostream>
#include<cstdlib>

using std::cout;
using std::cin;
using std::endl;

void ShowMenu(void);
void OpenAccount(void);
void Deposit(void);
void Withdrawal(void);
void ShowAllAccount(void);


struct Account{
	int id;
	char name[20];
	int money;
};

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
static Account account[100];
static int accNum = 0;


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
	Account tmpacc;
	cout<<"----계좌 개설----"<<endl;
	cout<<"계좌ID : ";
	cin>>tmpacc.id;
	cout<<"이름 : ";
	cin>>tmpacc.name;
	cout<<"입금액 : ";
	cin>>tmpacc.money;
	account[accNum++] = tmpacc;
	
	return ;
}
void Deposit(void)
{
	int id, money;
	cout<<endl<<"-----입 금-----"<<endl;
	cout<<"계좌ID : ";
	cin>>id;
	cout<<"입금액 : ";
	cin>>money;
	
	for(int i = 0; i < accNum; i++)
	{
		if (account[i].id == id)
		{
			account[i].money += money;
			cout<<"입금완료"<<endl;
			break;
		}
	}
	cout<<"ID오류"<<endl;
	
	return ;
}
void Withdrawal(void)
{
	int id, money;
	cout<<endl<<"-----출 금-----"<<endl;
	cout<<"계좌ID : ";
	cin>>id;
	cout<<"출금액 : ";
	cin>>money;
	
	for(int i = 0; i < accNum; i++)
	{
		if (account[i].id == id && account[i].money >= money)
		{
			
			if (account[i].money >= money)
			{
				account[i].money -= money;
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
	for(int i = 0; i < accNum; i++)
	{
		cout<<"계좌ID : "<<account[i].id<<endl;
		cout<<"이름 : "<<account[i].name<<endl;
		cout<<"입금액 : "<<account[i].money<<endl<<endl;
	}
}