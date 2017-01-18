#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <math.h>
#include <iostream>
#include "Currency.h"

void splitParts(float& wholeParts, float& fractionalParts, float someValue) {
	fractionalParts = round(fmod((someValue * 100), 100));
	wholeParts = someValue - (fractionalParts / 100);
}

Currency::Currency() {
	this->WholeName = "";
	this->FractionalName = "";
	this->WholeParts = 0;
	this->FractionalParts = 0;
}

void Currency::setCurrency(int currencyType, float someValue) {
	this->WholeName = this->WholeArray[currencyType - 1];
	this->FractionalName = this->FractionalArray[currencyType - 1];
	this->addValue(someValue);
}

void Currency::addWhole(float wholeParts){
	this->WholeParts += wholeParts;
}

void Currency::addFractional(float fractionalParts){
	this->FractionalParts += fractionalParts;
	if (this->FractionalParts >= 100) {
		this->WholeParts++;
		this->FractionalParts -= 100;
	}
}

void Currency::subWhole(float wholeParts) {
	this->WholeParts -= wholeParts;
}

void Currency::subFractional(float fractionalParts) {
	if (this->FractionalParts < fractionalParts) {
		this->WholeParts--;
		this->FractionalParts += 100;
	}
	this->FractionalParts -= fractionalParts;
}

void Currency::addValue(float someValue) {
	float wholeParts, fractionalParts;
	splitParts(wholeParts, fractionalParts, someValue);
	Currency::addWhole(wholeParts);
	Currency::addFractional(fractionalParts);
}

void Currency::subValue(float someValue) {
	float wholeParts, fractionalParts;
	splitParts(wholeParts, fractionalParts, someValue);
	Currency::subWhole(wholeParts);
	Currency::subFractional(fractionalParts);
}

bool operator==(const Currency& currentCurrency, const int currencyType) {
		return (currentCurrency.WholeName == currentCurrency.WholeArray[currencyType - 1]);
}

bool operator<(const Currency& currentCurrency, const float someValue) {
	float whole, fractional;
	splitParts(whole, fractional, someValue);
	return ((currentCurrency.WholeParts < whole) || ((currentCurrency.WholeParts == whole) && (currentCurrency.FractionalParts < fractional)));
}

std::ostream& operator<<(std::ostream& os, const Currency& currency) {
	if (&os == &std::cout) {
		os << currency.WholeParts << " " << currency.WholeName << " and " << currency.FractionalParts << " " << currency.FractionalName << ".";
	}
	return os;
}