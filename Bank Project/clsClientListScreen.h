#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include "Global.h"

class clsClientListScreen : protected clsScreen
{
private:

	static void _PrintClientRecordLine(clsBankClient Client)
	{

		cout << "| " << setw(15) << left << Client.UserName();
		cout << "| " << setw(20) << left << Client.Full_Name();
		cout << "| " << setw(12) << left << Client.PhoneNumber;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}

public:

	static void Show_Client_List() {
		if (!_CheckAccessRights(clsUser::enPermissions::pListClients)) {
			return;
		}
		vector<clsBankClient> vClients = clsBankClient::Get_Clients_List();
		clsScreen::_DrawScreenHeader("\tClient List Screen","\t  (" + to_string(vClients.size()) + ") Client(s).");
		//cout << "\n" << clsUtil::Tab(5) << "Client List(" << vClients.size() << ") Client(s).\n";
		cout << clsString::Multiply_String("_", 100) << endl;
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance" << endl;
		cout << clsString::Multiply_String("_", 100) << endl;

		if (vClients.size() == 0) {
			cout << clsUtil::Tab(4) << "No Clients Available In The System!";
		}
		else {
			for (int i = 0; i < vClients.size(); i++) {
				_PrintClientRecordLine(vClients[i]);
				cout << endl;
			}
		}
		cout << clsString::Multiply_String("_", 100) << endl;

	}

};

