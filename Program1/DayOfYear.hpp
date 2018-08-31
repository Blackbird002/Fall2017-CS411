/*******************************************************************************
    DayOfYear.hpp
    Riad Shash (Ray)
    Class: CS411
    Program #1

    *Non-extra credit version. (360 days in the year)

    This assignment modifies the DayOfYear class found in display 7.1 in the
    textbook. It includes numerous additions and adds overloaded operator ope-
    rations. It assumes a 12 month year with 30 days in each month (360 days in
    a year).

 ******************************************************************************/

#ifndef DAYOFYEARHPP
#define DAYOFYEARHPP

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class DayOfYear
{
public:
    //Constructors:
    DayOfYear(int monthValue, int dayValue);
    DayOfYear(int monthValue);
    DayOfYear();

    void input();
    void output() const;

    int getMonthNumber() const;
    int getDay() const;
    int getYearDay() const;

    //Member overloaded operators:
    const DayOfYear operator +(const DayOfYear& secondObj) const;
    const DayOfYear operator +(const int& daysToAdd) const;

    const bool operator >(const DayOfYear& secondObj) const;
    const bool operator <(const DayOfYear& secondObj) const;
    const bool operator ==(const DayOfYear& secondObj) const;
    const DayOfYear operator -() const; //Unary minus operator
    DayOfYear& operator++(); //Prefix increment operator
    const DayOfYear operator++(int ignoreMe);	//Postfix increment operator
    DayOfYear& operator--(); //Prefix decrement operator
    const DayOfYear operator--(int ignoreMe);	//Postfix  decrement operator
    const int operator [](int index) const; //Array operator

    //Implemented as friend function so it has access to private data in object
    friend ostream& operator <<(ostream& outputStream, const DayOfYear& object);
    friend istream& operator >>(istream& inputStream, DayOfYear& object);


private:
    int month;
    int day;
    void testDate();
    void warpDayOfYear(int &monthNum, int &dayNum) const;   //Handles roll over.
};

//Non-member overloaded operators:

//Non member, non friend overloaded "-" operator
const int operator -(const DayOfYear& fristObj, const DayOfYear& secondObj);

//Has to be implemented as a non-memeber function to allow int + object.
const DayOfYear operator +(const int& daysToAdd, const DayOfYear& object);

#endif // DAYOFYEARHPP
