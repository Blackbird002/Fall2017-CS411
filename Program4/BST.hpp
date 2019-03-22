/*******************************************************************************
    BST.hpp
    Riad Shash (Ray)
    ID: n845y337
    Class: CS411
    Program #4

	In this assignment (HW#4 - extra credit), we created a templated Binary
	Search Tree that also includes an iterator (in-order).

	I only did the in-order iterator.

 ******************************************************************************/
#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using std::cout;
using std::endl;

namespace Tree{
	template<class T>
	class BST {
	public:
		//Default constructor
		BST();

		//constructor with 1 parameter for root key
		BST(T inputObj);

		//destructor
		~BST();

		//function named insert with 1 parameter (key value to insert)
		void insert(T inputObj);

		//Prints the BST in preorder, inorder and postorder form
		const void printTree();

		//function named remove with 1 parameter (key value to remove)
		void remove(T inputObj);

		// Declaration of the iterator class
		class iterator
		{
			public:
				//Default constructor
				iterator(typename BST<T>::Node *s);

				//Overloaded ++ operator
				iterator& operator++();

				//Overloaded * operator
				const T operator*();

				//Overloaded == operator
				const bool operator ==(const iterator& r);

				//Overloaded != operator
				const bool operator !=(const iterator& r);

			private:
				typename BST<T>::Node *curr;
		};

		// Public section of BST class continues

		// Marks the start iterator
		iterator begin();

		// Marks the end iterator
		iterator end();


	private:
		class Node {
		public:
			//default constructor
			Node();

			//constructor with 1 parameter (key value)
			Node(T inputObj);

			//destructor (not needed)
			~Node();

			//parent accessor
			Node* getParentNode();

			//left accessor
			Node* getLeftNode();

			//right accessor
			Node* getRightNode();

			//Gets the Node's key value
			const T getKey() const;

			//parent mutator
			void changeParentNode(Node *NodePtr);

			//left mutator
			void changeLeftNode(Node *NodePtr);

			//right mutator
			void changeRightNode(Node *NodePtr);

			//operator <
			const bool operator <(const Node& secondObj) const;

			//operator >
			const bool operator >(const Node& secondObj) const;

			//operator ==
			const bool operator ==(const Node& secondObj) const;

			//operator !=
			const bool operator !=(const Node& secondObj) const;

		// Private section of Node class
		private:
			// The object in the node (int, class...)
			T key;

			Node *parent;
			Node *left;
			Node *right;
		};

		// Private section of BST class--
		Node *root;

		// Used by the iterator class
		Node* startNode;
		Node* endNode;

		// Searches the BST and returns a pointer to the found node
		Node* search(Node *nodePtr,T delKey);

		// Find the smallest node given a node pointer
		static Node* findSmallestNode(Node *nodePtr);

		// Find the largest node given a node pointer
		Node* findLargestNode(Node *nodePtr);

		// Removes the node from the BST
		Node* remove(Node *nodePtr);

		// De-allocates memory of passed in Node pointer
		void destroy(Node* nodePtr);

		//Prints the tree in Inorder form
		const void printInorder(typename BST<T>::Node *nodePtr);

		//Prints the tree in Postorder
		const void printPostorder(typename BST<T>::Node *nodePtr);

		//Prints the tree in Preorder form
		const void printPreorder(typename BST<T>::Node *nodePtr);

		//Deletes the tree in post order
		void deleteWholeTree(typename BST<T>::Node *nodePtr);
	};

	/* For separate header and source file source code
	Template classes & functions declarations and implementations
	should be in the "same file". BST.inl allows us to separate
	these two.
	*/
	#include "BST.inl"
};


#endif
