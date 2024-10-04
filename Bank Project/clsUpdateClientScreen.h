#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsUpdateClientScreen : protected clsScreen
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

	static void _Read_Client_Info(clsBankClient& Client) {

		Client.FirstName = clsInputValidate::ReadString("Enter Client's First Name: ");
		Client.LastName = clsInputValidate::ReadString("Enter Client's Last Name: ");
		Client.Email = clsInputValidate::ReadString("Enter Client's Email: ");
		Client.PhoneNumber = clsInputValidate::ReadString("Enter Client's Phone Number: ");
		Client.PinCode = clsInputValidate::ReadString("Enter Client's Pin Code: ");
		Client.AccountBalance = clsInputValidate::ReadDoubleNumber("Enter Client's Balance: ");

	}

public:

	static void Show_Update_Client_Screen() {
		if (!_CheckAccessRights(clsUser::enPermissions::pUpdateClients)) {
			return;
		}
		clsScreen::_DrawScreenHeader("\tUpdate Client Screen");

		string AccountNumber = clsInputValidate::ReadString("Enter Client's Account Number: ");

		while (!clsBankClient::Does_Client_Exist("Clients.txt", AccountNumber)) {
			cout << "Account Number Doesn't Exist!\n";
			AccountNumber = clsInputValidate::ReadString("Enter Another Clients' Account Number: ");
		}

		clsBankClient Client = clsBankClient::Find("Clients.txt", AccountNumber);
		_Print_Client(Client);

		_Read_Client_Info(Client);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client.Save();
		if (SaveResult == clsBankClient::svFaildEmptyObject) {
			cout << "\nError account was not saved because it's Empty";
		}
		else {
			cout << "\nAccount Updated Successfully :-)\n";
			_Print_Client(Client);
		}

	}

};

