#include<iostream>
#include"1_class.h"

using namespace std;

FruitSeller::FruitSeller(int price, int num, int money)
{
	APPLE_PRICE = price;
	numOfApples = num;
	myMoney = money;
}
int FruitSeller::SaleApples(int money)
{
	if(money <= 0)
		return 0;
	int num = money/APPLE_PRICE;
	numOfApples -= num;
	myMoney += money;
	return num;
}
void FruitSeller::ShowSalesResult() const
{
	cout<<"남은 사과: "<<numOfApples<<endl;
	cout<<"판매 수익: "<<myMoney<<endl;
}


FruitBuyer::FruitBuyer(int money)
{
	numOfApples = 0;
	myMoney = money;
}
void FruitBuyer::BuyApples(FruitSeller &seller, int money)
{
	if(money <= 0)
		return ;
	numOfApples += seller.SaleApples(money);
	myMoney -= money;
}
void FruitBuyer::ShowBuyResult() const
{
	std::cout<<"현재 잔액: "<<myMoney<<std::endl;
	cout<<"사과 개수: "<<numOfApples<<endl;
}