#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{
public:

	enum enCharacter {
		CapitalLetter = 1, SmallLetter = 2, Digit = 3, Mix = 4
	};

	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static int Random_Number(int From, int To) {
		int RandomNumber = 0;
		RandomNumber = rand() % (To - From + 1) + From;
		return RandomNumber;
	}

	static char RandomCapitalLetter() {
		return (char)Random_Number(65, 90);
	}

	static char RandomSmallLetter() {
		return (char)Random_Number(97, 122);
	}

	static char RandomDigit() {
		return (char)Random_Number(48, 57);
	}

	static char Get_Random_Character(enCharacter Character) {
		switch (Character)
		{
		case enCharacter::CapitalLetter:
			return RandomCapitalLetter();
			break;
		case enCharacter::SmallLetter:
			return RandomSmallLetter();
			break;
		case enCharacter::Digit:
			RandomDigit();
			break;
		case enCharacter::Mix:
			return Get_Random_Character((enCharacter)Random_Number(1, 3));
		default:
			break;
		}
	}

	static string GenerateWord(enCharacter Character , short Long) {
		string Word = "";
		for (short i = 0; i < Long; i++) {
			Word += Get_Random_Character(Character);
		}
		return Word;
	}

	static string GenerateKey(enCharacter Character) {
		int i = 0;
		string Key = "";
		for (i = 0; i < 3; i++) {
			Key = Key + GenerateWord(Character,4) + "-";
		}
		Key = Key + GenerateWord(Character,4);
		return Key;
	}

	static void Generate_Keys(enCharacter Character , short NumberOfKeys) {
		for (short i = 0; i < NumberOfKeys; i++) {
			cout << GenerateKey(Character) << "\n";
		}
	}

	static void Swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	static void Swap(double& a, double& b) {
		double temp = a;
		a = b;
		b = temp;
	}

	static void Swap(string& a, string& b) {
		string temp = a;
		a = b;
		b = temp;
	}

	static void Swap(clsDate& Date1, clsDate& Date2) {
		clsDate temp = Date1;
		Date1 = Date2;
		Date2 = temp;
	}
		
	static void ShuffleArray(int Arr[100] , short Length ) {
		for (short i = 0; i < Length; i++) {
			Swap(Arr[Random_Number(0, Length - 1)], Arr[Random_Number(0, Length - 1)]);
		}
	}

	static void ShuffleArray(string Arr[100], short Length) {
		for (short i = 0; i < Length; i++) {
			Swap(Arr[Random_Number(0, Length - 1)], Arr[Random_Number(0, Length - 1)]);
		}
	}

	static void Print_Array(int Arr[100], int Length) {
		cout << "Array elements are:\n";
		for (short i = 0; i < Length; i++) {
			cout << Arr[i] << " ";
		}
	}

	static void Print_Array(string Arr[100], int Length) {
		cout << "Array elements are:\n";
		for (short i = 0; i < Length; i++) {
			cout << Arr[i] << " ";
		}
	}

	static void FillArrayWithRandomNumbers(int Array[100], short Length , int NumberFrom , int NumberTo) {
		for (short i = 0; i < Length; i++) {
			Array[i] = Random_Number(NumberFrom, NumberTo);
		}
	}

	static void FillArrayWithRandomWords(string Array[100], short Length, enCharacter Character , short WordLength) {
		for (short i = 0; i < Length; i++) {
			Array[i] = GenerateWord(Character,WordLength);
		}
	}

	static void FillArrayWithRandomKeys(string Array[100], short Length, enCharacter Character) {
		for (short i = 0; i < Length; i++) {
			Array[i] = GenerateKey(Character);
		}
	}

	static void Tabs(short N) {
		for (short i = 0; i < N; i++) {
			cout << "\t";
		}
	}

	static string Tab(short N) {
		string Tabs = "";
		for (int i = 0; i < N; i++) {
			Tabs += "\t";
		}
		return Tabs;
	}

	static string  EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string  DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

};

