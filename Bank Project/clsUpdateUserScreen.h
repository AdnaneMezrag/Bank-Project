#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsUpdateUserScreen : protected clsScreen
{

private:

	static void _Read_User_Info(clsUser& User) {

		User.FirstName = clsInputValidate::ReadString("Enter User's First Name: ");
		User.LastName = clsInputValidate::ReadString("Enter User's Last Name: ");
		User.Email = clsInputValidate::ReadString("Enter User's Email: ");
		User.PhoneNumber = clsInputValidate::ReadString("Enter User's Phone Number: ");
		User.Password = clsInputValidate::ReadString("Enter User's Password: ");
		User.Permissions = _ReadPermissionsToSet();

	}

	static void _Print_User(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.Full_Name();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.PhoneNumber;
		cout << "\nUserName    : " << User.UserName();
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

	static int _ReadPermissionsToSet()
	{

		int Permissions = 0;
		char Answer = 'n';


		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nLogin Register? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::PLoginRegister;
		}

		return Permissions;

	}

public:

	static void Show_Update_User_Screen() {

		clsScreen::_DrawScreenHeader("\tUpdate User Screen");

		string UserName = clsInputValidate::ReadString("Enter User's UserName: ");

		while (!clsUser::Does_User_Exist("Users.txt", UserName)) {
			cout << "UserName Doesn't Exist!\n";
			UserName = clsInputValidate::ReadString("Enter another User's UserName: ");
		}

		clsUser User = clsUser::Find("Users.txt", UserName);
		_Print_User(User);

		_Read_User_Info(User);

		clsUser::enSaveResults SaveResult;
		SaveResult = User.Save();
		if (SaveResult == clsUser::svFaildEmptyObject) {
			cout << "\nError User was not saved because it's Empty";
		}
		else {
			cout << "\nUser Updated Successfully :-)\n";
			_Print_User(User);
		}

	}

};

