#include <iostream>
#include <string>
#include "PFAString.hpp"
using namespace std;

//Helper function that prints boolean values
namespace
{
	std::string printBool(bool test)
	{
		if(test == true)
			return "True";
		else
			return "False";
	}
}

int main()
{
	cout<<endl;
	cout<<"***************************************************************************\n";
	cout<<"----------------------Testing the PFAString Class!-------------------------\n";
	cout<<"***************************************************************************\n";

	cout<<std::endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the constructors: \n";

	cout<<"PFAString testobj\n";
	PFAString testObj;
	cout<<"Results: \n";
	cout<<"testObj = ";
	testObj.printStrings();
	cout<<std::endl;

	cout<<"PFAString testobj(5)\n";
	PFAString testObj1(5);
	cout<<"Results: \n";
	cout<<"testObj1 = ";
	testObj1.printStrings();
	cout<<std::endl;

	cout<<"PFAString testobj(5,'testObj2')\n";
	PFAString testObj2(5, "testObj2");
	cout<<"Results: \n";
	cout<<"testObj2 = ";
	testObj2.printStrings();


	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the accessor functions: \n";

	cout<<"testObj.get_capacity()\n";
	cout<<"testObj.get_size()\n";
	cout<<"Results: \n";
	cout<<"Capacity: " <<testObj.get_capacity() <<endl;
	cout<<"Size: " <<testObj.get_size() <<endl;
	cout<<endl;

	cout<<"testObj1.get_capacity()\n";
	cout<<"testObj1.get_size()\n";
	cout<<"Results: \n";
	cout<<"Capacity: " <<testObj1.get_capacity() <<endl;
	cout<<"Size: " <<testObj1.get_size() <<endl;
	cout<<endl;

	cout<<"testObj2.get_capacity()\n";
	cout<<"testObj2.get_size()\n";
	cout<<"Results: \n";
	cout<<"Capacity: " <<testObj2.get_capacity() <<endl;
	cout<<"Size: " <<testObj2.get_size() <<endl;

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the push_back() function: \n";

	cout<<"testObj.push_back('CS211')\n";
	cout<<"testObj.push_back('CS300')\n";
	cout<<"Results: \n";
	testObj.push_back("CS211");
	testObj.push_back("CS300");
	cout<<"testObj = ";
	testObj.printStrings();
	cout<<endl;

	cout<<"testObj2.push_back('CS211')\n";
	testObj2.push_back("CS211");
	cout<<"Results: \n";
	cout<<"testObj2 = ";
	testObj2.printStrings();
	cout<<endl;

	cout<<"PFAString testPushObj(10,'test');\n";
	PFAString testPushObj(10,"test");
	cout<<"Capacity: " <<testPushObj.get_capacity() <<endl;
	cout<<"Size: " <<testPushObj.get_size() <<endl;

	cout<<"testPushObj.push_back('test1');\n";
	testPushObj.push_back("test1");
	cout<<"Capacity: " <<testPushObj.get_capacity() <<endl;
	cout<<"Size: " <<testPushObj.get_size() <<endl;

	testPushObj.printStrings();

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the pop_back() function: \n";

	cout<<"testObj2.pop_back()\n";
	cout<<"Results: \n";
	testObj2.pop_back();
	cout<<"testObj2 = ";
	testObj2.printStrings();
	cout<<endl;

	cout<<endl;
	cout<<"testObj2.pop_back()\n";
	cout<<"Results: \n";
	testObj2.pop_back();
	cout<<"testObj2 = ";
	testObj2.printStrings();

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the resize() function: \n";

	cout<<"testObj2.resize(8, 'SWIW')\n";
	cout<<"Results: \n";
	testObj2.resize(8, "SWIW");
	cout<<"testObj2 = ";
	testObj2.printStrings();
	cout<<"Capacity: " <<testObj2.get_capacity() <<endl;
	cout<<"Size: " <<testObj2.get_size() <<endl;

	cout<<"testObj2.resize(5)\n";
	cout<<"Results: \n";
	testObj2.resize(5);
	cout<<"testObj2 = ";
	testObj2.printStrings();
	cout<<"Capacity: " <<testObj2.get_capacity() <<endl;
	cout<<"Size: " <<testObj2.get_size() <<endl;

	cout<<"testObj2.resize(0)\n";
	cout<<"Results: \n";
	testObj2.resize(0);
	cout<<"testObj2 = ";
	testObj2.printStrings();
	cout<<"Capacity: " <<testObj2.get_capacity() <<endl;
	cout<<"Size: " <<testObj2.get_size() <<endl;

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the empty_array() function: \n";

	cout<<"testObj2.empty_array()\n";
	cout<<"Results: \n";
	testObj2.empty_array();
	cout<<"testObj2 = ";
	testObj2.printStrings();
	cout<<"Capacity: " <<testObj2.get_capacity() <<endl;
	cout<<"Size: " <<testObj2.get_size() <<endl;

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the overloaded [] operator with a PFAString object: \n";

	cout<<"PFAString testObj3(8,'testObj3')\n";
	cout<<"testObj3[0] = 'CS540' \n";
	PFAString testObj3(8, "testObj3");
	testObj3[0] = "CS540";

	cout<<"Results: \n";
	cout<<"testObj3 = ";
	testObj3.printStrings();
	cout<<endl;

	cout<<"testObj3[3] = 'CS410' \n";
	testObj3[3] = "CS410";
	cout<<"Results: \n";
	cout<<"testObj3 = ";
	testObj3.printStrings();
	cout<<endl;

	cout<<"testObj3[7] = 'CS300' \n";
	testObj3[7] = "CS300";
	cout<<"Results: \n";
	cout<<"testObj3 = ";
	testObj3.printStrings();
	cout<<endl;

	cout<<"cout<<testObj3[4]\n";
	cout<<"Results: \n";
	cout<<testObj3[3];
	cout<<endl;

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the overloaded = operator: \n";

	cout<<"PFAString testObj4 \n";
	cout<<"testObj4 = testObj3 \n";
	cout<<"Results: \n";
	PFAString testObj4;
	testObj4 = testObj3;

	cout<<"testObj3 = ";
	testObj3.printStrings();
	cout<<"testObj4 = ";
	testObj4.printStrings();
	cout<<endl;

	cout<<"testObj3: \n";
	cout<<"Capacity: " <<testObj3.get_capacity() <<endl;
	cout<<"Size: " <<testObj3.get_size() <<endl;

	cout<<"testObj4: \n";
	cout<<"Capacity: " <<testObj4.get_capacity() <<endl;
	cout<<"Size: " <<testObj4.get_size() <<endl;

	cout<<endl;
	testObj4 = testObj4;
	cout<<"testObj4 = testObj4 \n";
	cout<<"Results: \n";
	cout<<"Capacity: " <<testObj4.get_capacity() <<endl;
	cout<<"Size: " <<testObj4.get_size() <<endl;
	cout<<"testObj4 = ";
	testObj4.printStrings();

	cout<<endl;
	cout<<"testObj4.push_back('CS194')\n";
	testObj4.push_back("CS194");
	cout<<"Capacity: " <<testObj4.get_capacity() <<endl;
	cout<<"Size: " <<testObj4.get_size() <<endl;
	testObj4.push_back("CS560");
	cout<<"testObj4.push_back('CS560')\n";
	cout<<"Capacity: " <<testObj4.get_capacity() <<endl;
	cout<<"Size: " <<testObj4.get_size() <<endl;

	cout<<endl;
	testObj4 = testObj4;
	cout<<"testObj4 = testObj4 \n";
	cout<<"Results: \n";
	cout<<"Capacity: " <<testObj4.get_capacity() <<endl;
	cout<<"Size: " <<testObj4.get_size() <<endl;
	cout<<"testObj4 = ";
	testObj4.printStrings();

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the overloaded == operator: \n";

	cout<<"testObj3 == testObj4\n";
	cout<<"Result: \n";
	bool test = (testObj3 == testObj4);
	cout<<printBool(test) <<endl;

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the overloaded != operator: \n";

	cout<<"testObj3 != testObj4\n";
	cout<<"Result: \n";
	test = (testObj3 != testObj4);
	cout<<printBool(test) <<endl;

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the overloaded < operator using two PFAString objects: \n";

	PFAString testObj5(2,"abc");
	testObj5.push_back("def");
	testObj5.push_back("ghi");
	cout<<"testObj5 = ";
	testObj5.printStrings();
	cout<<endl;

	PFAString testObj6(2,"jkl");
	testObj6.push_back("mno");
	testObj6.push_back("pqr");
	cout<<"testObj6 = ";
	testObj6.printStrings();
	cout<<endl;

	cout<<"test5 < test6\n";
	test = (testObj5 < testObj6);
	cout<<"Result: \n";
	cout<<printBool(test) <<endl;

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the overloaded > operator using two PFAString objects: \n";

	cout<<"testObj5 = ";
	testObj5.printStrings();
	cout<<endl;

	cout<<"testObj6 = ";
	testObj6.printStrings();
	cout<<endl;

	cout<<"test5 > test6\n";
	test = (testObj5 > testObj6);
	cout<<"Result: \n";
	cout<<printBool(test) <<endl;

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the overloaded >= operator using two PFAString objects: \n";

	cout<<"testObj5 = ";
	testObj5.printStrings();
	cout<<endl;

	cout<<"testObj6 = ";
	testObj6.printStrings();
	cout<<endl;

	cout<<"test5 >= test6\n";
	test = (testObj5 >= testObj6);
	cout<<"Result: \n";
	cout<<printBool(test) <<endl;

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<"Testing the overloaded <= operator using two PFAString objects: \n";

	cout<<"testObj5 = ";
	testObj5.printStrings();
	cout<<endl;

	cout<<"testObj6 = ";
	testObj6.printStrings();
	cout<<endl;

	cout<<"test5 <= test6\n";
	test = (testObj5 <= testObj6);
	cout<<"Result: \n";
	cout<<printBool(test) <<endl;

	cout<<endl;
	cout<<"___________________________________________________________________________\n";
	cout<<endl;
	cout<<"***************************************************************************\n";
	return 0;
}
