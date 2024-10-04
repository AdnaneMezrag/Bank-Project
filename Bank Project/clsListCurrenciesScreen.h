#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsUtil.h"

class clsListCurrenciesScreen : protected clsScreen
{

	static void _PrintCurrencyRecordLine(clsCurrency Currency) {
		cout << "| " << setw(35) << left << Currency.Country();
		cout << "| " << setw(15) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(15) << left << Currency.Rate();
	}

public:

	static void Show_List_Currencies_Screen() {

		vector<clsCurrency> vCurrencies = clsCurrency::Get_Currencies_List();
		clsScreen::_DrawScreenHeader("\tCurrency List Screen", "\t  (" + to_string(vCurrencies.size()) + ") Currencies.");
		//cout << "\n" << clsUtil::Tab(5) << "Client List(" << vClients.size() << ") Client(s).\n";
		cout << clsString::Multiply_String("_", 115) << endl;
		cout << "| " << left << setw(35) << "Country";
		cout << "| " << left << setw(15) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(15) << "Rate/(1$)" << endl;
		cout << clsString::Multiply_String("_", 115) << endl;

		if (vCurrencies.size() == 0) {
			cout << clsUtil::Tab(4) << "No Currencies Available In The System!";
		}
		else {
			for (int i = 0; i < vCurrencies.size(); i++) {
				_PrintCurrencyRecordLine(vCurrencies[i]);
				cout << endl;
			}
		}
		cout << clsString::Multiply_String("_", 115) << endl;

	}

};

