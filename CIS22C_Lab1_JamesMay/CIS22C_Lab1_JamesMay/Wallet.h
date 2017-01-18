#ifndef WALLET_H
#define WALLET_H
#include "Currency.h"

class Wallet {
private:
	Currency *Currencies;
	int Size;
	const int MaxSize = 5;
	bool IsEmpty;
	bool IsFull;

public:
	Wallet();

	void addCurrency(int currencyIndex, float userValue);
	void subCurrency(int currencyIndex, float userValue);
	void createCurrency(int currencyType, float userValue);
	void deleteCurrency(int currencyType);

	void checkWallet();
	void emptyWallet();

	bool subCheck(int currencyIndex, float userValue);
	bool searchCurrency(int currencyType, int& currencyIndex);

	class CurrencyNotFound { };
	class WalletIsFull { };
	class WalletIsEmpty { };

	~Wallet();
};

#endif WALLET_H