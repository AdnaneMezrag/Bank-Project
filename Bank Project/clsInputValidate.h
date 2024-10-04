#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:

    static bool IsNumberBetween(double Number, double From, double To) {
        return (Number >= From && Number <= To);
    }

    static bool IsDateBetween(clsDate Date, clsDate FromTo, clsDate ToFrom) {
        if (clsDate::IsDate1EqualDate2(Date, FromTo) || clsDate::IsDate1EqualDate2(Date, ToFrom)) {
            return 1;
        }
        return  !((clsDate::IsDate1AfterDate2(Date, FromTo) && clsDate::IsDate1AfterDate2(Date, ToFrom)) ||
            (clsDate::IsDate1AfterDate2(FromTo, Date) && clsDate::IsDate1AfterDate2(ToFrom, Date)));
    }

    template <typename T> T ReadNumber(const string& message) {
        T Num = -1;
        while (true) {
            cout << message;
            if (cin >> Num && cin.peek() == '\n') {
                // Input was a valid integer
                break;
            }
            else {
                // Input was not a valid integer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid number." << endl;
            }
        }
        return Num;
    }

    static int ReadIntNumber(const string& message) {
        int Num = -1;
        while (true) {
            cout << message;
            if (cin >> Num && cin.peek() == '\n') {
                // Input was a valid integer
                break;
            }
            else {
                // Input was not a valid integer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
        }
        return Num;
    }

    static float ReadFloatNumber(const string& message) {
        float Num = -1;
        while (true) {
            cout << message;
            if (cin >> Num && cin.peek() == '\n') {
                // Input was a valid integer
                break;
            }
            else {
                // Input was not a valid integer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
        }
        return Num;
    }

    static double ReadDoubleNumber(const string& message) {
        double Num = -1;
        while (true) {
            cout << message;
            if (cin >> Num && cin.peek() == '\n') {
                // Input was a valid integer
                break;
            }
            else {
                // Input was not a valid integer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
        }
        return Num;
    }

    static string ReadString(string message) {
        string Name = "";
        cout << message;
        getline(cin >> ws, Name);
        return Name;
    }

    static int ReadIntNumberFromTo(string message, int From, int To= numeric_limits<int>::max()) {
        int Number = 0;
        do {
            Number = ReadIntNumber(message);
            if (Number <= To && Number >= From) {
                break;
            }
            cout << "Number is not within range\n";
        } while (true);
        return Number;
    }

    static double ReadDoubleNumberFromTo(string message, double From, double To= numeric_limits<double>::max()) {
        double Number = 0;
        do {
            Number = ReadDoubleNumber(message);
            if (Number <= To && Number >= From) {
                break;
            }
            cout << "Number is not within range\n";
        } while (true);
        return Number;
    }

    static double ReadPositiveDoubleNumber(string message) {
        double Number = 0;
        do {
            Number = ReadDoubleNumber(message);
            if (Number >= 0 ) {
                break;
            }
            cout << "Number should be positive\n";
        } while (true);
        return Number;
    }

    static bool IsValidDate(clsDate Date) {
        return Date.Is_Valid_Date();
    }

    static char ReadCharacter(const string& message) {
        char Num = 'k';
        while (true) {
            cout << message;
            if (cin >> Num && cin.peek() == '\n') {
                // Input was a valid integer
                break;
            }
            else {
                // Input was not a valid integer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid integer." << endl;
            }
        }
        return Num;
    }

    static bool Are_You_Sure(string message) {
        cout << message << " y/n? ";
        char Answer = ReadCharacter("");
        //cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            return 1;
        }
        else {
            return 0;
        }
    }

};

