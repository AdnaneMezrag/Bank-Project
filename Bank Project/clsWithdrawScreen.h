#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

class clsWithdrawScreen : protected clsScreen
{

	static void _Print_Client(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.Full_Name();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.PhoneNumber;
		cout << "\nAcc. Number : " << Client.UserName();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public:

	static void Show_Withdraw_Screen() {

		clsScreen::_DrawScreenHeader("\tWithdraw Client Screen");

		string AccountNumber = clsInputValidate::ReadString("Enter Client's Account Number: ");

		while (!clsBankClient::Does_Client_Exist("Clients.txt", AccountNumber)) {
			cout << "Account Number Doesn't Exist!\n";
			AccountNumber = clsInputValidate::ReadString("Enter Another Clients' Account Number: ");
		}

		clsBankClient Client = clsBankClient::Find("Clients.txt", AccountNumber);
		_Print_Client(Client);

		double Amount = clsInputValidate::ReadDoubleNumberFromTo("Enter a withdraw amount: ",0);
		if (clsInputValidate::Are_You_Sure("Are you sure you want to perform this transaction?")) {
			if (Client.Withdraw(Amount)) {
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance << endl;
			}
			else {
				cout << "\nCannot Withdraw, Insufficient Balance!\n";
				cout << "\nAmount to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client.AccountBalance;
			}

		}
		else {
			cout << "\nOperation was canceled.\n";
		}
	}

};

