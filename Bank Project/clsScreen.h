#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"

using namespace std;
class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\tUser: " << CurrentUser.UserName() << "\n";
        cout << "\t\t\t\t\tDate: " << clsDate::Convert_Date_To_String(clsDate::Get_Current_Date()) << endl;

    }

    static bool _CheckAccessRights(clsUser::enPermissions Permission) {
        if (!CurrentUser.Check_Access_Permissions(Permission)) {
            _DrawScreenHeader("Access Denied! Contact Your Admin");
            return false;
        }
        return true;
    }

};

