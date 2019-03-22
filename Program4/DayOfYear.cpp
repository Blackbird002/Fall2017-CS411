/*
DayOfYear.cpp
Riad Shash (Ray)
ID: n845y337
Class: CS411
Program #4
 */
#include "DayOfYear.hpp"

//Constructor
DayOfYear::DayOfYear(int monthValue, int dayValue)
: month(monthValue), day(dayValue)
{
	//Tests the initialized month and day.
	testDate();
}

//Constructor
DayOfYear::DayOfYear(int monthValue): month(monthValue), day(1)
{
	//Tests the initialized month and day.
	testDate();
}

//Default Constructor
DayOfYear::DayOfYear(): month(1), day(1)
{}

//This function is the full implementation of the desired input for this class.
//This is replaced by the ">>" overloaded operator.
void DayOfYear::input()
{
	string input;
	cout<<"Enter a date (mm/dd, m/dd, mm/d, m/d): \n";
	//Gets the whole line and makes it a string
	getline(cin,input);
	int length = input.length();

	//Checks if the input is valid
	bool backslashCheck = false;
	//Looks for the '/'
	for(int i = 0; i < length; i++)
	{
		if(input[i] == '/')
		{
			backslashCheck = true;
		}
	}
	//If there is no '/' or if the string is too long or too short
	if ((backslashCheck == false) || (length > 5) || (length < 3))
	{
		cout<<endl;
		cout<<"Invalid input!\n";
		cout<<"Used default date instead.\n";
		month = 1;
		day = 1;
		//Exits right here since an error occured.
		return;	//Void function returns nothing.
	}

	string newMonth ="";
	string newDay= "";
	int intDay;
	int intMonth;

	//Extracts the relevant data from the input string
	bool monthFlag = true;
	for(int i = 0; i < length; i++)
	{
		if (input[i] == '/')
		{
			monthFlag = false;
			continue;
		}
		if(monthFlag == true)
		{
			newMonth+= input[i];
		}
		if(monthFlag == false)
		{
			newDay+= input[i];
		}
	}

	//Gets rid of the leading 0s if present
	if(newMonth[0] == '0')
	{
		newMonth.erase(newMonth.begin());
	}

	if(newDay[0] == '0')
	{
		newDay.erase(newDay.begin());
	}

	//Tests if the month or day string is empty
	if((newMonth.length() == 0) || (newDay.length() == 0))
	{
		cout<<endl;
		cout<<"Invalid input!\n";
		cout<<"Used default date instead.\n";
		month = 1;
		day = 1;
		//Returns right here since an error occured.
		return; //Void function returns nothing.
	}

	//Converts the strings to an int
	intMonth = atoi(newMonth.c_str());
	intDay = atoi(newDay.c_str());

	//Checks if the entered date was valid
	if((intMonth < 1) || (intMonth > 12) || (intDay < 1) || (intDay > 30))
	{
		cout<<endl;
		cout<<"Invalid input!\n";
		cout<<"Used default date instead.\n";
		month = 1;
		day = 1;
		//Returns right here since an error occured.
		return;	//Void function returns nothing.
	}
	else
	{
		month = intMonth;
		day = intDay;
	}
}

//Prints the output, the Month followed by the day
void DayOfYear::output() const
{
	switch (month)
	{
		case 1:
			cout<<"January "; break;
		case 2:
			cout<<"February "; break;
		case 3:
			cout<<"March "; break;
		case 4:
			cout<<"April "; break;
		case 5:
			cout<<"May "; break;
		case 6:
			cout<<"June "; break;
		case 7:
			cout<<"July "; break;
		case 8:
			cout<<"August "; break;
		case 9:
			cout<<"September "; break;
		case 10:
			cout<<"October "; break;
		case 11:
			cout<<"November "; break;
		case 12:
			cout<<"December "; break;
		default:
			cout<<"Error! Invalid month!\n";
	}
	cout<< day;
}

//A typical accessor to get the month
int DayOfYear::getMonthNumber() const
{
	return month;
}

//A typical accessor to get the day
int DayOfYear::getDay() const
{
	return day;
}

//Retuns the day of year (1-360)
int DayOfYear::getYearDay() const
{
	int totalDays = month -1;
	totalDays = totalDays * 30;
	totalDays+= day;
	return totalDays;
}

//Adds the months and days and returns the DayOfYear object by value.
//Member function of the DayOfYear class.
const DayOfYear DayOfYear::operator +(const DayOfYear& secondObj) const
{
	//Months:
	int totalMonths = month + secondObj.month;
	//Days:
	int totalDays = day + secondObj.day;

	//Rolls over the dates if necessary
	warpDayOfYear(totalMonths,totalDays);

	return DayOfYear(totalMonths,totalDays);
}

/*
This private function does the desired rolling over into months and also
into new years. A year starts on January 1st (1/1) and ends on December 30th
(12/30). It also handles negative rolling over in a very limited way in the
cases where a negative int is provided.
Member function of the DayOfYear class.
*/
void DayOfYear::warpDayOfYear(int& monthNum, int& dayNum) const
{
	int newMonth = monthNum;
	int newDay = dayNum;

	//If the months are > then 12, it warps the months
	if(newMonth > 12)
	{
		//Handles the specific case of adding December + 12 months
		if (newMonth == 24)
			newMonth = 12;
		else
			newMonth = newMonth - 12;
	}

	//Keeps subtracting 30 and adding a month if newDay is greater than 30
	while (newDay > 30)
	{
		newDay = newDay - 30;
		//If current month is December, next month is January
		if(newMonth == 12)
			newMonth = 1;
		else
			//Just increases the month number
			newMonth++;
	}

	//For negative day numbers (optional)
	if(newDay <= 0)
	{
		//Since we already went past the current month...
		newMonth--;
		//If we're at month '0'
		if(newMonth == 0)
		{
			//We set the month to 12
			newMonth = 12;
		}
		while(newDay < -30)
		{
			newMonth--;
			if(newMonth == 0)
			{
				newMonth = 12;
			}
			newDay = newDay + 30;
		}
		newDay = 30 + newDay;
		if (newDay == 0)
			newDay = 1;
	}

	monthNum = newMonth;
	dayNum = newDay;
}

/*
Adds an integer amount of days to a DayOfYear class.
Only handles the case of object + int. The other implementation which is not
a memeber of the DayOfYear class takes care of the int + object case since
that needs automatic type conversion.
Member function of the DayOfYear class.
*/
const DayOfYear DayOfYear::operator +(const int& daysToAdd) const
{
	int newMonth = month;
	int newDay = day;

	newDay = newDay + daysToAdd;

	//Rolls over the dates if necessary
	warpDayOfYear(newMonth,newDay);

	return DayOfYear(newMonth,newDay);
}

/*Has to be implemented as a non-memeber function to allow int + object.
Overloading this as a non-memeber gives us automatic type conversion.
Not a member of the DayOfYear class.
*/
const DayOfYear operator +(const int& daysToAdd, const DayOfYear& object)
{
	return (object + daysToAdd);
}

//Compares the months and days and returns a boolean.
const bool DayOfYear::operator >(const DayOfYear& secondObj) const
{
	if(month > secondObj.month)
	{
		return true;
	}
	else if((month == secondObj.month) && (day > secondObj.day))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Compares the months and days and returns a boolean.
const bool DayOfYear::operator <(const DayOfYear& secondObj) const
{
	if(month < secondObj.month)
	{
		return true;
	}
	else if((month == secondObj.month) && (day < secondObj.day))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Did not have to be overloaded, but chose to do so to save computation time.
const bool DayOfYear::operator ==(const DayOfYear& secondObj) const
{
	return ((month == secondObj.month) && (day == secondObj.day));
}

/*
Returns the end of the year minus the DayOfYear object.
Returs the object by value.
*/
const DayOfYear DayOfYear::operator -() const
{
	int newDay = 30 - day;
	int newMonth = 12 - month;
	newDay++;
	newMonth++;
	return DayOfYear(newMonth,newDay);
}

//Adds one day and returns modified DayOfYear object by reference.
//Prefix increment operator
DayOfYear& DayOfYear::operator ++()
{
	day++;
	//Checks if it needs to roll over
	if (day == 31)
	{
		day = 1;
		month++;
		//Checks if needs to roll over to new year (January)
		if (month > 12)
		{
			month = 1;
		}
	}
	//Returns by reference
	return* this;
}

//Adds one day and returns modified old DayOfYear object by value.
//Postfix increment operator
const DayOfYear DayOfYear::operator ++(int ingnoreMe)
{
	DayOfYear temp(month,day);
	day++;
	//Rolls over the dates if necessary
	warpDayOfYear(month,day);
	return temp;
}

//Subtracts one day and returns modified DayOfYear object by reference.
//Prefix decrement operator
DayOfYear& DayOfYear::operator --()
{
	day--;
	if (day == 0)
	{
		day = 30;
		month--;
		if (month == 0)
		{
			month = 12;
		}
	}
	//Returns by reference
	return* this;
}

//Subtracts one day and returns modified old DayOfYear object by value.
//Postfix decrement operator
const DayOfYear DayOfYear::operator --(int ingnoreMe)
{
	DayOfYear temp(month,day);
	day--;
	if (day == 0)
	{
		day = 30;
		month--;
		if (month == 0)
		{
			month = 12;
		}
	}
	return temp;
}

/*
Returns a read-only int data member according to the given input:
[1] - month
[2] - day
[3] - day of year
[anything else] - (-1)
*/
const int DayOfYear::operator [](int index) const
{
	if(index == 1)
		//Gets the month
		return month;
	else if(index == 2)
		//Gets the day
		return day;
	else if(index == 3)
		//Gets the day of year
		return getYearDay();
	else
		//All the other inputs (invalid inputs)
		return -1;
}

/*This is a test that runs when using any of the constructors to declare a
DayOfYear object. If declaration is invalid, the object will be set to the
default date of January 1st.
*/
void DayOfYear::testDate()
{
	if((month < 1) || (month > 12))
	{
		//ERROR!
		cout<<endl;
		cout<<"Illegal month value!\n";
		cout<<"Changed the month to the default value of 1. \n";
		month = 1;
	}
	if((day < 1) || (day > 30))
	{
		//ERROR!
		cout<<endl;
		cout<<"Illegal day value!\n";
		cout<<"Changed the day to the default value of 1. \n";
		day = 1;
	}
}

/*
Returns the number of days between two dates (DayOfYear objects).
Only performs the subtraction if the left operand is greater than the right
operand. Otherwise, an integer of 0 is returned and a message is displayed
that the left operand is bigger than the right operand.
*/
const int operator -(const DayOfYear& firstObject, const DayOfYear& secondObject)
{
	int daysBetween = 0;
	if(firstObject < secondObject)
	{
		//Displays a message that the left operand was smaller and returns a 0
		//Does not do the calculations.
		cout<<"The left operand is < than the right operand!\n";
		cout<<"Returning the default value of 0. \n";
		daysBetween = 0;
	}
	else
	{
		//Does the computation
		daysBetween = firstObject.getYearDay() - secondObject.getYearDay();
	}
	return daysBetween;
}

/*
Replaces the output() function.
Uses the outputSteam to print out the Month then the day.
*/
ostream& operator <<(ostream& outputStream, const DayOfYear& object)
{
	switch (object.month)
	{
		case 1:
			outputStream<<"January "; break;
		case 2:
			outputStream<<"February "; break;
		case 3:
			outputStream<<"March "; break;
		case 4:
			outputStream<<"April "; break;
		case 5:
			outputStream<<"May "; break;
		case 6:
			outputStream<<"June "; break;
		case 7:
			outputStream<<"July "; break;
		case 8:
			outputStream<<"August "; break;
		case 9:
			outputStream<<"September "; break;
		case 10:
			outputStream<<"October "; break;
		case 11:
			outputStream<<"November "; break;
		case 12:
			outputStream<<"December "; break;
		default:
			//Should not happen, but just in case.
			outputStream<<"Error! Invalid month!\n";
	}
	outputStream<<object.day;
	return outputStream;
}

/*
Replaces the input() function.
Acceptable input formats are: mm/dd, m/dd, mm/d, m/d
If an invalid input is given, the object will be set to the default
date of January 1st (1/1) and a message will be displayed.
*/
istream& operator >>(istream& inputStream, DayOfYear& object)
{
	string input;
	getline(inputStream,input);
	int length = input.length();

	//Checks if the input is valid:

	//Checks to see if there is a "/" in the string
	bool backslashCheck = false;
	for(int i = 0; i < length; i++)
	{
		if(input[i] == '/')
		{
			backslashCheck = true;
		}
	}
	if ((backslashCheck == false) || (length > 5) || (length < 3))
	{
		cout<<endl;
		cout<<"Invalid input!\n";
		cout<<"Used default date instead.\n";
		object.month = 1;
		object.day = 1;
		//Exits right here since an error occured.
		return inputStream;
	}

	string newMonth ="";
	string newDay= "";
	int intDay;
	int intMonth;

	//Extracts the relevant data from the input string
	bool monthFlag = true;
	for(int i = 0; i < length; i++)
	{
		if (input[i] == '/')
		{
			monthFlag = false;
			continue;
		}
		if(monthFlag == true)
		{
			newMonth+= input[i];
		}
		if(monthFlag == false)
		{
			newDay+= input[i];
		}
	}

	//Gets rid of the leading 0s if present
	if(newMonth[0] == '0')
	{
		newMonth.erase(newMonth.begin());
	}

	if(newDay[0] == '0')
	{
		newDay.erase(newDay.begin());
	}

	//Tests if the month or day string is empty
	if((newMonth.length() == 0) || (newDay.length() == 0))
	{
		cout<<endl;
		cout<<"Invalid input!\n";
		cout<<"Used default date instead.\n";
		object.month = 1;
		object.day = 1;
		//Returns right here since an error occured.
		return inputStream;
	}

	//Converts the string to an int
	intMonth = atoi(newMonth.c_str());
	intDay = atoi(newDay.c_str());

	//Checks if the entered date was valid
	if((intMonth < 1) || (intMonth > 12) || (intDay < 1) || (intDay > 30))
	{
		cout<<endl;
		cout<<"Invalid input!\n";
		cout<<"Used default date instead.\n";
		object.month = 1;
		object.day = 1;
		//Returns right here since an error occured.
		return inputStream;
	}
	else
	{
		object.month = intMonth;
		object.day = intDay;
	}
	return inputStream;
}
