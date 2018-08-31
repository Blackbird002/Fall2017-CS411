#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "PFAString.hpp"

bool testDConstr();		// Default constructor
bool testCapConstr();	// Capacity constructor
bool testFillConstr();	// Fill constructor
bool testCopConstr();	// Copy constructor
bool testGetCap();
bool testGetSize();
bool testPushBack();
bool testPopBack();
bool testResizeSmaller();
bool testResizeLarger();
bool testEmpty();
bool testExpansion();
bool testSQBLV();	// Square brackets as an l-value
bool testSQAcc();	// Square brackets as access
bool testAssgn();	// Assignment operator
bool testEQUIVT();	// Equivalance with true result
bool testEQUIVF();	// Equivalence with false result
bool testLTT();		// Less than with true result
bool testLTF();		// Less than with false result
bool testGTT();		// Greater than with true result
bool testGTF();		// Greater than with false result
bool testLEQT();	// Less than or equal to with true result
bool testLEQE();	// Less than or equal to when equivalent (expect true)
bool testLEQF();	// Less than or equal to with false result
bool testGEQT();	// Greater than or equal to with true result
bool testGEQE();	// Greater than or equal to when equivalent (expect true)
bool testGEQF();	// Greater than or equal to with false result


const int COL = 37;

int main()
{
	std::ofstream outf("outfile");
	if (outf.fail()) {
		std::cout << "Error opening output file. Exiting...\n";
		return 1;
	}

	outf << std::setw(COL) << std::left << "Default Constructor:" << testDConstr() << std::endl;
	outf << std::setw(COL) << std::left << "Capacity Constructor:" << testCapConstr() << std::endl;
	outf << std::setw(COL) << std::left << "Fill Constructor:" << testFillConstr() << std::endl;
	outf << std::setw(COL) << std::left << "Copy Constructor:" << testCopConstr() << std::endl;
	outf << std::setw(COL) << std::left << "Function getCapacity:" << testGetCap() << std::endl;
	outf << std::setw(COL) << std::left << "Function getSize:" << testGetSize() << std::endl;
	outf << std::setw(COL) << std::left << "Function push_back:" << testPushBack() << std::endl;
	outf << std::setw(COL) << std::left << "Function pop_back:" << testPopBack() << std::endl;
	outf << std::setw(COL) << std::left << "Function resize (shrink):" << testResizeSmaller() << std::endl;
	outf << std::setw(COL) << std::left << "Function resize (grow):" << testResizeLarger() << std::endl;
	outf << std::setw(COL) << std::left << "Function empty_array:" << testEmpty() << std::endl;
	outf << std::setw(COL) << std::left << "Array expansion:" << testExpansion() << std::endl;
	outf << std::setw(COL) << std::left << "Square bracket l-value:" << testSQBLV() << std::endl;
	outf << std::setw(COL) << std::left << "Square bracket access:" << testSQAcc() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Assignment:" << testAssgn() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Equivalency(T):" << testEQUIVT() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Equivalency(F):" << testEQUIVF() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Less than(T):" << testLTT() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Less than(F):" << testLTF() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Greater than(T):" << testGTT() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Greater than(F):" << testGTF() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Less than or Equal(T):" << testLEQT() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Less than or Equal(E):" << testLEQE() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Less than or Equal(F):" << testLEQF() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Greater than or Equal(T):" << testGEQT() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Greater than or Equal(E):" << testLEQE() << std::endl;
	outf << std::setw(COL) << std::left << "Operator Greater than or Equal(F):" << testLEQE() << std::endl;

	outf.close();

	return 0;
}

bool testDConstr()
{
	PFAString obj;
	return (obj.get_capacity() == 0 && obj.get_size() == 0);
}

bool testCapConstr()
{
	PFAString obj(5);
	return (obj.get_capacity() == 5 && obj.get_size() == 0);
}

bool testFillConstr()
{
	int cap = 5;
	std::string PATTERN = "HI-DIDDLY-HO";
	PFAString obj(cap, PATTERN);

	if (obj.get_capacity() == cap && obj.get_size() == cap) {
		for (int i = 0; i < cap; ++i) {
			if (obj[i] != PATTERN) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}

bool testCopConstr()
{
	PFAString one;
	one.push_back("THIS");
	one.push_back("IS");
	one.push_back("SPARTA");

	PFAString two = one;

	if (two.get_capacity() == 3 && two.get_size() == 3) {
		for (int i = 0; i < one.get_size(); ++i) {
			if (two[i] != one[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool testGetCap()
{
	int cap = 10;
	PFAString obj(cap);

	return (obj.get_capacity() == cap);
}

bool testGetSize()
{
	PFAString obj(3, "HUH");

	return (obj.get_size() == 3);
}

bool testPushBack()
{
	PFAString obj(3);
	obj.push_back("HUUH");

	return (obj[0] == "HUUH");
}

bool testPopBack()
{
	PFAString obj(3, "GANGNAM");
	obj.pop_back();

	return (obj.get_size() == 2);
}

bool testResizeSmaller()
{
	PFAString obj(3, "HULLO");
	obj.resize(1);

	return (obj.get_size() == 1 && obj.get_capacity() == 3 && obj[0] == "HULLO");
}

bool testResizeLarger()
{
	PFAString obj(3, "HULLO");
	obj.resize(5, "PSY");

	for (int i = 0; i < 3; ++i) {
		if (obj[i] != "HULLO") {
			return false;
		}
	}
	for (int i = 3; i < 5; ++i) {
		if (obj[i] != "PSY") {
			return false;
		}
	}

	return (obj.get_size() == 5 && obj.get_capacity() == 5);
}

bool testEmpty()
{
	PFAString obj(3, "PSY");
	obj.empty_array();

	return (obj.get_capacity() == 3 && obj.get_size() == 0);
}

bool testExpansion()
{
	PFAString obj(3, "GANGNAM");
	obj.push_back("STYLE");

	return (obj.get_capacity() == 6 && obj.get_size() == 4);
}

bool testSQBLV()
{
	PFAString obj(2, "LILY");
	obj[1] = "FLOWER";

	return (obj[0] == "LILY" && obj[1] == "FLOWER");
}

bool testSQAcc()
{
	PFAString obj(1, "LILY");

	return (obj[0] == "LILY");
}

bool testAssgn()
{
	PFAString obj(3, "HOW");
	PFAString test(4, "NOW");

	test = obj;

	for (int i = 0; i < test.get_size(); ++i) {
		if (test[i] != "HOW") {
			return false;
		}
	}

	return (test.get_capacity() == 3 && test.get_size() == 3);
}

bool testEQUIVT()
{
	PFAString obj;
	PFAString test(3, "HI");

	obj.push_back("HI");
	obj.push_back("HI");
	obj.push_back("HI");

	return (obj == test);
}

bool testEQUIVF()
{
	PFAString obj, test;
	obj.push_back("HI");
	test.push_back("HO");

	return !(obj == test);
}

bool testLTT()
{
	PFAString obj, test;

	obj.push_back("A");
	test.push_back("B");

	return (obj < test);
}

bool testLTF()
{
	PFAString obj, test;
	
		obj.push_back("A");
		test.push_back("B");
	
		return !(test < obj);
}
bool testGTT()
{
	PFAString obj, test;
	
		obj.push_back("A");
		test.push_back("B");
	
		return (test > obj);
}

bool testGTF()
{
	PFAString obj, test;
	
		obj.push_back("A");
		test.push_back("B");
	
		return !(obj > test);
}

bool testLEQT()
{
	PFAString obj, test;

	obj.push_back("B");
	test.push_back("B");
	test.push_back("B");

	return (obj <= test);
}

bool testLEQE()
{
	PFAString obj, test;

	obj.push_back("THIS");
	obj.push_back("IS");
	obj.push_back("SPARTA! *punt*");

	test = obj;

	return (obj <= test);
}

bool testLEQF()
{
	PFAString obj, test;
	
	obj.push_back("THIS");
	obj.push_back("IS");
	obj.push_back("SPARTA! *punt*");

	test = obj;
	test.push_back("AAaah");

	return !(test <= obj);
}

bool testGEQT()
{
	PFAString obj, test;

	obj.push_back("AIAIAI");
	test.push_back("AHAHAH");

	return (obj >= test);
}

bool testGEQE()
{
	PFAString obj, test;
	
	obj.push_back("THIS");
	obj.push_back("IS");
	obj.push_back("SPARTA! *punt*");

	test = obj;

	return (test >= obj);
}

bool testGEQF()
{
	PFAString obj, test;
	
	obj.push_back("THIS");
	obj.push_back("IS");
	obj.push_back("SPARTA! *punt*");

	test = obj;
	test.push_back("AAaah");

	return !(obj <= test);
}
