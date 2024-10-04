#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{

	static clsCurrency _Get_Currency(string Message) {

		string CurrencyCode = clsInputValidate::ReadString(Message);

		while (!clsCurrency::Does_Currency_Exist(CurrencyCode)) {
			cout << "Currency Doesn't Exist!\n";
			CurrencyCode = clsInputValidate::ReadString("Enter another Currency Code: ");
		}

		return clsCurrency::Find_By_Code(CurrencyCode);

	}

	static void _Print_Currency(clsCurrency Currency , string Title = "Currency Card: ")
	{
		cout << "\n" << Title;
		cout << "\n_________________________________";
		cout << "\nCountry        : " << Currency.Country();
		cout << "\nCode           : " << Currency.CurrencyCode();
		cout << "\nName           : " << Currency.CurrencyName();
		cout << "\nRate(1$)       : " << Currency.Rate();
		cout << "\n_______________________________\n";

	}

	static void _Print_Calculation_Results(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount) {

		_Print_Currency(CurrencyFrom, "Convert From: ");
		float AmountInUSD = CurrencyFrom.Convert_To_USD(Amount);
		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << " USD\n";

		if (CurrencyTo.CurrencyCode() == "USD") {
			return;
		}

		_Print_Currency(CurrencyTo, "Converting From USD to: ");
		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << CurrencyTo.Convert_From_USD(AmountInUSD) << " " << CurrencyTo.CurrencyCode() << endl;

	}

public:

	static void Show_Currency_Calculator_Screen() {
		do {
			system("cls");
			clsScreen::_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency CurrencyFrom = _Get_Currency("Please enter currency code to change from: ");
			clsCurrency CurrencyTo = _Get_Currency("Please enter currency code to change to: ");

			float Amount = clsInputValidate::ReadFloatNumber("\nEnter amount to exchange: ");
			
			_Print_Calculation_Results(CurrencyFrom, CurrencyTo, Amount);

		} while (clsInputValidate::Are_You_Sure("Do you want to perform another calculation? "));
	}

};

