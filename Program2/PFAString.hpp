/*******************************************************************************
    PFAString.hpp
    Riad Shash (Ray)
    Class: CS411
    Program #2

   This class is a weak implementation of the vector class. It is a dynamic
   array of strings.

 ******************************************************************************/

#ifndef PFASTRING_HPP
#define PFASTRING_HPP

#include <string>

class PFAString {
public:
    // Default constructor
	PFAString();

    // Constructor that sets capacity
	PFAString(int inputCapacity);

    // Constructor that sets capacity and initializes all elements to a specific string
	PFAString(int inputCapacity, std::string inputString);

    // Copy Constructor
	PFAString(const PFAString& PFAobj);

    // Destructor
	~PFAString();

    // function get_capacity
	const int get_capacity() const;

    // function get_size
	const int get_size() const;

    // function push_back  // Places a string at the back of the array
	void push_back(std::string inputString);

    // function pop_back   // Destroys the string at the back of the array
	void pop_back();

    // function resize that also takes in a string input parameter
	void resize(int newSize, std::string inputString = std::string());

    // empty_array         // Sets the size to zero
	void empty_array();

    // overload operator []    // Needs to work as l-value
	std::string& operator[](int index);

    // overload operator =     // MUST work as l-value
	PFAString& operator =(const PFAString& PFAobj);

    // overload operator ==
	bool operator ==(const PFAString& PFAobj) const;

	// overload operator !=
	bool operator !=(const PFAString& PFAobj) const;

    // overload operator <
	bool operator <(const PFAString& PFAobj) const;

    // overload operator >
	bool operator >(const PFAString& PFAobj) const;

    // overload operator <=
	bool operator <=(const PFAString& PFAobj) const;

    // overload operator >=
	bool operator >=(const PFAString& PFAobj) const;

	// prints the elements of the dynamic array
	void printStrings();
private:
    std::string *arr;	// Pointer that points to the allocated memory
    int capacity;       // Capacity is the size of the array container
    int size;			// Size is the number of elements in the array container (how many strings)

    //Returns true if the size and capacity are equal
    const bool isArrFull() const;

    // Doubles the capacity of the array and then copies the elements over
    void doubleCapacity();

    // Changes capacity of the array to newCapacity parameter and copies the elements over
    void changeCapacity(const int& newCapacity);

    //Changes the size of current object, assumes that the capacity is ok
    void changeSize(const int& newSize);
};

#endif
