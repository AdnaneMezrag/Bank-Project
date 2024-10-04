#pragma once
#include "clsScreen.h"
#include "clsUtil.h"

class clsLoginRegister : protected clsScreen
{

	static void _PrintUserRecordLineOfLogFile(clsUser User)
	{
		cout << "| " << setw(25) << left << User.DateTime();
		cout << "| " << setw(15) << left << User.UserName();
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;

	}

public:

	static void Login_Register() {
		if (!_CheckAccessRights(clsUser::enPermissions::PLoginRegister)) {
			return;
		}

		clsScreen::_DrawScreenHeader("\tLogin Register List Screen");

		vector<clsUser> vUsers = clsUser::Get_Users_List_Of_Log_File();

		cout << clsString::Multiply_String("_", 100) << endl;
		cout << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions" << endl;
		cout << clsString::Multiply_String("_", 100) << endl;

		if (vUsers.size() == 0) {
			cout << clsUtil::Tab(4) << "No Records Available In The System!";
		}
		else {
			for (int i = 0; i < vUsers.size(); i++) {
				_PrintUserRecordLineOfLogFile(vUsers[i]);
				cout << endl;
			}
		}
		cout << clsString::Multiply_String("_", 100) << endl;

	}

};

