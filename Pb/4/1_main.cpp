#include<iostream>
#include"1_class.h"

int main()
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);
	buyer.BuyApples(seller, -1000);
	seller.ShowSalesResult();
	buyer.ShowBuyResult();
}