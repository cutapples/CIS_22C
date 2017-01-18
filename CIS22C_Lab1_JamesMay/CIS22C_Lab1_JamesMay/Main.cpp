#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Wallet.h"
#include "Currency.h"

using namespace std;

/*
Green Text
*/

//Modules
void AddCurrencyScreen(Wallet&);
void AddingCurrencyScreen(Wallet&, int);
void CreateCurrencyScreen(Wallet&, int);
void SubCurrencyScreen(Wallet&);
void RemoveCurrencyScreen(Wallet&);
void CheckWalletScreen(Wallet&);
void EmptyWalletScreen(Wallet&);

int main() {

	Wallet myWallet;

	bool exit = false;

	do {

		int userChoice;

		cout << endl << "============================== myWallet Program ==============================" << endl
			<< "   Main Menu" << endl
			<< "==============================================================================" << endl << endl
			<< "1. Add Currency" << endl
			<< "2. Sub Currency" << endl
			<< "3. Remove Currency" << endl
			<< "4. Check Wallet" << endl
			<< "5. Empty Wallet" << endl
			<< "6. Exit" << endl << endl
			<< "Enter your choice: ";

		cin >> userChoice;
		cin.clear();
		cin.ignore(999, '\n');
		switch (userChoice) {
		case 1:
			system("cls");
			AddCurrencyScreen(myWallet);
			system("cls");
			break;
		case 2:
			system("cls");
			SubCurrencyScreen(myWallet);
			system("cls");
			break;
		case 3:
			system("cls");
			RemoveCurrencyScreen(myWallet);
			system("cls");
			break;
		case 4:
			system("cls");
			CheckWalletScreen(myWallet);
			system("cls");
			break;
		case 5:
			system("cls");
			EmptyWalletScreen(myWallet);
			system("cls");
			break;
		case 6:
			system("cls");
			cout << endl << "============================== myWallet Program ==============================" << endl
				<< "   Exiting Program" << endl
				<< "==============================================================================" << endl << endl;
			exit = true;
			break;
		default:
			system("cls");
			cout << endl << "============================== myWallet Program ==============================" << endl
				<< "   Invalid Choice" << endl
				<< "==============================================================================" << endl << endl;
			system("pause");
			break;
		}

	} while (!exit);
	system("Pause");
	return 0;

}

void AddCurrencyScreen(Wallet& myWallet) {

	int currencyIndex;
	int userChoice;

	cout << endl << "============================== myWallet Program ==============================" << endl
		<< "   Adding Currency" << endl
		<< "==============================================================================" << endl << endl
		<< "What kind of currency would you like to add?" << endl
		<< "1. USD ( Dollars, Cents )" << endl
		<< "2. EUR ( Euro, Pence )" << endl
		<< "3. MXN ( Pesos, Centavos )" << endl
		<< "4. GBP ( Pounds, Pence )" << endl
		<< "5. CHF ( Franken, Rappen )" << endl
		<< "Enter your choice: ";

	cin >> userChoice;
	cin.clear();
	cin.ignore(999, '\n');

	switch (userChoice) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		try {
			myWallet.searchCurrency(userChoice, currencyIndex);
		}
		catch (Wallet::CurrencyNotFound) {
			system("cls");
			cout << endl << "============================== myWallet Program ==============================" << endl
				<< "   Adding Currency" << endl
				<< "==============================================================================" << endl << endl
				<< "You do not currently have that type of currency in your wallet." << endl
				<< "Would you like to create that type of currency?" << endl
				<< "1. Yes" << endl
				<< "2. No" << endl << endl
				<< "Enter your choice: ";

			int userChoice2;

			cin >> userChoice2;
			cin.clear();
			cin.ignore(999, '\n');
			switch (userChoice2) {
			case 1:
				CreateCurrencyScreen(myWallet, userChoice);
				return;
			case 2:
				return;
			default:
				system("cls");
				cout << endl << "============================== myWallet Program ==============================" << endl
					<< "   Invalid Choice" << endl
					<< "==============================================================================" << endl << endl;
				system("pause");
				return;
			}
		}
		catch (...) {
			system("cls");
			cout << endl << "============================== myWallet Program ==============================" << endl
				<< "   Unexpected Error" << endl
				<< "==============================================================================" << endl << endl;
			system("pause");
			return;
		}
		AddingCurrencyScreen(myWallet, currencyIndex);
		return;
	default:
		system("cls");
		cout << endl << "============================== myWallet Program ==============================" << endl
			<< "   Invalid Choice" << endl
			<< "==============================================================================" << endl << endl;
		system("pause");
		return;
	}
}

void AddingCurrencyScreen(Wallet& myWallet, int currencyIndex) {
	system("cls");
	cout << endl << "============================== myWallet Program ==============================" << endl
		<< "   Adding Currency" << endl
		<< "==============================================================================" << endl << endl
		<< "How much money would you like to add of this type?" << endl << endl
		<< "Enter your value: ";

	float userChoice;
	cin >> userChoice;
	cin.clear();
	cin.ignore(999, '\n');

	myWallet.addCurrency(currencyIndex, userChoice);
}

void CreateCurrencyScreen(Wallet& myWallet, int currencyType) {
	system("cls");
	cout << endl << "============================== myWallet Program ==============================" << endl
		<< "   Creating Currency" << endl
		<< "==============================================================================" << endl << endl
		<< "How much money would you like to add of this type?" << endl << endl
		<< "Enter your value: ";

	float userValue;
	cin >> userValue;
	cin.clear();
	cin.ignore(999, '\n');
	try {
		myWallet.createCurrency(currencyType, userValue);
	}
	catch (Wallet::WalletIsFull) {
		system("cls");
		cout << endl << "============================== myWallet Program ==============================" << endl
			<< "   Creating Currency" << endl
			<< "==============================================================================" << endl << endl
			<< "Your wallet is currently full and you cannot create more currencies at the moment" << endl << endl;
		system("pause");
		return;
	}
	catch (...) {
		system("cls");
		cout << endl << "============================== myWallet Program ==============================" << endl
			<< "   Unexpected Error" << endl
			<< "==============================================================================" << endl << endl;
		system("pause");
		return;
	}
}

void SubCurrencyScreen(Wallet& myWallet) {

	cout << endl << "============================== myWallet Program ==============================" << endl
		<< "   Subtracting Currency" << endl
		<< "==============================================================================" << endl << endl
		<< "What kind of currency would you like to subtract?" << endl
		<< "1. USD ( Dollars, Cents )" << endl
		<< "2. EUR ( Euro, Pence )" << endl
		<< "3. MXN ( Pesos, Centavos )" << endl
		<< "4. GBP ( Pounds, Pence )" << endl
		<< "5. CHF ( Franken, Rappen )" << endl << endl
		<< "Enter your choice: ";

	int userChoice, currencyIndex;

	cin >> userChoice;
	cin.clear();
	cin.ignore(999, '\n');
	
	switch (userChoice) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		try {
			myWallet.searchCurrency(userChoice, currencyIndex);
		}
		catch (Wallet::CurrencyNotFound) {
			system("cls");
			cout << endl << "============================== myWallet Program ==============================" << endl
				<< "   Subtracting Currency" << endl
				<< "==============================================================================" << endl << endl
				<< "The type of currency you are trying to subtract is not currently in your wallet." << endl << endl;
			system("pause");
			return;
		}
		catch (...) {
			system("cls");
			cout << endl << "============================== myWallet Program ==============================" << endl
				<< "   Unexpected Error" << endl
				<< "==============================================================================" << endl << endl;
			system("pause");
			return;
		}
		break;
	default:
		system("cls");
		cout << endl << "============================== myWallet Program ==============================" << endl
			<< "   Invalid Choice" << endl
			<< "==============================================================================" << endl << endl;
		system("pause");
		return;
	}

	system("cls");
	cout << endl << "============================== myWallet Program ==============================" << endl
		<< "   Subtracting Currency" << endl
		<< "==============================================================================" << endl << endl
		<< "How much money would you like to subtract of this type?" << endl << endl
		<< "Enter your value: ";

	float userValue;
	cin >> userValue;
	cin.clear();
	cin.ignore(999, '\n');

	if (myWallet.subCheck(currencyIndex, userValue)) {
		myWallet.subCurrency(currencyIndex, userValue);
	}
	else {
		system("cls");
		cout << endl << "============================== myWallet Program ==============================" << endl
			<< "   Subtracting Currency" << endl
			<< "==============================================================================" << endl << endl
			<< "You cannot subtract more money from your wallet than you currently own." << endl << endl;
		system("pause");
		return;
	}
}


void RemoveCurrencyScreen(Wallet& myWallet) {

	cout << endl << "============================== myWallet Program ==============================" << endl
		<< "   Removing Currency" << endl
		<< "==============================================================================" << endl << endl
		<< "What kind of currency would you like to remove?" << endl
		<< "1. USD ( Dollars, Cents )" << endl
		<< "2. EUR ( Euro, Pence )" << endl
		<< "3. MXN ( Pesos, Centavos )" << endl
		<< "4. GBP ( Pounds, Pence )" << endl
		<< "5. CHF ( Franken, Rappen )" << endl << endl
		<< "Enter your choice: ";

	int userChoice;

	cin >> userChoice;
	cin.clear();
	cin.ignore(999, '\n');

	switch (userChoice) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		try {
			myWallet.deleteCurrency(userChoice);
		}
		catch (Wallet::WalletIsEmpty) {
			system("cls");
			cout << endl << "============================== myWallet Program ==============================" << endl
				<< "   Removing Currency" << endl
				<< "==============================================================================" << endl << endl
				<< "Your wallet is currently empty and there is nothing to remove." << endl << endl;
			system("pause");
			return;
		}
		catch (Wallet::CurrencyNotFound) {
			system("cls");
			cout << endl << "============================== myWallet Program ==============================" << endl
				<< "   Removing Currency" << endl
				<< "==============================================================================" << endl << endl
				<< "The type of currency you are trying to remove is not currently in your wallet." << endl << endl;
			system("pause");
			return;
		}
		catch (...) {
			system("cls");
			cout << endl << "============================== myWallet Program ==============================" << endl
				<< "   Unexpected Error" << endl
				<< "==============================================================================" << endl << endl;
			system("pause");
			return;
		}
	default:
		system("cls");
		cout << endl << "============================== myWallet Program ==============================" << endl
			<< "   Invalid Choice" << endl
			<< "==============================================================================" << endl << endl;
		system("pause");
		return;
	}
}


void CheckWalletScreen(Wallet& myWallet) {
	myWallet.checkWallet();
	system("pause");
}


void EmptyWalletScreen(Wallet& myWallet) {
	cout << endl << "============================== myWallet Program ==============================" << endl
		<< "   Emptying wallet..." << endl
		<< "==============================================================================" << endl << endl;
	myWallet.emptyWallet();
	system("pause");
}

