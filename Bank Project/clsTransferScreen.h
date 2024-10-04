#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "Global.h"

class clsTransferScreen : protected clsScreen
{

	static void _Print_Client(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.Full_Name();
		cout << "\nAcc. Number : " << Client.UserName();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static clsBankClient _Read_Account_Number(string message) {

		string AccountNumber = clsInputValidate::ReadString(message);
		while (!clsBankClient::Does_Client_Exist("Clients.txt", AccountNumber)) {
			cout << "Account Number Doesn't Exist!\n";
			AccountNumber = clsInputValidate::ReadString("Enter Another Clients' Account Number: ");
		}

		return clsBankClient::Find("Clients.txt", AccountNumber);
	}

	static float _Read_Amount(clsBankClient ClientFrom) {

		double Amount = clsInputValidate::ReadPositiveDoubleNumber("Enter transfer amount: ");

		do {
			if (Amount <= ClientFrom.AccountBalance) {
				break;
			}
			cout << "Amount exceeds the available balance, ";
			Amount = clsInputValidate::ReadPositiveDoubleNumber("Enter another amount: ");

		} while (true);

		return Amount;
	}

	static clsBankClient::stTransferRegisterRecord _Fill_Record(double AccountDestinationBalance, string AccountNumberDestination, string AccountNumberSource, double AccountSourceBalance, string DateTime, double TransferedAmount, string UserName) {

		clsBankClient::stTransferRegisterRecord Record;

		Record.AccountDestinationBalance = AccountDestinationBalance;
		Record.AccountNumberDestination = AccountNumberDestination;
		Record.AccountNumberSource = AccountNumberSource;
		Record.AccountSourceBalance = AccountSourceBalance;
		Record.DateTime = DateTime;
		Record.TransferedAmount = TransferedAmount;
		Record.UserName = UserName;

		return Record;
	}

public:

	//Preconditions
	//Transfer from the account to the same account!

	static void Show_Transfer_Screen() {
		clsScreen::_DrawScreenHeader("\tTransfer Screen");

		//From
		clsBankClient ClientFrom = _Read_Account_Number("\nPlease enter account number to transfer from: ");
		_Print_Client(ClientFrom);

		//To
		clsBankClient ClientTo = _Read_Account_Number("\nPlease enter account number to transfer to: ");
		_Print_Client(ClientTo);

		//Amount
		double Amount = _Read_Amount(ClientFrom);

		if (clsInputValidate::Are_You_Sure("\nAre you sure you want to perform this transaction?")) {

			if (clsBankClient::Transfer(ClientFrom, ClientTo, Amount)) {
				//Here I should Add this transfer operation to a transfer log file
				clsBankClient::stTransferRegisterRecord Record;
				Record = _Fill_Record(ClientTo.AccountBalance, ClientTo.UserName(), ClientFrom.UserName(), ClientFrom.AccountBalance, clsDate::Get_Current_Date_And_Time(), Amount, CurrentUser.UserName());
				clsBankClient::Add_In_Transfer_Log_File(Record);
				cout << "\nAmount transered successfully!";
				_Print_Client(ClientFrom);
				cout << endl;
				_Print_Client(ClientTo);
			}
			else {
				cout << "Amount excceds the available balance";
			}

		}
		else {
			cout << "\nOperation has been canceled.\n";
		}



	}

};


