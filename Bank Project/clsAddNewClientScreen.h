#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"


class clsAddNewClientScreen : protected clsScreen
{

private:

	static void _Read_Client_Info(clsBankClient& Client) {

		Client.FirstName = clsInputValidate::ReadString("Enter Client's First Name: ");
		Client.LastName = clsInputValidate::ReadString("Enter Client's Last Name: ");
		Client.Email = clsInputValidate::ReadString("Enter Client's Email: ");
		Client.PhoneNumber = clsInputValidate::ReadString("Enter Client's Phone Number: ");
		Client.PinCode = clsInputValidate::ReadString("Enter Client's Pin Code: ");
		Client.AccountBalance = clsInputValidate::ReadDoubleNumber("Enter Client's Balance: ");

	}

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

	static void Add_New_Client() {
		if (!_CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
			return;
		}
		clsScreen::_DrawScreenHeader("\tAdd New Client Screen");
		string AccountNumber = clsInputValidate::ReadString("Enter Client's Account Number: ");

		while (clsBankClient::Does_Client_Exist("Clients.txt", AccountNumber)) {
			cout << "Account Number Exists!\n";
			AccountNumber = clsInputValidate::ReadString("Enter Another Clients' Account Number: ");
		}

		clsBankClient Client = clsBankClient::Get_Add_New_Client_Object(AccountNumber);

		_Read_Client_Info(Client);
		clsBankClient::enSaveResults SaveResult = Client.Save();


		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Added Successfully :-)\n";
			_Print_Client(Client);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
		}


	}

};

