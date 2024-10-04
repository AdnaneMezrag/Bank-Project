#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{
	string _Value;

	static char InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1
			== 'o') || (Ch1 == 'u'));

	}

	static string  LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

public:

	clsString(string Value){
		_Value = Value;
	}

	clsString() {
		_Value = "";
	}
	
	void Set_Value(string Value) {
		_Value = Value;
	}

	string Get_Value() {
		return _Value;
	}

	__declspec (property(get = Get_Value, put = Set_Value)) string Value;



	static void PrintFirstLetterOfEachWord(string S1)
	{

		bool isFirstLetter = true;

		cout << "\nFirst letters of this string: \n";

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				cout << S1[i] << endl;
			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}
	}

	void PrintFirstLetterOfEachWord() {
		PrintFirstLetterOfEachWord(_Value);
	}

	static string  UpperFirstLetterOfEachWord(string S1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}

	void UpperFirstLetterOfEachWord() {
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string  LowerFirstLetterOfEachWord(string S1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}

	void LowerFirstLetterOfEachWord() {
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string  UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	void UpperAllString() {
		_Value = UpperAllString(_Value);
	}

	void LowerAllString() {
		_Value = LowerAllString(_Value);
	}

	static string  InvertAllStringLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}

	void InvertAllStringLettersCase() {
		_Value = InvertAllStringLettersCase(_Value);
	}

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{

		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetters &&
				isupper(S1[i]))
				Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters &&
				islower(S1[i]))
				Counter++;


		}

		return Counter;

	}

	short CountLetters(enWhatToCount WhatToCount = enWhatToCount::All) {
		return CountLetters(_Value, WhatToCount);
	}

	static short  CountCapitalLetters(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (isupper(S1[i]))
				Counter++;

		}

		return Counter;
	}

	short CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (islower(S1[i]))
				Counter++;

		}

		return Counter;
	}

	short CountSmallLetters() {
		return CountSmallLetters(_Value);
	}

	static short CountLetter(string S1, char Letter)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] == Letter)
				Counter++;

		}

		return Counter;
	}

	short CountLetter(char Letter) {
		return CountLetter(_Value, Letter,true);
	}

	static short  CountLetter(string S1, char Letter, bool MatchCase = true)
	{

		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{

			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}

		}
		return Counter;
	}

	short CountLetter(char Letter, bool MatchCase = true) {
		return CountLetter(_Value, Letter, MatchCase);
	}

	static short  CountVowels(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (IsVowel(S1[i]))
				Counter++;
		}

		return Counter;
	}

	short CountVowels() {
		return CountVowels(_Value);
	}

	static void PrintVowels(string S1)
	{
		cout << "\nVowels in string are: ";
		for (short i = 0; i < S1.length(); i++)
		{

			if (IsVowel(S1[i]))
				cout << S1[i] << "    ";
		}

	}

	void PrintVowels() {
		return PrintVowels(_Value);
	}

	static void PrintEachWordInString(string S1)
	{

		string delim = " "; // delimiter   

		cout << "\nYour string wrords are: \n\n";
		short pos = 0;
		string sWord; // define a string variable   

		// use find() function to get the position of the delimiters   
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word    
			if (sWord != "")
			{
				cout << sWord << endl;
			}

			S1.erase(0, pos + delim.length());  /* erase() until
	positon and move to next word. */
		}

		if (S1 != "")
		{
			cout << S1 << endl; // it print last word of the string. 
		}

	}

	void PrintEachWordInString() {
		return  PrintEachWordInString(_Value);
	}

	static short CountWords(string S1)
	{

		string delim = " "; // delimiter   
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable   

		// use find() function to get the position of the delimiters   
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word    
			if (sWord != "")
			{
				Counter++;
			}

			//erase() until positon and move to next word. 
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++; // it counts the last word of the string. 
		}

		return Counter;

	}

	short CountWords() {
		return CountWords(_Value);
	}

	static vector<string> Split(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable   

		// use find() function to get the position of the delimiters   
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word    
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());  /* erase() until
	positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string. 
		}

		return vString;

	}

	vector<string> Split(string Delim) {
		return Split(_Value, Delim);
	}

	static string TrimLeft(string S1)
	{


		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	void TrimLeft() {
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{


		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight() {
		_Value = TrimRight(_Value);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));

	}

	void Trim() {
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string> vString, string Delim)
	{

		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());


	}

	static string JoinString(string arrString[], short Length, string Delim)
	{

		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}

	static string ReverseWordsInString(string S1)
	{

		vector<string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		// declare iterator 
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space. 

		return S2;
	}

	void ReverseWordsInString() {
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo)
	{

		short pos = S1.find(StringToReplace);

		while (pos != std::string::npos)

		{
			S1 = S1.replace(pos, StringToReplace.length(),
				sRepalceTo);
			pos = S1.find(StringToReplace);//find next 
		}

		return S1;

	}

	void ReplaceWordInStringUsingBuiltInFunction(string StringToReplace, string sRepalceTo) {
		_Value = ReplaceWordInStringUsingBuiltInFunction(_Value, StringToReplace, sRepalceTo);
	}

	static string ReplaceWordInStringUsingSplit(string S1, string
		StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (LowerAllString(s) ==
					LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}

		return JoinString(vString, " ");
	}

	void ReplaceWordInStringUsingSplit(string
		StringToReplace, string sRepalceTo, bool MatchCase = true) {
		_Value = ReplaceWordInStringUsingSplit(_Value, StringToReplace, sRepalceTo, MatchCase);
	}

	static string RemovePunctuationsFromString(string S1)
	{

		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2;

	}

	void RemovePunctuationsFromString() {
		_Value = RemovePunctuationsFromString(_Value);
	}

	static string Multiply_String(string S, short N) {
		string Result = "";
		for (int i = 0; i < N; i++) {
			Result += S;
		}
		return Result;
	}
};

