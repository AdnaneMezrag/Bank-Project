#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsDeleteClientScreen : protected clsScreen
{
private:


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

	static void Show_Delete_Client_Screen() {
		if (!_CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
			return;
		}
		clsScreen::_DrawScreenHeader("\tDelete Client Screen");

		string AccountNumber = clsInputValidate::ReadString("Enter Client's Account Number: ");

		while (!clsBankClient::Does_Client_Exist("Clients.txt", AccountNumber)) {
			cout << "Account Number Doesn't Exist!\n";
			AccountNumber = clsInputValidate::ReadString("Enter Another Clients' Account Number: ");
		}

		clsBankClient Client = clsBankClient::Find("Clients.txt", AccountNumber);
		_Print_Client(Client);

		cout << "Are you sure you want to delete this client? y/n? ";
		char Answer;
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			if (Client.Delete()) {
				cout << "Client has been deleted successfully";
				_Print_Client(Client);
			}
			else {
				cout << "Error, Client has not been deleted";
			}
		}
		else {
			cout << "Client has not been deleted ";
		}
	}

};

