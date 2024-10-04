#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"

class clsTransferLogScreen : protected clsScreen
{

	static void _PrintTransferLogRecordLineOfLogFile(clsBankClient::stTransferRegisterRecord Record)
	{
		cout << "| " << setw(25) << left << Record.DateTime;
		cout << "| " << setw(10) << left << Record.AccountNumberSource;
		cout << "| " << setw(10) << left << Record.AccountNumberDestination;
		cout << "| " << setw(10) << left << Record.TransferedAmount;
		cout << "| " << setw(10) << left << Record.AccountSourceBalance;
		cout << "| " << setw(10) << left << Record.AccountDestinationBalance;
		cout << "| " << setw(10) << left << Record.UserName;

	}

public:

	static void Login_Register() {

		vector<clsBankClient::stTransferRegisterRecord> vTransferRecords = clsBankClient::Get_Transfer_Log_Vector_List_Of_Transfer_Log_File("TransferLog.txt");
		short VectorLength = vTransferRecords.size();
		string Subtitle = "\t    (" + to_string(VectorLength) + ") " + "Records.";
		clsScreen::_DrawScreenHeader("\tTransfer Log List Screen",Subtitle);

		cout << clsString::Multiply_String("_", 100) << endl;
		cout << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(10) << "S.Acct";
		cout << "| " << left << setw(10) << "D.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "D.Balance";
		cout << "| " << left << setw(10) << "User" << endl;


		cout << clsString::Multiply_String("_", 100) << endl;

		if (vTransferRecords.size() == 0) {
			cout << clsUtil::Tab(4) << "No Records Available In The System!";
		}
		else {
			for (int i = 0; i < vTransferRecords.size(); i++) {
				_PrintTransferLogRecordLineOfLogFile(vTransferRecords[i]);
				cout << endl;
			}
		}
		cout << clsString::Multiply_String("_", 100) << endl;

	}

};

