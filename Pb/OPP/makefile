BankingSystemMain : BankingSystemMain.o Account.o NormalAccount.o HighCreditAccount.o AccountHandler.o BoundCheckArray.o  String.o AccountException.o
	g++ -o BankingSystem BankingSystemMain.o Account.o NormalAccount.o HighCreditAccount.o AccountHandler.o BoundCheckArray.o String.o AccountException.o

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


BoundCheckArray.o : BoundCheckArray.cpp
	g++ -c BoundCheckArray.cpp


String.o : String.cpp
	g++ -c String.cpp
	
AccountException.o : AccountException.cpp
	g++ -c AccountException.cpp

clean:
	rm -f BankingSystemMain.o Account.o NormalAccount.o HighCreditAccount.o AccountHandler.o BoundCheckArray.o String.o AccountException.o