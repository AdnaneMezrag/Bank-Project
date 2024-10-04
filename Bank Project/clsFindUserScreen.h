#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsFindUserScreen : protected clsScreen
{

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

public:

	static void Show_Find_User_Screen() {

		clsScreen::_DrawScreenHeader("\tFind User Screen");

		string UserName = clsInputValidate::ReadString("Enter User's UserName: ");

		while (!clsUser::Does_User_Exist("Users.txt", UserName)) {
			cout << "UserName Doesn't Exist!\n";
			UserName = clsInputValidate::ReadString("Enter Another User's UserName: ");
		}

		clsUser User = clsUser::Find("Users.txt", UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser Was not Found :-(\n";
		}

		_Print_User(User);
	}

};

