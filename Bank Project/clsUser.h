#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"

class clsUser : public clsPerson
{

private:

    enum enMode {
        EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
    };

    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;
    string _DateTime;

    bool _MarkForDelete = false;

    static clsUser _Convert_Line_To_User_Object(string Line, string Delim = "#//#") {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Delim);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5],3) , stoi(vUserData[6]));
    }

    static vector<clsUser> _Load_Users_Data_From_File(string FileName) {
        vector <clsUser> vUsers;
        fstream UsersFile;
        UsersFile.open(FileName, ios::in);
        if (UsersFile.is_open()) {
            string Line;

            while (getline(UsersFile, Line)) {
                clsUser User = _Convert_Line_To_User_Object(Line);
                vUsers.push_back(User);
            }
            UsersFile.close();
        }
        return vUsers;

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
    {
        string stUserRecord = "";
        stUserRecord += User.FirstName + Seperator;
        stUserRecord += User.LastName + Seperator;
        stUserRecord += User.Email + Seperator;
        stUserRecord += User.PhoneNumber + Seperator;
        stUserRecord += User._UserName + Seperator;
        stUserRecord += clsUtil::EncryptText(User._Password,3) + Seperator;
        stUserRecord += to_string(User._Permissions);

        return stUserRecord;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkForDelete() == false) {
                    DataLine = _ConvertUserObjectToLine(U);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();

        }

    }

    void _Update() {
        vector <clsUser> vUsers = _Load_Users_Data_From_File("Users.txt");
        for (clsUser& U : vUsers) {
            if (U._UserName == _UserName) {
                U = *this;
                break;
            }
        }
        _SaveUsersDataToFile(vUsers);
    }

    void _Add_Data_Line_To_File(string Line,string FileName = "Users.txt") {
        fstream File;
        File.open(FileName, ios::out | ios::app);
        if (File.is_open()) {
            File << Line << endl;
            File.close();
        }
    }

    void _Add_New() {
        _Add_Data_Line_To_File(_ConvertUserObjectToLine(*this));
    }

    //Log File

    static string _ConvertUserObjectToLineToSaveInLogFile(clsUser User, string Seperator = "#//#")
    {
        string stUserRecord = "";
        stUserRecord = clsDate::Get_Current_Date_And_Time() + Seperator;
        stUserRecord += User._UserName + Seperator;
        stUserRecord += clsUtil::EncryptText(User._Password,3) + Seperator;
        stUserRecord += to_string(User._Permissions);

        return stUserRecord;

    }

    void _Add_New_To_Log_File() {
        _Add_Data_Line_To_File(_ConvertUserObjectToLineToSaveInLogFile(*this), "LoginRegister.txt");
    }

    //List Log Records

    static clsUser _Convert_Line_Of_Login_File_To_User_Object(string Line, string Delim = "#//#") {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Delim);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], clsUtil::DecryptText(vUserData[2],3),
            stoi(vUserData[3]));

    }

    static vector<clsUser> _Load_Users_Data_From_Login_File(string FileName) {
        vector <clsUser> vUsers;
        fstream UsersFile;
        UsersFile.open(FileName, ios::in);
        if (UsersFile.is_open()) {
            string Line;

            while (getline(UsersFile, Line)) {
                clsUser User = _Convert_Line_Of_Login_File_To_User_Object(Line);
                vUsers.push_back(User);
            }
            UsersFile.close();
        }
        return vUsers;

    }

public:

    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClients = 8, pFindClient = 16
        , pTranactions = 32, pManageUsers = 64, PLoginRegister = 128
    };

    //Constructors
    clsUser() {}

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber,
        string UserName, string Password, int Permissions) :clsPerson(FirstName, LastName, Email, PhoneNumber) {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    clsUser(enMode Mode, string DateTime, string UserName, string Password, int Permissions ) {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
        _DateTime = DateTime;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    //Setters and Getters
    string UserName()
    {
        return _UserName;
    }

    string DateTime()
    {
        return _DateTime;
    }

    void SetDateTime(string DateTime)
    {
        _DateTime = DateTime;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    bool MarkForDelete() {
        return _MarkForDelete;
    }

    void SetMarkForDelete(bool MarkForDelete) {
        _MarkForDelete = MarkForDelete;
    }

    //Find User
    static clsUser Find(string FileName, string UserName) {

        fstream UsersFile;
        UsersFile.open(FileName, ios::in);
        if (UsersFile.is_open()) {
            string Line;
            while (getline(UsersFile, Line)) {
                clsUser User = _Convert_Line_To_User_Object(Line);
                if (User.UserName() == UserName) {
                    UsersFile.close();
                    return User;
                }
            }
            UsersFile.close();
        }
        return _GetEmptyUserObject();
    }

    //Can User Login
    static clsUser Find(string FileName, string UserName, string Password) {

        fstream UsersFile;
        UsersFile.open(FileName, ios::in);
        if (UsersFile.is_open()) {
            string Line;
            while (getline(UsersFile, Line)) {
                clsUser User = _Convert_Line_To_User_Object(Line);
                if (User.UserName() == UserName && User.Password == Password) {
                    UsersFile.close();
                    return User;
                }
            }
            UsersFile.close();
        }
        return _GetEmptyUserObject();
    }

    //Does User Exists
    static bool Does_User_Exist(string FileName, string UserName) {
        return (!clsUser::Find(FileName, UserName).IsEmpty());
    }

    //Update User
    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExists = 2 };

    enSaveResults Save() {
        switch (_Mode)
        {

        case enMode::EmptyMode:
            return enSaveResults::svFaildEmptyObject;

        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;

        case enMode::AddNewMode:
            if (clsUser::Does_User_Exist("Users.txt", _UserName)) {
                return enSaveResults::svFaildUserNameExists;
            }
            else {
                _Add_New();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
    }

    //Add New User
    static clsUser Get_Add_New_User_Object(string UserName) {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    //Delete User
    bool Delete() {
        vector <clsUser> vUsers = _Load_Users_Data_From_File("Users.txt");
        for (clsUser& U : vUsers) {
            if (U.UserName() == this->UserName()) {
                U._MarkForDelete = true;
                break;
            }
        }

        _SaveUsersDataToFile(vUsers);
        *this = _GetEmptyUserObject();

        return true;
    }

    //Client List
    static vector<clsUser> Get_Users_List() {
        return _Load_Users_Data_From_File("Users.txt");
    }

    bool Check_Access_Permissions(enPermissions Permission) {
        if (this->Permissions == enPermissions::eAll) {
            return true;
        }
        if ((this->Permissions & Permission) == Permission) {
            return true;
        }
        return false;
    }

    //Log File

    void Save_User_In_Log_File() {
        this->_Add_New_To_Log_File();
    }

    static vector<clsUser> Get_Users_List_Of_Log_File() {
        return _Load_Users_Data_From_Login_File("LoginRegister.txt");
    }



};

