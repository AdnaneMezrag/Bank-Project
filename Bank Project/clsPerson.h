#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
	private:
		string _FirstName;
		string _LastName;
		string _Email;
		string _PhoneNumber;

	public:
		//Constructors
		clsPerson(){}

		clsPerson( string FirstName, string LastName, string Email, string PhoneNumber) {
			_FirstName = FirstName;
			_LastName = LastName;
			_Email = Email;
			_PhoneNumber = PhoneNumber;
		}

		//Get Fucntions
		string Full_Name() {
			return _FirstName + " " + _LastName;
		}
		string First_Name() {
			return _FirstName;
		}
		string Last_Name() {
			return _LastName;
		}
		string Get_Email() {
			return _Email;
		}
		string Phone_Number() {
			return _PhoneNumber;
		}

		//Set Functions
		void Set_First_Name(string FirstName) {
			_FirstName = FirstName;
		}
		void Set_Last_Name(string LastName) {
			_LastName = LastName;
		}
		void Set_Email(string Email) {
			_Email = Email;
		}
		void Set_Phone_Number(string PhoneNumber) {
			_PhoneNumber = PhoneNumber;
		}

		void Print() {
			cout << "\t\tPerson's Info:\n";
			cout << "================================================\n";
			cout << "First Name   : " << _FirstName << "\n";
			cout << "Last Name    : " << _LastName << "\n";
			cout << "Full Name    : " << Full_Name() << "\n";
			cout << "Email        : " << _Email << "\n";
			cout << "Phone Number : " << _PhoneNumber << "\n";
			cout << "================================================\n";
		}
		//Property
		__declspec(property(get = First_Name, put = Set_First_Name)) string FirstName;
		__declspec(property(get = Last_Name, put = Set_Last_Name)) string LastName;
		__declspec(property(get = Get_Email, put = Set_Email)) string Email;
		__declspec(property(get = Phone_Number, put = Set_Phone_Number)) string PhoneNumber;

};

