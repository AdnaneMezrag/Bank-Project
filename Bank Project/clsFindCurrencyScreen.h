#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
{

	static void _Print_Currency(clsCurrency Currency)
	{
		cout << "\Currency Card:";
		cout << "\n_________________________________";
		cout << "\nCountry        : " << Currency.Country();
		cout << "\nCode           : " << Currency.CurrencyCode();
		cout << "\nName           : " << Currency.CurrencyName();
		cout << "\nRate(1$)       : " << Currency.Rate();
		cout << "\n_______________________________\n";

	}

	static void _Show_Results(clsCurrency Currency) {
		if (Currency.Is_Empty()) {
			cout << "Currency Was Not Found :-(\n";
		}
		else {
			cout << "Currency Found :-)\n";
			_Print_Currency(Currency);
		}
	}

public:

	static void Show_Find_Currency_Screen() {

		clsScreen::_DrawScreenHeader("\tFind Currency Screen");

		short FindChoice = clsInputValidate::ReadIntNumber("Find By: [1] Code or [2] Country ? ");
		if (FindChoice == 1) {
			string Code = clsInputValidate::ReadString("Please Enter Currency Code: ");
			clsCurrency Currency = clsCurrency::Find_By_Code(Code);
			_Show_Results(Currency);
		}

		else {
			string Country = clsInputValidate::ReadString("Please Enter Country Name: ");
			clsCurrency Currency = clsCurrency::Find_By_Country(Country);
			_Show_Results(Currency);
		}
	}

};

