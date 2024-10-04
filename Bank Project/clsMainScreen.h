#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegister.h"
#include "clsCurrencyMainScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8,eCurrencyExchange = 9,eExit = 10
    };

    static short _Read_Main_Menue_Option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadIntNumberFromTo("Enter Number between 1 to 10? ",1,10);
        return Choice;
    }

    static void _Go_Back_To_Main_Menue() {

        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        Show_Main_Menue();
    }

    static void _Show_All_Clients_Screen() {
        //cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::Show_Client_List();
    }

    static void _Show_Add_New_Clients_Screen() {
        //cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::Add_New_Client();
    }

    static void _Show_Delete_Client_Screen() {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::Show_Delete_Client_Screen();
    }

    static void _Show_Update_Client_Screen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::Show_Update_Client_Screen();
    }

    static void _Show_Find_Client_Screen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::Show_Find_Client_Screen();
    }

    static void _Show_Transactions_Menue()
    {
        //cout << "\nTransactions Menue Will be here...\n";
        clsTransactionsScreen::Show_Transactions_Menue();
    }

    static void _Show_Manage_Users_Menue()
    {
        //cout << "\nUsers Menue Will be here...\n";
        clsManageUsersScreen::Show_Manage_Users_Menue();
    }

    static void _Show_Login_Register_Screen() {
        clsLoginRegister::Login_Register();
    }

    static void _Show_Currency_Exchange_Screen() {
        clsCurrencyMainScreen::Show_Currency_Main_Screen();
    }

    static void _Logout() {
        CurrentUser = clsUser::Find("Users.txt", "", "");
    }

    static void _Perform_Main_Menue_Option(enMainMenueOptions MainMenueOption) {
        switch (MainMenueOption)
        {

        case clsMainScreen::eListClients:
            system("cls");
            _Show_All_Clients_Screen();
            _Go_Back_To_Main_Menue();
            break;

        case clsMainScreen::eAddNewClient:
            system("cls");
            _Show_Add_New_Clients_Screen();
            _Go_Back_To_Main_Menue();
            break;

        case clsMainScreen::eDeleteClient:
            system("cls");
            _Show_Delete_Client_Screen();
            _Go_Back_To_Main_Menue();
            break;

        case clsMainScreen::eUpdateClient:
            system("cls");
            _Show_Update_Client_Screen();
            _Go_Back_To_Main_Menue();
            break;

        case clsMainScreen::eFindClient:
            system("cls");
            _Show_Find_Client_Screen();
            _Go_Back_To_Main_Menue();

            break;

        case clsMainScreen::eShowTransactionsMenue:
            system("cls");
            _Show_Transactions_Menue();
            _Go_Back_To_Main_Menue();

            break;

        case clsMainScreen::eManageUsers:
            system("cls");
            _Show_Manage_Users_Menue();
            _Go_Back_To_Main_Menue();

            break;

        case clsMainScreen::eLoginRegister:
            system("cls");
            _Show_Login_Register_Screen();
            _Go_Back_To_Main_Menue();

            break;

        case clsMainScreen::eCurrencyExchange:
            system("cls");
            _Show_Currency_Exchange_Screen();
            _Go_Back_To_Main_Menue();

            break;


        case clsMainScreen::eExit:
            system("cls");
            _Logout();
            break;

        default:
            break;
        }
    }

public:

	static void Show_Main_Menue() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _Perform_Main_Menue_Option((enMainMenueOptions)_Read_Main_Menue_Option());
	}


};

