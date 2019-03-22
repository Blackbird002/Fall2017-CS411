/*
main.cpp
Riad Shash (Ray)
ID: n845y337
Class: CS411
Program #4
 */

#include <iostream>
#include <string>
#include "BST.hpp"              //The BST class
#include "DayOfYear.hpp"        //The DayOfYear class

using std::cout;
using std::endl;
using namespace Tree;

int main()
{
    //Testing BST with int type:
    cout<<endl;
    cout<<"*************************************************************************************\n";
    cout<<"Testing BST with int type: \n";
    cout<<"*************************************************************************************\n";
    cout<<endl;

    cout<<"Using BST's default constructor: \n";
    cout<<"BST<int> intTree; \n"; 
    BST<int> intTree;

    cout<<endl;
    cout<<"intTree.insert(50);\n";  
    cout<<"intTree.insert(30);\n";
    cout<<"intTree.insert(70);\n";  
    cout<<"intTree.insert(40);\n";  
    cout<<"intTree.insert(20);\n";    
    cout<<"intTree.insert(60);\n";  
    cout<<"intTree.insert(80);\n";  
    
    intTree.insert(50);     
    intTree.insert(30);
    intTree.insert(70);
    intTree.insert(40);
    intTree.insert(20);
    intTree.insert(60);
    intTree.insert(80);

    cout<<endl;
    cout<<"Testing tree: (recursive print - no iterator)\n";
    cout<<"Result: \n";

    intTree.printTree();
    cout<<endl;

    cout<<"Removing 50: \n";
    cout<<"intTree.remove(50);\n";
    intTree.remove(50);

    cout<<endl;
    cout<<"Testing tree: (recursive print - no iterator)\n";
    cout<<endl;
    cout<<"Result: \n";

    intTree.printTree();
    cout<<endl;

    
    cout<<"-------------------------IN-ORDER ITERATOR---------------------------\n";
    cout<<"Using iterator on intTree: \n";
    cout<<"for(auto it = intTree.begin(); it != intTree.end(); ++it)\n";
    cout<<endl;
    cout<<"Result: \n";

    //Iterator used in for loop...
    for(auto it = intTree.begin(); it != intTree.end(); ++it)
    {
        cout<<*it <<" ";
    }
    cout<<endl;

    cout<<endl;
    cout<<"Removing 40: \n";
    cout<<"intTree.remove(40);\n";
    intTree.remove(40);

    cout<<endl;
    cout<<"-------------------------IN-ORDER ITERATOR---------------------------\n";
    cout<<"Using iterator on intTree: \n";
    cout<<"for(auto it = intTree.begin(); it != intTree.end(); ++it)\n";
    cout<<endl;
    cout<<"Result: \n";

    //Iterator used in for loop...
    for(auto it = intTree.begin(); it != intTree.end(); ++it)
    {
        cout<<*it <<" ";
    }
    cout<<endl;


    //Testing BST with DayOfYear type:
    cout<<endl;
    cout<<"*************************************************************************************\n";
    cout<<"Testing BST with DayOfYear type: \n";
    cout<<"*************************************************************************************\n";
    cout<<endl;

    cout<<"Using BST's other constructor: \n";
    cout<<"BST<DayOfYear> DayOfYearTree(DayOfYear(1,11)); \n"; 
    BST<DayOfYear> DayOfYearTree(DayOfYear(1,11));

    cout<<endl;
    cout<<"DayOfYearTree.insert(DayOfYear(5,15));\n";
    cout<<"DayOfYearTree.insert(DayOfYear(4,10));\n";
    cout<<"DayOfYearTree.insert(DayOfYear(6,25));\n";
    cout<<"DayOfYearTree.insert(DayOfYear(3,3));\n";
    cout<<"DayOfYearTree.insert(DayOfYear(11,25));\n";

    DayOfYearTree.insert(DayOfYear(5,15));
    DayOfYearTree.insert(DayOfYear(4,10));
    DayOfYearTree.insert(DayOfYear(6,25));
    DayOfYearTree.insert(DayOfYear(3,3));
    DayOfYearTree.insert(DayOfYear(11,25));

    cout<<endl;
    cout<<"Testing tree: (recursive print - no iterator)\n";

    cout<<endl;
    cout<<"Result: \n";

    DayOfYearTree.printTree();
    cout<<endl;

    cout<<"Removing April 10: \n";
    cout<<"DayOfYearTree.remove(DayOfYear(4,10));\n";
    DayOfYearTree.remove(DayOfYear(4,10));

    cout<<endl;
    cout<<"Testing tree: (recursive print - no iterator)\n";

    cout<<endl;
    cout<<"Result: \n";
    
    DayOfYearTree.printTree();
    cout<<endl;

    //Iterator used in for loop...
    cout<<"-------------------------IN-ORDER ITERATOR---------------------------\n";
    cout<<"Using iterator on DayOfYearTree: \n";
    cout<<"for(auto it = DayOfYearTree.begin(); it != DayOfYearTree.end(); ++it)\n";
    cout<<endl;
    cout<<"Result: \n";

    for(auto it = DayOfYearTree.begin(); it != DayOfYearTree.end(); ++it)
    {
        cout<<*it <<" ";
    }
    cout<<endl;

    cout<<endl;
    cout<<"*************************************************************************************\n";
    cout<<"END OF BST TEST \n";
    cout<<"*************************************************************************************\n";
    cout<<endl;
    return 0;
}
