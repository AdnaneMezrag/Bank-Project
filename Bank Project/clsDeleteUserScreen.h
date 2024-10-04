#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsDeleteUserScreen : protected clsScreen
{
private:

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

	static void Show_Delete_User_Screen() {

		clsScreen::_DrawScreenHeader("\tDelete User Screen");

		string UserName = clsInputValidate::ReadString("Enter User's UserName: ");

		while (!clsUser::Does_User_Exist("Users.txt", UserName)) {
			cout << "UserName Doesn't Exist!\n";
			UserName = clsInputValidate::ReadString("Enter Another UserName: ");
		}

		clsUser User = clsUser::Find("Users.txt", UserName);
		_Print_User(User);

		cout << "Are you sure you want to delete this user? y/n? ";
		char Answer;
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			if (User.Delete()) {
				cout << "User has been deleted successfully";
				_Print_User(User);
			}
			else {
				cout << "Error, User has not been deleted";
			}
		}
		else {
			cout << "User has not been deleted ";
		}
	}

};

