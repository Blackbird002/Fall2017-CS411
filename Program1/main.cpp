/*
main.cpp
Riad Shash (Ray)
Class: CS411
Program #1

Tests the DayOfYear class by running various tests.
 */

#include "DayOfYear.hpp"
#include <iostream>
using namespace std;

//A function that prints the results of booleans as True/False.
void printBoolResult(bool test)
{
	if(test == true)
			cout<<"True! \n";
		else
			cout<<"False! \n";
}

int main(void)
{
	cout<<endl;
	cout<<"***************************************************************************\n";
	cout<<"----------------------Testing the DayOfYear Class!-------------------------\n";
	cout<<"***************************************************************************\n";

	cout<<endl;
    cout<<"___________________________________________________________________________\n";
	DayOfYear date1(12,30), date2(5,1), date3(5), date4;
	DayOfYear sameDate1(5,5), sameDate2(5,5);
	cout<<"The initialized dates are: \n";
	cout<<date1 <<endl;
	cout<<date2 <<endl;
	cout<<date3 <<endl;
	cout<<date4 <<endl;
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing declaration of DayOfYear object given invalid date: \n";
	cout<<"DayOfYear badDate(99,99); \n";
	DayOfYear badDate(99,99);
	cout<<"Result: " <<badDate <<endl;
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded '+' operator with two DayOfYear objects: \n";
	cout<<date1 <<" + " <<date2 <<" = \n";
	date3 = date1 + date2;
	cout<<"Result: " <<date3 <<endl;
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded '+' operator with an int: \n";
	date3 = DayOfYear(1,30);
	cout<<date3 <<" + 1 = \n";
	date3 = date3 + (1);
	cout<<"Result: " <<date3 <<endl;
	cout<<endl;

	date3 = DayOfYear(12,30);
	cout<<"1 + " <<date3 <<" = \n";
	date3 = 1 + date3;
	cout<<"Result: " <<date3 <<endl;
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded '>' operator with two DayOfYear objects: \n";
	bool test;
	cout<<date1 <<" > " <<date2 <<endl;
	test = date1 > date2;
	cout<<"Result: ";
	printBoolResult(test);
	cout<<endl;

	cout<<date2 <<" > " <<date1 <<endl;
	test = date2 > date1;
	cout<<"Result: ";
	printBoolResult(test);
	cout<<endl;

	cout<<sameDate1 <<" > " <<sameDate2 <<endl;
	test = sameDate1 < sameDate2;
	cout<<"Result: ";
	printBoolResult(test);
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded '<' operator with two DayOfYear objects: \n";
	cout<<date1 <<" < " <<date2 <<endl;
	test = date1 < date2;
	cout<<"Result: ";
	printBoolResult(test);
	cout<<endl;

	cout<<date2 <<" < " <<date1 <<endl;
	test = date2 < date1;
	cout<<"Result: ";
	printBoolResult(test);
	cout<<endl;

	cout<<sameDate1 <<" < " <<sameDate2 <<endl;
	test = sameDate1 < sameDate2;
	cout<<"Result: ";
	printBoolResult(test);
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Getting the total amount of days from a DayOfYear objects: \n";
	cout<<date2 <<endl;
	cout<<"Result: " <<date2.getYearDay() <<" day(s) in this object.\n";
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded '==' operator with two DayOfYear objects: \n";
	cout<<date1 <<" == " <<date2 <<endl;
	test = (date1 == date2);
	cout<<"Result: ";
	printBoolResult(test);
	cout<<endl;

	cout<<sameDate1 <<" == " <<sameDate2 <<endl;
	test = (sameDate1 == sameDate2);
	cout<<"Result: ";
	printBoolResult(test);
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded '-' operator with two DayOfYear objects: \n";
	date1 = DayOfYear(6,25);
	date2 = DayOfYear(6,23);
	cout<<date1 <<" - " <<date2 <<endl;
	int daysBetween = date1 - date2;
	cout<<"Result: " <<daysBetween <<endl;
	cout<<endl;

	date1 = DayOfYear(2,25);
	date2 = DayOfYear(8,23);
	cout<<date1 <<" - " <<date2 <<endl;
	daysBetween = date1 - date2;
	cout<<"Result: " <<daysBetween <<endl;
	cout<<endl;

	
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded '<<' ostream operator using a DayOfYear object: \n";
	cout<<"Result: " <<date3 <<endl;
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded 'unary -' operator using a DayOfYear object: \n";
	date3 = DayOfYear(1,1);
	cout<<" -" <<date3 <<endl;
	date3 = -date3;
	cout<<"Result: " <<date3 <<endl;
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded 'prefix ++ operator' using a DayOfYear object: \n";
	cout<<"++ " <<date3 <<endl;
	++date3;
	cout<<"Result: " <<date3 <<endl;
	cout<<endl;

	date3 = DayOfYear(4,11);
	cout<<"++ " <<date3 <<endl;
	++date3;
	cout<<"Result: " <<date3 <<endl;
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded 'postfix ++ operator' using a DayOfYear object: \n";
	date3 = DayOfYear(12,30);
	cout<<date3 <<" ++ \n";
	date3++;
	cout<<"Result: " <<date3 <<endl;
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded 'prefix -- operator' using a DayOfYear object: \n";
	cout<<"-- " <<date3 <<endl;
	--date3;
	cout<<"Result: " <<date3 <<endl;
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded 'postfix -- operator' using a DayOfYear object: \n";
	cout<<date3 <<" -- \n";
	date3--;
	cout<<"Result: " <<date3 <<endl;
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded '[]' using a DayOfYear object: \n";
	DayOfYear date6(5,25);
	cout<<date6 <<endl;
	cout<<"Results: \n";
	cout<<"[1] - Month: " <<date6[1] <<endl;
	cout<<"[2] - Day: " <<date6[2] <<endl;
	cout<<"[3] - Day of year: " <<date6[3] <<endl;
	cout<<"[ 4] - Invalid Input of '4': " <<date6[4] <<endl;
	cout<<endl;
	cout<<"___________________________________________________________________________\n";

	cout<<"Testing the overloaded '>>' using a DayOfYear object: \n";
	DayOfYear test1, test2, test3, test4;

	cout<<"Enter a date (mm/dd, m/dd, mm/d, m/d): \n";
	cin>>test1;
	cout<<"Result: " <<test1 <<endl;
	cout<<endl;

	cout<<"Enter a date (mm/dd, m/dd, mm/d, m/d): \n";
	cin>>test2;
	cout<<"Result: " <<test2 <<endl;
	cout<<endl;

	cout<<"Enter a date (mm/dd, m/dd, mm/d, m/d): \n";
	cin>>test3;
	cout<<"Result: " <<test3 <<endl;
	cout<<endl;

	cout<<"Enter a date (mm/dd, m/dd, mm/d, m/d): \n";
	cin>>test4;
	cout<<"Result: " <<test4 <<endl;
	cout<<endl;

	cout<<endl;
	cout<<"***************************************************************************\n";
	cout<<"------------------------------END OF TEST----------------------------------\n";
	cout<<"***************************************************************************\n";
	cout<<endl;
	
	return 0;
}
