BankingSystemMain : BankingSystemMain.o Account.o NormalAccount.o HighCreditAccount.o AccountHandler.o
	g++ -o BankingSystem BankingSystemMain.o Account.o NormalAccount.o HighCreditAccount.o AccountHandler.o

BankingSystemMain.o : BankingSystemMain.cpp
	g++ -c BankingSystemMain.cpp
	
Account.o : Account.cpp
	g++ -c Account.cpp

NormalAccount.o : NormalAccount.cpp
	g++ -c NormalAccount.cpp


HighCreditAccount.o : HighCreditAccount.cpp
	g++ -c HighCreditAccount.cpp


AccountHandler.o : AccountHandler.cpp
	g++ -c AccountHandler.cpp