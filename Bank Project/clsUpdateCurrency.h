#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsUpdateCurrency : protected clsScreen
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

public:

	static void Show_Update_Currency_Screen() {
		clsScreen::_DrawScreenHeader("\tUpdate Currency Screen");

		string CurrencyCode = clsInputValidate::ReadString("Please Enter Currency Code: ");

		while (!clsCurrency::Does_Currency_Exist(CurrencyCode)) {
			cout << "Currency Doesn't Exist!\n";
			CurrencyCode = clsInputValidate::ReadString("Enter another Currency Code: ");
		}

		clsCurrency Currency = clsCurrency::Find_By_Code(CurrencyCode);
		_Print_Currency(Currency);

		if (clsInputValidate::Are_You_Sure("Are you sure you want to update the rate of this currency?")) {
			float CurrencyRate = clsInputValidate::ReadFloatNumber("Enter New Currency Rate: ");
			Currency.Update_Rate(CurrencyRate);
			_Print_Currency(Currency);
			cout << "\nCurrency has been updated successfully :-)\n";

		}
		else {
			cout << "\nCurrency hasn't been updated\n";
		}

	}

};

