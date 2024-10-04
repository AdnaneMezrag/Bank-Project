#pragma once
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
	
	static bool _Login() {
		short Trials = 2;
		do {
			string UserName = clsInputValidate::ReadString("Enter UserName: ");
			string Password = clsInputValidate::ReadString("Enter Password: ");
			CurrentUser = clsUser::Find("Users.txt", UserName, Password);
			if (!CurrentUser.IsEmpty()) {
				CurrentUser.Save_User_In_Log_File();
				clsMainScreen::Show_Main_Menue();
				return true;
			}
			cout << "\nInvalid UserName/Password\n";
			cout << "You have " << Trials << " trials to login\n\n";
			Trials--;
			if (Trials == -1) {
				cout << "\nYou are locked after 3 faild trails\n\n";
				return false;
			}
		} while (true);

	}

public:

	static bool Login_Screen() {
		system("cls");
		_DrawScreenHeader("\t\tLogin Screen");
		return _Login();
	}


};

