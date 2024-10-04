#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"

using namespace std;

class clsBankClient : public clsPerson
{

	enum enMode {
		EmptyMode = 0 , UpdateMode = 1 , AddNewMode = 2
	};

    struct stTransferRegisterRecord;

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

    bool _MarkForDelete = false;

    static clsBankClient _Convert_Line_To_Client_Object(string Line, string Delim = "#//#") {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Delim);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static vector<clsBankClient> _Load_Clients_Data_From_File(string FileName) {
        vector <clsBankClient> vClients;
        fstream ClientsFile;
        ClientsFile.open(FileName, ios::in);
        if (ClientsFile.is_open()) {
            string Line;

            while (getline(ClientsFile, Line)) {
                clsBankClient Client = _Convert_Line_To_Client_Object(Line);
                vClients.push_back(Client);
            }
            ClientsFile.close();
        }
        return vClients;

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", -1);
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.PhoneNumber + Seperator;
        stClientRecord += Client.UserName() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.MarkForDelete() == false) {
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();

        }

    }

    void _Update() {
        vector <clsBankClient> vClients = _Load_Clients_Data_From_File("Clients.txt");
        for (clsBankClient& C : vClients) {
            if (C._AccountNumber == _AccountNumber) {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(vClients);
    }

    void _Add_Data_Line_To_File(string Line) {
        fstream File;
        File.open("Clients.txt", ios::out | ios::app);
        if (File.is_open()) {
            File << Line << endl;
            File.close();
        }
    }

    void _Add_New() {
        _Add_Data_Line_To_File(_ConvertClientObjectToLine(*this));
    }


    //Transfer Log File

    static string _ConvertTransferRegisterRecordStructToLine(stTransferRegisterRecord Record, string Seperator = "#//#")
    {
        string TransferLogRecord = "";
        TransferLogRecord += Record.DateTime + Seperator;
        TransferLogRecord += Record.AccountNumberSource + Seperator;
        TransferLogRecord += Record.AccountNumberDestination + Seperator;
        TransferLogRecord += to_string(Record.TransferedAmount) + Seperator;
        TransferLogRecord += to_string(Record.AccountSourceBalance) + Seperator;
        TransferLogRecord += to_string(Record.AccountDestinationBalance) + Seperator;
        TransferLogRecord += Record.UserName;

        return TransferLogRecord;

    }

    static void _Add_Data_Line_To_Transfer_Log_File(string Line) {
        fstream File;
        File.open("TransferLog.txt", ios::out | ios::app);
        if (File.is_open()) {
            File << Line << endl;
            File.close();
        }
    }

    static void _Add_New_To_Transfer_Log_File(stTransferRegisterRecord Record) {
        _Add_Data_Line_To_Transfer_Log_File(_ConvertTransferRegisterRecordStructToLine(Record));
    }


    //List Transfer Log 
    static stTransferRegisterRecord _Convert_Line_To_Transfer_Log_Record(string Line, string Delim = "#//#") {
        stTransferRegisterRecord Record;
        vector<string> vTransferRecrds;
        vTransferRecrds = clsString::Split(Line, Delim);

        Record.DateTime = vTransferRecrds[0];
        Record.AccountNumberSource = vTransferRecrds[1];
        Record.AccountNumberDestination = vTransferRecrds[2];
        Record.TransferedAmount = stod(vTransferRecrds[3]);
        Record.AccountSourceBalance = stod( vTransferRecrds[4]);
        Record.AccountDestinationBalance = stod(vTransferRecrds[5]);
        Record.UserName = vTransferRecrds[6];

        return Record;
    }

    static vector<stTransferRegisterRecord> _Load_Transfer_Records_From_File(string FileName) {
        vector <stTransferRegisterRecord> vTransferRecords;
        fstream TransferLogFile;
        TransferLogFile.open(FileName, ios::in);
        if (TransferLogFile.is_open()) {
            string Line;

            while (getline(TransferLogFile, Line)) {
                stTransferRegisterRecord Record = _Convert_Line_To_Transfer_Log_Record(Line);
                vTransferRecords.push_back(Record);
            }
            TransferLogFile.close();
        }
        return vTransferRecords;

    }

public:

    struct stTransferRegisterRecord {
        string DateTime;
        string AccountNumberSource;
        string AccountNumberDestination;
        double TransferedAmount;
        double AccountSourceBalance;
        double AccountDestinationBalance;
        string UserName;
    };

    //Constructors
    clsBankClient() {}

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber,
		string AccountNumber, string PinCode, float AccountBalance):clsPerson(FirstName, LastName, Email, PhoneNumber) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    //Setters and Getters
    string UserName()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    bool MarkForDelete() {
        return _MarkForDelete;
    }
    void SetMarkForDelete(bool MarkForDelete) {
        _MarkForDelete = MarkForDelete;
    }

    //Find Client
    static clsBankClient Find(string FileName , string AccountNumber) {
            
        fstream ClientsFile;
        ClientsFile.open(FileName, ios::in);
        if (ClientsFile.is_open()) {
            string Line;
            while (getline(ClientsFile, Line)) {
                clsBankClient Client = _Convert_Line_To_Client_Object(Line);
                if (Client.UserName() == AccountNumber) {
                    ClientsFile.close();
                    return Client;
                }
            }
            ClientsFile.close();
        }
        return _GetEmptyClientObject();
    }

    //Can Client Login
    static clsBankClient Find(string FileName, string AccountNumber, string PinCode) {

        fstream ClientsFile;
        ClientsFile.open(FileName, ios::in);
        if (ClientsFile.is_open()) {
            string Line;
            while (getline(ClientsFile, Line)) {
                clsBankClient Client = _Convert_Line_To_Client_Object(Line);
                if (Client.UserName() == AccountNumber && Client.PinCode == PinCode) {
                    ClientsFile.close();
                    return Client;
                }
            }
            ClientsFile.close();
        }
        return _GetEmptyClientObject();
    }

    //Does Client Exists
    static bool Does_Client_Exist(string FileName, string AccountNumber) {
        return (!clsBankClient::Find(FileName, AccountNumber).IsEmpty());
    }

    //Update Client
    enum enSaveResults {svFaildEmptyObject = 0 , svSucceeded = 1 , svFaildAccountNumberExists = 2};

    enSaveResults Save() {
        switch (_Mode)
        {

        case enMode::EmptyMode :
            return enSaveResults::svFaildEmptyObject;

        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;

        case enMode::AddNewMode:
            if (clsBankClient::Does_Client_Exist("Clients.txt",_AccountNumber)) {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else {
                _Add_New();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
    }

    //Add New Client
    static clsBankClient Get_Add_New_Client_Object(string AccountNumber) {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }
    
    //Delete Client
    bool Delete() {
        vector <clsBankClient> vClients = _Load_Clients_Data_From_File("Clients.txt");
        for (clsBankClient &C : vClients) {
            if (C.UserName() == this->UserName()) {
                C._MarkForDelete = true;
                break;
            }
        }

        _SaveClientsDataToFile(vClients);
        *this = _GetEmptyClientObject();

        return true;
    }

    //Client List
    static vector<clsBankClient> Get_Clients_List() {
        return _Load_Clients_Data_From_File("Clients.txt");
    }

    //Transactions
    //Total Balances
    static float Get_Total_Balances()
    {
        vector <clsBankClient> vClients = clsBankClient::Get_Clients_List();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }

    //Deposit
    void Deposit(double Amount) {
        _AccountBalance += Amount;
        Save();
    }

    //Withdraw
    bool Withdraw(double Amount) {
        if (Amount > _AccountBalance) {
            return false;
        }
        else {
            _AccountBalance -= Amount;
            Save();
            return true;
        }

    }

    //Transfer
    static bool Transfer(clsBankClient &ClientFrom , clsBankClient &ClientTo , double Amount) {
        if (Amount > ClientFrom.AccountBalance) {
            return false;
        }
        else {
            ClientFrom.Withdraw(Amount);
            ClientTo.Deposit(Amount);
            return true;
        }
    }

    //Add In Transfer Log File
    static void Add_In_Transfer_Log_File(stTransferRegisterRecord Record) {
        _Add_New_To_Transfer_Log_File(Record);
    }

    //List Transfer Log Records
    static vector<stTransferRegisterRecord> Get_Transfer_Log_Vector_List_Of_Transfer_Log_File(string FileName) {
        return _Load_Transfer_Records_From_File(FileName);
    }
};

