using namespace std;

class FruitSeller
{
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
	public:
		FruitSeller(int price, int num, int money);
		int SaleApples(int money);
		void ShowSalesResult() const;
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;
	public:
		FruitBuyer(int money);
		void BuyApples(FruitSeller &seller, int money);
		void ShowBuyResult() const;
};