class BBB
{
	private:
		int num;
	public:
		BBB(int n) :num(n) {}
};

class AAA
{
	private:
		BBB bbb;
	public:
		AAA(int n)
			:bbb(n)
		{
		}
		~AAA()
		{
			///delete bbb;
		}
};

int main()
{
	AAA *aaa;
	while(1)
	{
		aaa = new AAA(0);
		delete aaa;
	}
}