/*
	PFAString.cpp
	Riad Shash (Ray)
	Class: CS411
	Program #2
 */

#include <iostream>
#include <cstdlib>
#include "PFAString.hpp"


// Default constructor
PFAString::PFAString()
{
	arr = nullptr;
	capacity = 0;
	size = 0;
}

// Constructor that sets the capacity
PFAString::PFAString(int inputCapacity)
{
	if (inputCapacity > 0)
	{
		capacity = inputCapacity;
		size = 0;
		arr = new std::string[capacity];
	}
	else if (inputCapacity == 0)
	{
		// Default values are set here as well
		capacity = 0;
		size = 0;
		arr = nullptr;
	}
	else
	{
		// A invalid capacity was entered!
		// Default values are set
		capacity = 0;
		size = capacity;
		arr = nullptr;
		std::cout<<"Error! Invalid capacity! Capacity set to 0! \n";
	}
}

// A helper class function that prints (using cout) all the contents in the array
void PFAString::printStrings()
{
	if(arr != nullptr)
	{
		for(int i = 0; i < size; i++)
		{
			std::cout<<arr[i] <<" ";
		}
		std::cout<<std::endl;
	}
}

PFAString::PFAString(int inputCapacity, std::string inputString)
{
	if (inputCapacity > 0)
	{
		capacity = inputCapacity;
		size = capacity;
		// The size equals the capacity because the array is full
		arr = new std::string[capacity];
	}
	else if (capacity == 0)
	{
		capacity = 0;
		size = 0;
		arr = nullptr;
	}
	else
	{
		// A invalid capacity was entered!
		// Default values are set
		capacity = 0;
		size = 0;
		arr = nullptr;
		std::cout<<"Error! Invalid capacity! Capacity set to 0! \n";
	}

	// Fills the array elements with the input string
	if(arr != nullptr)
	{
		for(int i = 0; i < capacity; i++)
		{
			arr[i] = inputString;
		}
	}
}

/*
Copy Constructor
Capacity of new object is equal to the size of the object being copied
*/
PFAString::PFAString(const PFAString& PFAobj):capacity(PFAobj.size), size(PFAobj.size)
{
	if (capacity > 0)
	{
		//Makes arr point to new allocated memory in heap
		arr = new std::string[capacity];

		//Copies the element to the array from the object being copied
		for(int i = 0; i < capacity ; i++)
		{
			arr[i] = PFAobj.arr[i];
		}
	}
	else
	{
		arr = nullptr;
	}
}

// Destructor
PFAString::~PFAString()
{
	if (arr != nullptr)
		delete [] arr;
}

// Accessor that gets the capacity
const int PFAString::get_capacity() const
{
	return capacity;
}

// Accessor that gets the size
const int PFAString::get_size() const
{
	return size;
}

// Doubles the capacity of the dynamic array
void PFAString::doubleCapacity()
{
	if(arr != nullptr)
	{
		//creates a copy of capacity and then doubles the capacity
		int previousCapacity = capacity;
		capacity *= 2;

		//Sets the previous Array pointer to this temporary pointer.
		std::string *previousArray = arr;

		//Allocates memory for a array of strings with double capacity.
		arr = new std::string[capacity];

		//Copies the previous array elements to the new dynamic array
		for(int i = 0; i < previousCapacity ; i++)
		{
			arr[i] = previousArray[i];
		}

		//Frees up the memory used by the previous array
		delete [] previousArray;
	}
	else
	{
		std::cout<<"Error, capacity is 0! Double capacity aborted! \n";
	}

}

// Changes the capacity of the dynamic array according to input parameter (helper)
void PFAString::changeCapacity(const int& newCapacity)
{
	if (newCapacity > 0)
	{
		// Creates a copy of capacity and then doubles the capacity.
		int previousCapacity = capacity;
		capacity = newCapacity;

		// Sets the previous Array pointer to this temporary pointer.
		std::string *previousArray = arr;

		// Allocates memory for a array of strings with double capacity.
		arr = new std::string[capacity];

		// Determines the smallest size value for the following for loop.
		int smallestCapacity;
		if (previousCapacity < newCapacity)
			smallestCapacity = previousCapacity;
		else
			smallestCapacity = newCapacity;

		// Copies the previous array elements to the new dynamic array.
		for(int i = 0; i < smallestCapacity ; i++)
		{
			arr[i] = previousArray[i];
		}

		// Frees up the memory used by the previous array.
		delete [] previousArray;
	}
	else
	{
		// deletes the allocated memory that arr points to
		delete [] arr;

		// sets the dangling pointer to a nullptr
		arr = nullptr;

		capacity = 0;
	}

	if (capacity < size)
	{
		size = capacity;
	}

}

// Changes the size, a helper function
void PFAString::changeSize(const int& newSize)
{
	//The case where we're making the size bigger (so we add "")
	if(newSize > size)
	{
		for(int i = size; i < newSize; i++)
		{
			arr[i] = "";
		}
	}
	else if(newSize < size)
	{
		for(int i = newSize; i < size; i++)
		{
			arr[i] = "";
		}
	}
	size = newSize;
}

/*
 * Places a string at the back of the array.
 * When an attempt is made to write to the next element after the current capacity,
 * the array expands to twice its size. So if the capacity is 20 and an attempt to
 * write to the 21st element is made, the capacity doubles to 40 and then the 21st
 * element is written.
 */
void PFAString::push_back(std::string inputString)
{
	if(arr != nullptr)
	{
		// Check if the array is full or not
		if(isArrFull() == true)
		{
			// Doubles the capacity of the array
			doubleCapacity();
		}
		arr[size] = inputString;
		size++;
	}
	else
	{
		//If the arr pointer is a nullptr, need to allocated memory for the array
		capacity++;
		arr = new std::string[capacity];
		arr[size] = inputString;
		size++;
	}
}

// function pop_back   // "Destroys" the string at the back of the array
void PFAString::pop_back()
{
	if(arr != nullptr)
	{
		//Handles the case when the size is 0 but the capacity is not
		if (size != 0)
		{
			arr[size-1] = "";
			size--;
		}
	}
	else
		std::cout<<"Error, capacity is 0! pop_back aborted! \n";
}

/*
 * Function resize that also takes in a string input parameter
 * It fills the newly created elements with the given input string.
 */
void PFAString::resize(int newSize, std::string inputString)
{
	int previousSize = size;

	if (newSize < 0 )
	{
		std::cout<<"Error, the new size cannot be negative! Resize aborted! \n";
		return;
	}
	else if (arr != nullptr)
	{
		if(newSize > capacity)
		{
			changeCapacity(newSize);
			changeSize(newSize);
		}
		else if(newSize < capacity)
		{
			changeSize(newSize);
		}
	}
	else if (arr == nullptr)
	{
		changeCapacity(newSize);
		changeSize(newSize);
	}

	// Fills all the empty array elements with the inputString string.
	if(size > previousSize)
	{
		for(int i = previousSize; i < size; i++)
		{
			arr[i] = inputString;
		}
	}

}


// Sets the size to 0 and clears the array
void PFAString::empty_array()
{
	if(arr != nullptr)
	{
		// Clears the array elements
		for(int i = 0; i < size; i++)
		{
			arr[i] = "";
		}
		size = 0;
	}
	else
		std::cout<<"Error, capacity is 0! empty_array aborted! \n";
}

/* overloaded operator []  //Works as an l-value
 * The value in the array position can be viewed and also changed.
 */
std::string& PFAString::operator[](int index)
{
	if((index > (size-1)) || (index < 0) || (arr == nullptr))
	{
		std::cout<<"An attempt was made to access the array out of bounds! Program terminated!\n";
		std::exit(1);		// Exits the program
	}
	//Returns the specific element as a reference
	return arr[index];
}


/*
 * overloaded operator =
 * Capacity of new object is equal to the size of the object being copied.
 * Handles the self-assignment situations
 */
PFAString& PFAString::operator =(const PFAString& PFAobj)
{
	bool isSelfAssign = false;
	std::string *temparr = nullptr;

	// Checks to see if this is a self-assignment
	if (this == &PFAobj)
	{
		isSelfAssign = true;
		temparr = arr;
	}

	if((arr != nullptr) && (isSelfAssign == false))
		//Deletes the allocated memory of the caller (the object on the left)
		delete [] arr;
	else
		// temp ptr set to dynaimc array
		// self-assignment
		temparr = arr;

	if (PFAobj.capacity > 0)
	{
		// Capacity of new object is equal to the size of the object being copied
		size = PFAobj.size;
		capacity = size;

		// Makes arr point to new allocated memory in heap
		arr = new std::string[capacity];

		//Copies the element to the array from the object being copied
		if (isSelfAssign == false)
		{
			for(int i = 0; i < capacity ; i++)
			{
				arr[i] = PFAobj.arr[i];
			}
		}
		else
		// If this is a self-assignment
		{
			for(int i = 0; i < capacity ; i++)
			{
				arr[i] = temparr[i];
			}
			// Deletes the prevous dynamic array that temparr pointed to
			if (temparr != nullptr)
				delete [] temparr;
		}
	}
	else
	{
		arr = nullptr;
		size = 0;
		capacity = 0;
	}
	return *this;
}

// overloaded operator ==
bool PFAString::operator ==(const PFAString& PFAobj) const
{
	// If both arr pointers are nullptrs
	if(arr == nullptr && PFAobj.arr == nullptr)
	{
		return true;
	}
	else if ((arr != nullptr) && (PFAobj.arr != nullptr))
	{
		// If the sizes are both the same
		if(size == PFAobj.size)
		{
			// Compares the elements in both arrays
			for (int i = 0; i < size; i++)
			{
				if(arr[i] != PFAobj.arr[i])
					return false;
			}
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

/*
 * Overloaded operator !=
 * Had to overloaded because != overload is not automatic
 */
bool PFAString::operator !=(const PFAString& PFAobj) const
{
	return !(*this == PFAobj);
}

/*
  This is the code I used to base my code off of:

	  template <class InputIterator1, class InputIterator2>
	  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)

	  while (first1!=last1)
	  {
		if (first2==last2 || *first2<*first1) return false;
		else if (*first1<*first2) return true;
		++first1; ++first2;
	  }
	  return (first2!=last2);


	for my implementation:
	  first1 starts at the 1st element in array1 (pointer)
	  last1 is the last element in the array1 (pointer)

	  first2 starts at the 1st element in array2 (pointer)
	  last2 is the last element in the array2 (pointer)

	  *first1.. means the actual value in the element


 Overloaded < operator, please look at code above
 */
bool PFAString::operator <(const PFAString& PFAobj) const
{
	int i = 0;		//first1
	int j = 0;		//first2

	//while (first1!=last1)
	while(i != size)
	{
		//if (first2==last2 || *first2<*first1)
		if((j == PFAobj.size) || PFAobj.arr[i] < arr[i])
			return false;
		//else if (*first1<*first2)
		else if (arr[i] < PFAobj.arr[j])
			return true;
		i++;
		j++;
	}
	//return (first2!=last2);
	return (j != PFAobj.size);
}

/*
 * Overloaded > operator
 * Equivalent operation is b < a:
 */
bool PFAString::operator >(const PFAString& PFAobj) const
{
	return (PFAobj < (*this));
}

// overloaded <= operator
bool PFAString::operator <=(const PFAString& PFAobj) const
{
	if ((*this < PFAobj) || (*this == PFAobj))
		return true;
	else
		return false;
}

// overloaded >= operator
bool PFAString::operator >=(const PFAString& PFAobj) const
{
	if ((*this > PFAobj) || (*this == PFAobj))
		return true;
	else
		return false;
}

// Returns true if the size and capacity are equal
const bool PFAString::isArrFull() const
{
	if (capacity == size)
		return true;
	else
		return false;
}
