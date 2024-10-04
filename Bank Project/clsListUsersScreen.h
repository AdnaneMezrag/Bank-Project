#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsUser.h"

class clsListUsersScreen : protected clsScreen
{

	static void _PrintUserRecordLine(clsUser User)
	{

		cout << "| " << setw(15) << left << User.UserName();
		cout << "| " << setw(20) << left << User.Full_Name();
		cout << "| " << setw(12) << left << User.PhoneNumber;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;

	}

public:

	static void Show_User_List() {
		vector<clsUser> vUsers = clsUser::Get_Users_List();
		clsScreen::_DrawScreenHeader("\tUser List Screen", "\t  (" + to_string(vUsers.size()) + ") User(s).");
		//cout << "\n" << clsUtil::Tab(5) << "Client List(" << vClients.size() << ") Client(s).\n";
		cout << clsString::Multiply_String("_", 100) << endl;
		cout << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions" << endl;
		cout << clsString::Multiply_String("_", 100) << endl;

		if (vUsers.size() == 0) {
			cout << clsUtil::Tab(4) << "No Users Available In The System!";
		}
		else {
			for (int i = 0; i < vUsers.size(); i++) {
				_PrintUserRecordLine(vUsers[i]);
				cout << endl;
			}
		}
		cout << clsString::Multiply_String("_", 100) << endl;

	}

};

