#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : protected clsScreen
{

private:

    enum enTransactionMenueOptions {
        eDeposit = 1 , eWithdraw = 2 , eTotalBalance = 3 , eTransfer = 4 ,eTransferLog = 5 ,eMainMenue = 6
    };

    static short _Read_Transactions_Menue_Option() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberFromTo("Enter Number between 1 to 6? ", 1, 6);
        return Choice;
    }

    static void _Go_Back_To_Transactions_Menue() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        Show_Transactions_Menue();
    }

    static void _Show_Deposit_Screen() {
        //cout << "\nDeposit Screen Will Be Here...\n";
        clsDepositScreen::Show_Deposit_Screen();
    }

    static void _Show_Withdraw_Screen() {
        //cout << "\Withdraw Screen Will Be Here...\n";
        clsWithdrawScreen::Show_Withdraw_Screen();
    }

    static void _Show_Total_Balances_Screen() {
        //cout << "\Total Balances Screen Will Be Here...\n";
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _Show_Transfer_Screen() {
       clsTransferScreen::Show_Transfer_Screen();
    }

    static void _Show_Transfer_Log_Screen() {
        //cout << "Transfer Log Screen Will Be Here!\n";
        clsTransferLogScreen::Login_Register();
    }

    static void _Perform_Transaction_Menue_Option(enTransactionMenueOptions TransactionMenueOption) {
        switch (TransactionMenueOption)
        {

        case clsTransactionsScreen::eDeposit:
            system("cls");
            _Show_Deposit_Screen();
            _Go_Back_To_Transactions_Menue();
            break;

        case clsTransactionsScreen::eWithdraw:
            system("cls");
            _Show_Withdraw_Screen();
            _Go_Back_To_Transactions_Menue();
            break;

        case clsTransactionsScreen::eTotalBalance:
            system("cls");
            _Show_Total_Balances_Screen();
            _Go_Back_To_Transactions_Menue();
            break;

        case clsTransactionsScreen::eTransfer:
            system("cls");
            _Show_Transfer_Screen();
            _Go_Back_To_Transactions_Menue();
            break;

        case clsTransactionsScreen::eTransferLog:
            system("cls");
            _Show_Transfer_Log_Screen();
            _Go_Back_To_Transactions_Menue();
            break;

        case clsTransactionsScreen::eMainMenue:
            //clsMainScreen::Show_Main_Menue();
            break;

        default:
            break;
        }
    }

public:

	static void Show_Transactions_Menue() {
        if (!_CheckAccessRights(clsUser::enPermissions::pTranactions)) {
            return;
        }
		system("cls");
		clsScreen::_DrawScreenHeader("\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";

        _Perform_Transaction_Menue_Option((enTransactionMenueOptions)_Read_Transactions_Menue_Option());

	}

};

