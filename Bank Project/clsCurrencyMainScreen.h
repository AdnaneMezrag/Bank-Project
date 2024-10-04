#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrency.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyMainScreen : protected clsScreen
{

    enum enCurrencyExchangeOption {
        eListCurrencies = 1 , eFindCurrency = 2 , eUpdateRate = 3 , eCurrencyCalculator = 4 , eMainMenue = 5
    };

    static short _Read_Currency_Exchange_Menue_Option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadIntNumberFromTo("Enter Number between 1 to 5? ", 1, 5);
        return Choice;
    }

    static void _Go_Back_To_Currency_Exchange_Menue() {

        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        Show_Currency_Main_Screen();
    }

    static void _Show_Currencies_List_Screen() {
        //cout << "Currencies List Screen Will Be Here Soon . . . \n";
        clsListCurrenciesScreen::Show_List_Currencies_Screen();
    }

    static void _Show_Find_Currency_Screen() {
        //cout << "Find Currency Screen Will Be Here Soon . . . \n";
        clsFindCurrencyScreen::Show_Find_Currency_Screen();
    }

    static void _Show_Update_Currency_Screen() {
        //cout << "Update Currency Screen Will Be Here Soon . . . \n";
        clsUpdateCurrency::Show_Update_Currency_Screen();
    }

    static void _Show_Currency_Calculator_Screen() {
        //cout << "Currency Calculator Screen Will Be Here Soon . . . \n";
        clsCurrencyCalculatorScreen::Show_Currency_Calculator_Screen();
    }

    static void _Perform_Currency_Exchange_Option(enCurrencyExchangeOption CurrencyExchangeOption) {

        switch (CurrencyExchangeOption)
        {
        case clsCurrencyMainScreen::eListCurrencies:
            system("cls");
            _Show_Currencies_List_Screen();
            _Go_Back_To_Currency_Exchange_Menue();
            break;

        case clsCurrencyMainScreen::eFindCurrency:
            system("cls");
            _Show_Find_Currency_Screen();
            _Go_Back_To_Currency_Exchange_Menue();
            break;

        case clsCurrencyMainScreen::eUpdateRate:
            system("cls");
            _Show_Update_Currency_Screen();
            _Go_Back_To_Currency_Exchange_Menue();
            break;

        case clsCurrencyMainScreen::eCurrencyCalculator:
            system("cls");
            _Show_Currency_Calculator_Screen();
            _Go_Back_To_Currency_Exchange_Menue();
            break;

        case clsCurrencyMainScreen::eMainMenue:
            break;
        default:
            break;
        }
    }


public:

	static void Show_Currency_Main_Screen() {
		system("cls");
		clsScreen::_DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _Perform_Currency_Exchange_Option(enCurrencyExchangeOption(_Read_Currency_Exchange_Menue_Option()));

	}

};

