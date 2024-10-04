#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
private:

    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6,
    };

    static short _Read_Manage_Users_Menue_Option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberFromTo("Enter Number between 1 to 6? ", 1, 6);
        return Choice;
    }

    static void _Go_Back_To_Manage_Users_Menue() {

        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        Show_Manage_Users_Menue();
    }

    static void _Show_All_Users_Screen() {
        clsListUsersScreen::Show_User_List();
    }

    static void _Show_Add_New_Users_Screen() {
        clsAddNewUserScreen::Add_New_User();
    }

    static void _Show_Delete_User_Screen() {
        clsDeleteUserScreen::Show_Delete_User_Screen();
    }

    static void _Show_Update_User_Screen()
    {
        clsUpdateUserScreen::Show_Update_User_Screen();
    }

    static void _Show_Find_User_Screen()
    {
        clsFindUserScreen::Show_Find_User_Screen();
    }

    static void _Perform_Manage_Users_Menue_Option(enManageUsersMenueOptions ManageUsersMenueOption) {
        switch (ManageUsersMenueOption)
        {

        case clsManageUsersScreen::eListUsers:
            system("cls");
            _Show_All_Users_Screen();
            _Go_Back_To_Manage_Users_Menue();
            break;

        case clsManageUsersScreen::eAddNewUser:
            system("cls");
            _Show_Add_New_Users_Screen();
            _Go_Back_To_Manage_Users_Menue();
            break;

        case clsManageUsersScreen::eDeleteUser:
            system("cls");
            _Show_Delete_User_Screen();
            _Go_Back_To_Manage_Users_Menue();
            break;

        case clsManageUsersScreen::eUpdateUser:
            system("cls");
            _Show_Update_User_Screen();
            _Go_Back_To_Manage_Users_Menue();
            break;

        case clsManageUsersScreen::eFindUser:
            system("cls");
            _Show_Find_User_Screen();
            _Go_Back_To_Manage_Users_Menue();
            break;

        case clsManageUsersScreen::eMainMenue:
            system("cls");

            break;
        default:
            break;
        }
    }

public:

    static void Show_Manage_Users_Menue() {
        if (!_CheckAccessRights(clsUser::enPermissions::pManageUsers)) {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t\Manage Users Screen");


        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show User List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _Perform_Manage_Users_Menue_Option((enManageUsersMenueOptions)_Read_Manage_Users_Menue_Option());
    }

};

