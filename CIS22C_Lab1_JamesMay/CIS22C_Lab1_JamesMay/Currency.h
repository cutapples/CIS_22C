#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>

class Currency {
private:

	std::string WholeName;
	std::string FractionalName;
	float WholeParts;
	float FractionalParts;
	std::string WholeArray[5] = {"Dollar(s)", "Euro", "Peso(s)", "Pound(s)", "Franc(Franken)"};
	std::string FractionalArray[5] = {"Cent(s)", "Pence", "Centavo(s)", "Pence", "Rappen"};

public:
	Currency();

	void setCurrency(int currencyType, float someValue);
	void addWhole(float wholeParts);
	void addFractional(float fractionalParts);
	void subWhole(float wholeParts);
	void subFractional(float fractionalParts);
	void addValue(float someValue);
	void subValue(float someValue);

	friend bool operator==(const Currency& currentCurrency, const int currencyType);
	friend bool operator<(const Currency& currentCurrency, const float someValue);
	friend std::ostream& operator<< (std::ostream&, const Currency&);
};

#endif CURRENCY_H