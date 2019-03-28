#include<iostream>
#include<cstring>

using namespace std;

class Book
{
	private:
		char *title;
		char *isbn;
		int price;
	public:
		Book(char *title, char *isbn, int price) : price(price)
		{
			this->title = new char[strlen(title)+1];
			strcpy(this->title, title);
			this->isbn = new char[strlen(isbn)+1];
			strcpy(this->isbn, isbn);
			return ;
		}
		void ShowBookInfo()
		{
			cout<<title<<" / "<<isbn<<" / "<<price<<endl;
			return ;
		}
		Book& operator=(const Book& book2)
		{
			this->price = book2.price;
			delete []this->title;
			delete []this->isbn;
			this->title = new char[strlen(book2.title)+1];
			strcpy(this->title, book2.title);
			this->isbn = new char[strlen(book2.isbn)+1];
			strcpy(this->isbn, book2.isbn);
			return *this;
		}
};

class EBook : public Book
{
	private:
		char *DRMKey;
	public:
		EBook(char *title, char *isbn, int price, char *drmKey) : Book(title, isbn, price)
		{
			this->DRMKey = new char[strlen(drmKey)+1];
			strcpy(this->DRMKey, drmKey);
			return ;
		}
		void ShowEBookInfo()
		{
			ShowBookInfo();
			cout<<" / "<<DRMKey<<endl;
			return ;
		}
};

int main(void)
{
	Book book("좋은 C++", "55123456", 20000);
	book.ShowBookInfo();
	cout<<endl;
	EBook ebook("좋은 C++ ebook", "55123457", 10000, "fdfsfgs");
	ebook.ShowEBookInfo();
	return 0;	
}