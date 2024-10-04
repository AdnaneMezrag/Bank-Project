#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

class clsDate
{
	short _Day;
	short _Month;
	short _Year;

	static void Header_Of_Month_Calendar(short Month) {
		cout << endl;
		cout << "_______________" << Number_To_Month(Month) << "_______________" << endl;
		cout << left << setw(5) << "Sun" << left << setw(5) << "Mon" << left << setw(5) << "Tue" << left << setw(5) << "Wed" << left << setw(5) << "Thu" << left << setw(5) << "Fri" << left << setw(5) << "Sat";
		cout << endl;
	}

public:
	//Constructors
	clsDate(){
		*this = Get_Current_Date();
	}

	clsDate(short Day, short Month, short Year) {
		_Day = Day;
		_Month = Month; 
		_Year = Year;
	}

	clsDate(short NumOfDays, short Year) {
		*this = Convert_Days_To_Date(Year, NumOfDays);
	}

	//clsDate(string Date) {
	//	
	//}

	//Getters and Setters
	short Get_Day() {
		return _Day;
	}
	short Get_Month() {
		return _Month;
	}
	short Get_Year() {
		return _Year;
	}

	void Set_Day(short Day) {
		_Day = Day;
	}
	void Set_Month(short Month) {
		_Month = Month;
	}
	void Set_Year(short Year) {
		_Year = Year;
	}

	//Other

	static void Print(clsDate Date) {
		cout << endl;
		cout << "Date is: " << Date._Day << "/" << Date._Month << "/" << Date._Year;
	}

	void Print() {
		Print(*this);
	}

	static short DayOfWeekOrder(clsDate Date)
	{
		short a, y, m;
		a = (14 - Date._Month) / 12;
		y = Date._Year - a;
		m = Date._Month + (12 * a) - 2;
		// Gregorian: 
		//0:sun, 1:Mon, 2:Tue...etc 
		return (Date._Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
			/ 12)) % 7;

	}

	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(*this);
	}

	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = {
	"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[DayOfWeekOrder];

	}

	static bool isLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return  0;

		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

	}

	short NumberOfDaysInAMonth() {
		return NumberOfDaysInAMonth(this->_Month, this->_Year);
	}

	static string Number_To_Month(short Month) {
		string ArrOfMonths[] = { "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec" };
		return ArrOfMonths[Month - 1];
	}

	string Number_To_Month() {
		return Number_To_Month(this->_Month);
	}

	static void Month_Calendar(short Year, short Month) {
		Header_Of_Month_Calendar(Month);
		short NumberOfDaysInMonth = NumberOfDaysInAMonth(Month, Year);
		clsDate Date;
		Date._Day = 1;
		Date._Month = Month;
		Date._Year = Year;
		short DayOrder = DayOfWeekOrder(Date);
		string DayOfBeginningOfMonth = DayShortName(DayOrder);

		short Counter = 1;
		for (int i = 0; i < DayOrder; i++) {
			cout << "     ";
			Counter++;
		}

		for (int i = 1; i <= NumberOfDaysInMonth; i++) {
			cout << left << setw(5) << i;
			if (Counter % 7 == 0) {
				cout << endl;
			}
			Counter++;
		}
		cout << "\n_________________________________" << endl;
	}

	void Month_Calendar() {
		Month_Calendar(this->_Year, this->_Month);
	}

	static clsDate Convert_Days_To_Date(short Year, short NumOfDays) {
		short Month = 1;
		while (NumOfDays > NumberOfDaysInAMonth(Month, Year)) {
			NumOfDays = NumOfDays - NumberOfDaysInAMonth(Month, Year);
			Month++;
			if (Month > 12) {
				Year++;
				Month = 1;
			}
		}
		clsDate Date;
		Date._Day = NumOfDays;
		Date._Month = Month;
		Date._Year = Year;
		return Date;
	}

	static short Number_Of_Days_Of_Year(short Year) {
		return (isLeapYear(Year) ? 366 : 365);
	}

	static clsDate Get_Current_Date() {
		clsDate Today(1,1,1);
		time_t T = time(0);
		tm* TimeStruct = localtime(&T);
		Today._Year = TimeStruct->tm_year + 1900;
		Today._Month = TimeStruct->tm_mon + 1;
		Today._Day = TimeStruct->tm_mday;
		return Today;
	}

	static string Convert_Date_To_String(clsDate Date) {
		return to_string(Date.Get_Day()) + "/" + to_string(Date.Get_Month()) + "/" + to_string(Date.Get_Year());
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(clsDate Date)
	{
		if (Date._Day == 31 && Date._Month == 12) {
			return Number_Of_Days_Of_Year(Date._Year);
		}

		short TotalDays = 0;

		for (int i = 1; i <= Date._Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Date._Year);
		}

		TotalDays += Date._Day;

		return TotalDays;
	}

	short NumberOfDaysFromTheBeginingOfTheYear() {
		return NumberOfDaysFromTheBeginingOfTheYear(*this);
	}

	static clsDate Days_To_Add_In_A_Date(short Days, clsDate Date) {
		short NumOfDaysFromTheBeginingOfTheYear = NumberOfDaysFromTheBeginingOfTheYear(Date);
		short AllTheDays = Days + NumOfDaysFromTheBeginingOfTheYear;
		short NumOfDaysOfYear = Number_Of_Days_Of_Year(Date._Year);
		return Convert_Days_To_Date(Date._Year, AllTheDays);
	}

	void Days_To_Add_In_A_Date(short Days) {
		*this = Days_To_Add_In_A_Date(Days, *this);
	}

	static short Difference_Between_Two_Dates(clsDate Date1, clsDate Date2, bool EndDay = false) {
		short Diff = 0;
		while (Date1._Year < Date2._Year) {
			Diff += NumberOfDaysFromTheBeginingOfTheYear(Date2);
			Date2._Year--;
			Date2._Month = 12;
			Date2._Day = 31;
		}
		Diff = Diff + (NumberOfDaysFromTheBeginingOfTheYear(Date2) - NumberOfDaysFromTheBeginingOfTheYear(Date1));
		return Diff + EndDay;
	}

	short Difference_Between_Two_Dates(clsDate Date2, bool EndDay = false) {
		return Difference_Between_Two_Dates(*this, Date2, EndDay);
	}

	static short Calculate_Your_Age(clsDate BornDate) {
		return Difference_Between_Two_Dates(BornDate, Get_Current_Date());
	}

	short Calculate_Your_Age() {
		return Calculate_Your_Age(*this);
	}

	static bool Is_End_Of_Month(clsDate Date) {
		return Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year);
	}

	bool Is_End_Of_Month() {
		return Is_End_Of_Month(*this);
	}

	static clsDate Increase_Date_By_One_Day(clsDate Date) {
		if (Date._Month == 12 && Date._Day == 31) {
			Date._Day = 1;
			Date._Month = 1;
			Date._Year++;
		}
		else {
			if (Is_End_Of_Month(Date)) {
				Date._Day = 1;
				Date._Month++;
			}
			else {
				Date._Day++;
			}
		}
		return Date;
	}

	void Increase_Date_By_One_Day() {
		*this = Increase_Date_By_One_Day(*this);
	}

	static clsDate Increase_Date_By_X_Days(clsDate Date, short XDays) {
		for (int i = 0; i < XDays; i++) {
			Date = Increase_Date_By_One_Day(Date);
		}
		return Date;
	}

	static clsDate Increase_Date_By_One_Week(clsDate Date) {
		return Increase_Date_By_X_Days(Date, 7);
	}

	void Increase_Date_By_One_Week() {
		*this = Increase_Date_By_One_Week(*this);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

	}

	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}


	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}

	bool IsDateBeforeDate2(clsDate Date2)
	{
		//note: *this sends the current object :-) 
		return  IsDate1BeforeDate2(*this, Date2);

	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}

	bool IsDateEqualDate2(clsDate Date2)
	{
		return  IsDate1EqualDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		/* if (IsDate1AfterDate2(Date1,Date2))
			 return enDateCompare::After;*/

			 //this is faster
		return enDateCompare::After;

	}

	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	static bool Is_Valid_Date(clsDate Date) {
		if (Date._Year < 1) {
			return 0;
		}
		if (Date._Month > 12 || Date._Month < 1) {
			return 0;
		}
		if (Date._Day > 31 || Date._Day < 1) {
			return 0;
		}
		if (Date._Day > NumberOfDaysInAMonth(Date._Month, Date._Year)) {
			return 0;
		}
		return 1;
	}

	bool Is_Valid_Date() {
		return Is_Valid_Date(*this);
	}

	static string Get_Current_Date_And_Time() {

		time_t T = time(0);
		tm* TimeStruct = localtime(&T);
		int Year = TimeStruct->tm_year + 1900;
		int month = TimeStruct->tm_mon + 1;
		int day = TimeStruct->tm_mday;
		int hour = TimeStruct->tm_hour;          
		int minute = TimeStruct->tm_min;         
		int second = TimeStruct->tm_sec;        
		
		return to_string(Year) + "/" + to_string(month) + "/" + to_string(day) + " - " + to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
	}

	
};

