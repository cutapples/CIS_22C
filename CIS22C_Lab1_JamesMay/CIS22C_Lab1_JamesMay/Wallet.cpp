#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Wallet.h"

Wallet::Wallet() {
	this->Currencies = new Currency[0];
	this->Size = 0;
	this->IsEmpty = true;
	this->IsFull = false;
}

void Wallet::addCurrency(int currencyIndex, float userValue)  {
	this->Currencies[currencyIndex].addValue(userValue);
}

void Wallet::subCurrency(int currencyIndex, float userValue) {
	this->Currencies[currencyIndex].subValue(userValue);
}

void Wallet::createCurrency(int currencyType, float userValue) {
	if (this->IsFull) {
		throw WalletIsFull();
	}

	Currency tempCurrency;
	tempCurrency.setCurrency(currencyType, userValue);

	Currency *tempArray = new Currency[this->Size + 1];
	Currency *tempPtr = this->Currencies;

	for (int i = 0; i < this->Size; i++) {
		tempArray[i] = this->Currencies[i];
	}

	tempArray[this->Size] = tempCurrency;
	this->Currencies = tempArray;
	this->Size++;
	if (this->Size == this->MaxSize) {
		this->IsFull = true;
	}

	delete[] tempPtr;
}

void Wallet::deleteCurrency(int currencyType) {
	if (this->IsEmpty) {
		throw WalletIsEmpty();
	}

	int currencyIndex;

	//Check if the desired currency type is in the wallet
	try {
		Wallet::searchCurrency(currencyType, currencyIndex);
	}
	catch (Wallet::CurrencyNotFound) {
		throw;
	}

	//Move the to be deleted currency to the end of the array
	Currency tempCurrency = this->Currencies[currencyIndex];
	this->Currencies[currencyIndex] = this->Currencies[this->Size - 1];
	this->Currencies[this->Size - 1] = tempCurrency;

	//Create a temporary array to store the new set of currencies without the deleted one
	Currency *tempArray = new Currency[this->Size - 1];
	Currency *tempPtr = this->Currencies;

	//Copy the old array to the new one, stopping short of the deleted currency
	for (int i = 0; i < this->Size - 1; i++) {
		tempArray[i] = this->Currencies[i];
	}

	this->Currencies = tempArray;
	this->Size--;
	if (this->Size == 0) {
		this->IsEmpty = true;
	}

	delete[] tempPtr;
}



void Wallet::checkWallet() {
	std::cout << std::endl << "============================== myWallet Program ==============================" << std::endl
		<< "   This is the current contents of your wallet" << std::endl;
	std::cout << "==============================================================================" << std::endl;
	for (int i = 0; i < this->Size; i++) {
		std::cout << i + 1 << ") " << this->Currencies[i] << std::endl;
	}
	std::cout << "==============================================================================" << std::endl << std::endl;
}

void Wallet::emptyWallet() {
	delete[] this->Currencies;
	this->Currencies = new Currency[0];
	this->Size = 0;
	this->IsEmpty = true;
	this->IsFull = false;
}

bool Wallet::subCheck(int currencyIndex, float userValue) {
	if (this->Currencies[currencyIndex] < userValue) {
		return false;
	}
	return true;
}

bool Wallet::searchCurrency(int currencyType, int& currencyIndex) {
	for (currencyIndex = 0; currencyIndex < this->Size; currencyIndex++) {
		if (this->Currencies[currencyIndex] == currencyType) {
			return true;
		}
	}
	throw Wallet::CurrencyNotFound();
}

Wallet::~Wallet() {
	delete[] this->Currencies;
}