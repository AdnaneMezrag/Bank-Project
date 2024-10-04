#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

class clsFindClientScreen : protected clsScreen
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
	
	static void Show_Find_Client_Screen() {
		if (!_CheckAccessRights(clsUser::enPermissions::pFindClient)) {
			return;
		}
		clsScreen::_DrawScreenHeader("\tFind Client Screen");

		string AccountNumber = clsInputValidate::ReadString("Enter Client's Account Number: ");

		while (!clsBankClient::Does_Client_Exist("Clients.txt", AccountNumber)) {
			cout << "Account Number Doesn't Exist!\n";
			AccountNumber = clsInputValidate::ReadString("Enter Another Clients' Account Number: ");
		}

		clsBankClient Client = clsBankClient::Find("Clients.txt", AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}

		_Print_Client(Client);
	}

};

