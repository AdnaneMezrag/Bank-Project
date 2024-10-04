#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"

using namespace std;

class clsCurrency
{

	enum enMode{eEmptyMode = 0 , eUpdateMode = 1};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _Convert_Line_To_Currency_Object(string Line, string Delim = "#//#") {
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Delim);

		return clsCurrency(enMode::eUpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
			stof(vCurrencyData[3]));
	}

	static vector<clsCurrency> _Load_Currencies_Data_From_File(string FileName) {
		vector <clsCurrency> vCurrencies;
		fstream CurrenciesFile;
		CurrenciesFile.open(FileName, ios::in);
		if (CurrenciesFile.is_open()) {
			string Line;

			while (getline(CurrenciesFile, Line)) {
				clsCurrency Currency = _Convert_Line_To_Currency_Object(Line);
				vCurrencies.push_back(Currency);
			}
			CurrenciesFile.close();
		}
		return vCurrencies;

	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string stUserRecord = "";
		stUserRecord += Currency.Country() + Seperator;
		stUserRecord += Currency.CurrencyCode() + Seperator;
		stUserRecord += Currency.CurrencyName() + Seperator;
		stUserRecord += to_string(Currency.Rate()) ;

		return stUserRecord;

	}

	static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrencies)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency Currency : vCurrencies)
			{
				DataLine = _ConvertCurrencyObjectToLine(Currency);
				MyFile << DataLine << endl;
				
			}

			MyFile.close();

		}

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
	}

	void _Update() {
		vector <clsCurrency> vCurrencies = _Load_Currencies_Data_From_File("Currencies.txt");
		for (clsCurrency& Currency : vCurrencies) {
			if (Currency.CurrencyCode() == CurrencyCode()) {
				Currency._Rate = this->_Rate;
				break;
			}
		}
		_SaveCurrenciesDataToFile(vCurrencies);
	}



public:

	//Constructr(s)
	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	//This Are Read Only Properties Except For The Rate Variable
	//Getrs 
	string Country() {
		return _Country;
	}
	string CurrencyCode() {
		return _CurrencyCode;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	float Rate() {
		return _Rate;
	}

	bool Is_Empty() {
		return (_Mode == enMode::eEmptyMode);
	}

	void Update_Rate(float NewRate) {
		_Rate = NewRate;
		_Update();
	}

	static clsCurrency Find_By_Code(string CurrencyCode , string FileName = "Currencies.txt") {
		fstream CurrenciesFile;
		CurrenciesFile.open(FileName, ios::in);
		if (CurrenciesFile.is_open()) {
			string Line;
			while (getline(CurrenciesFile, Line)) {
				clsCurrency Currency = _Convert_Line_To_Currency_Object(Line);
				if (Currency.CurrencyCode() == clsString::UpperAllString(CurrencyCode)) {
					CurrenciesFile.close();
					return Currency;
				}
			}
			CurrenciesFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency Find_By_Country(string Country, string FileName = "Currencies.txt") {
		fstream CurrenciesFile;
		CurrenciesFile.open(FileName, ios::in);
		if (CurrenciesFile.is_open()) {
			string Line;
			while (getline(CurrenciesFile, Line)) {
				clsCurrency Currency = _Convert_Line_To_Currency_Object(Line);
				if (clsString::UpperAllString(Currency.Country()) == clsString::UpperAllString(Country)) {
					CurrenciesFile.close();
					return Currency;
				}
			}
			CurrenciesFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static bool Does_Currency_Exist(string CurrencyCode, string FileName = "Currencies.txt") {
		return (!Find_By_Code(CurrencyCode).Is_Empty());
	}

	static vector<clsCurrency> Get_Currencies_List(string FileName = "Currencies.txt") {
		return _Load_Currencies_Data_From_File(FileName);
	}

	float Convert_To_USD(float Amount) {
		return (Amount / (Rate()));
	}

	float Convert_From_USD(float Amount) {
		return (Amount * (Rate()));
	}

	float Convert_To_Other_Currency(clsCurrency CurrencyTo, float Amount) {
		float AmountInUSD = Convert_To_USD(Amount);
		float FromUSD = CurrencyTo.Convert_From_USD(AmountInUSD);

		return FromUSD;
	}

};

