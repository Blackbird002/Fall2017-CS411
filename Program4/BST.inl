/*
BST.inl
Riad Shash (Ray)
ID: n845y337
Class: CS411
Program #4
 */

// Class Node*******************************************************************

//Default Constructor
template <class T>
BST<T>::Node::Node()
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;

    // Calls the constructor for the class T
    key = T();
}

/*
Destructor (does nothing and should do nothing) do to the way I
implemented the removal of nodes.
*/
template <class T>
BST<T>::Node::~Node()
{
}

//Node key accessor
template <class T>
const T BST<T>::Node::getKey() const
{
    return key;
}

template <class T>
BST<T>::Node::Node(T inputObj)
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;

    key = inputObj;
}

//Parent Node accessor
template <class T>
typename BST<T>::Node* BST<T>::Node::getParentNode()
{
    return parent;
}

//Left Node accessor
template <class T>
typename BST<T>::Node* BST<T>::Node::getLeftNode()
{
    return left;
}

//Right Node accessor
template <class T>
typename BST<T>::Node* BST<T>::Node::getRightNode()
{
    if (right != nullptr)
        return right;
    else
        return nullptr;
}

//Parent Node mutator
template <class T>
void BST<T>::Node::changeParentNode(Node *NodePtr)
{
    parent = NodePtr;
}

//Left Node mutator
template <class T>
void BST<T>::Node::changeLeftNode(Node *NodePtr)
{
    left = NodePtr;
}

//Right Node mutator
template <class T>
void BST<T>::Node::changeRightNode(Node *NodePtr)
{
    right = NodePtr;
}

// Assumes that this node is isolated and removed.
template <class T>
void BST<T>::destroy(Node *nodePtr)
{
    if(nodePtr != nullptr)
        delete nodePtr;
}

// Class BST-----------------------------------------------------------
template <class T>
BST<T>::BST()
{
    root = nullptr;
    startNode = nullptr;
    endNode = nullptr;
}

//Prints the BST in preorder, inorder and postorder form
template <class T>
const void BST<T>::printTree()
{
    cout<<"Preorder: \n";
    printPreorder(root);

    cout<<endl;

    cout<<"Inorder: \n";
    printInorder(root);

    cout<<endl;

    cout<<"Postorder: \n";
    printPostorder(root);

    cout<<endl;
}

//BST destructor
template <class T>
BST<T>::~BST()
{
    //Calls the recursive deleteWholeTree that frees up memory
    deleteWholeTree(root);
}

//Deletes the entire tree in post order form
template <class T>
void BST<T>::deleteWholeTree(typename BST<T>::Node *nodePtr)
{
    //Base case
    if (nodePtr == nullptr)
        return;
 
    //first delete both subtrees
    deleteWholeTree(nodePtr->getLeftNode());
    deleteWholeTree(nodePtr->getRightNode());
   
    //then delete the node 
    delete nodePtr;
}

//BST Constructor 
template <class T>
BST<T>::BST(T inputObj)
{
    root = new Node(inputObj);
    startNode = nullptr;
    endNode = nullptr;
}

// Marks the start iterator
template <class T>
typename BST<T>::iterator BST<T>::begin()
{
    if((startNode == nullptr) || (endNode == nullptr))
    {
        if(root != nullptr)
        {
            startNode = findSmallestNode(root);
            endNode = findLargestNode(root);
            endNode = endNode->getRightNode();
        }
        else
        {
            startNode = nullptr;
            endNode = nullptr;
        }
    }
    return BST<T>::iterator(startNode);
}

// Marks the end iterator
template <class T>
typename BST<T>::iterator BST<T>::end()
{
    if((startNode == nullptr) || (endNode == nullptr))
    {
        if(root != nullptr)
        {
            startNode = findSmallestNode(root);
            endNode = findLargestNode(root);
            endNode = endNode->getRightNode();
        }
        else
        {
            startNode = nullptr;
            endNode = nullptr;
        }
    }
    return BST<T>::iterator(endNode);
}

template <class T>
void BST<T>::insert(T inputObj)
{
    //Creates a node using the given input key
    Node* newNode = new Node(inputObj);

    //If the root is empty..
    if (root == nullptr)
        root = newNode;
    else
    {
        //Bool is true is there is a found free spot
        bool freeSpotFound = false;
        Node *NodePtr = root;
        while(freeSpotFound == false)
        {
            if(*newNode < *NodePtr)
            {
                if(NodePtr->getLeftNode() != nullptr)
                {
                    NodePtr = NodePtr->getLeftNode();
                    continue;
                }
                else
                {
                    freeSpotFound = true;
                    NodePtr->changeLeftNode(newNode);
                    newNode->changeParentNode(NodePtr);

                }
            }
            else
            {
                if(NodePtr->getRightNode() != nullptr)
                {
                    NodePtr = NodePtr->getRightNode();
                    continue;
                }
                else
                {
                    freeSpotFound = true;
                    NodePtr->changeRightNode(newNode);
                    newNode->changeParentNode(NodePtr);
                }
            }
        }
    }
    newNode = nullptr;
}

//Only used for testing, prints the tree in in-order form
template <class T>
const void BST<T>::printInorder(Node *nodePtr)
{
    //Base Case
    if(nodePtr == nullptr)
    {
        return;
    }
    else
    {
        printInorder(nodePtr->getLeftNode());
        cout<<nodePtr->getKey() <<" ";
        printInorder(nodePtr->getRightNode());
    }
}

//Only used for testing, prints the tree in post-order form
template <class T>
const void BST<T>::printPostorder(Node *nodePtr)
{
    //Base Case
    if(nodePtr == nullptr)
    {
        return;
    }
    else
    {
        printPostorder(nodePtr->getLeftNode());
        printPostorder(nodePtr->getRightNode());
        cout<<nodePtr->getKey() <<" ";
    }
}

//Only used for testing, prints the tree in pre-order form
template <class T>
const void BST<T>::printPreorder(Node *nodePtr)
{
    //Base Case
    if(nodePtr == nullptr)
    {
        return;
    }
    else
    {
        cout<<nodePtr->getKey() <<" ";
        printPreorder(nodePtr->getLeftNode());
        printPreorder(nodePtr->getRightNode());
    }
}

//This is the public method that users have access to
template <class T>
void BST<T>::remove(T delKey)
{
    // Sets the pointer to the node we want to delete
    Node *nodeDelete = search(root, delKey);

    Node *removedNode = remove(nodeDelete);

    //Node gets deleted here:
    delete removedNode;
}

//This is the private version of remove that returns the node to be removed
template <class T>
typename BST<T>::Node* BST<T>::remove(Node *nodeDelete)
{
    // Base Case#1 - No children
    if(nodeDelete->getLeftNode() == nullptr && nodeDelete->getRightNode() == nullptr)
    {
        // If it is the root node
        if(nodeDelete->getParentNode() == nullptr)
        {
            //Sets the root to nullptr
            root = nullptr;
        }
        // If it is a leaf node
        else
        {
            // Sets the parent node pointers to nodeDelete to nullptr
            if(nodeDelete->getParentNode()->getLeftNode() == nodeDelete)
                nodeDelete->getParentNode()->changeLeftNode(nullptr);
            else
                nodeDelete->getParentNode()->changeRightNode(nullptr);

        }
    }
    // Base Case#2 - Left or Right children
    //If there is a child node on the left of nodeDelete
    else if(nodeDelete->getLeftNode() != nullptr && nodeDelete->getRightNode() == nullptr)
    {
        // If nodeDelete is a root node
        if(nodeDelete->getParentNode() == nullptr)
        {
            root = nodeDelete->getLeftNode();
        }
        else
        {
            // If nodeDelete is not a root node
            if(nodeDelete->getParentNode()->getLeftNode() == nodeDelete)
                nodeDelete->getParentNode()->changeLeftNode(nodeDelete->getLeftNode());
            else
                nodeDelete->getParentNode()->changeRightNode(nodeDelete->getLeftNode());
        }
        nodeDelete->getLeftNode()->changeParentNode(nodeDelete->getParentNode());
    }
    //If there is a child node on the Right of nodeDelete (recursive)
    else if(nodeDelete->getLeftNode() == nullptr && nodeDelete->getRightNode() != nullptr)
    {
        // If nodeDelete is a root node
        if(nodeDelete->getParentNode() == nullptr)
        {
            root = nodeDelete->getRightNode();
        }
        else
        {
            if(nodeDelete->getParentNode()->getRightNode() == nodeDelete)
                nodeDelete->getParentNode()->changeRightNode(nodeDelete->getRightNode());
            else
                nodeDelete->getParentNode()->changeLeftNode(nodeDelete->getRightNode());
        }

        nodeDelete->getRightNode()->changeParentNode(nodeDelete->getParentNode());
    }

    // Case #3 - children on the left and the right!
    else if ((nodeDelete->getLeftNode() != nullptr) && (nodeDelete->getRightNode() != nullptr) && (root != nodeDelete))
    {
        // Finds the least extrema
        Node *replaceNode = findSmallestNode(nodeDelete->getRightNode());

        // Recursive call
        remove(replaceNode);

        // Sets parentNode to the parent Node of nodeDelete
        Node *parentNode = nodeDelete->getParentNode();

        // Sets all the branches on the replaceNode to nullptr
        replaceNode->changeParentNode(nullptr);
        replaceNode->changeLeftNode(nullptr);
        replaceNode->changeRightNode(nullptr);

        // Sets the branches for the parent of nodeDelete
        // If nodeDelete is located on the left:
        if(parentNode->getLeftNode() == nodeDelete)
            parentNode->changeLeftNode(replaceNode);
        else
            parentNode->changeRightNode(replaceNode);

        // Sets the branches for replaceNode to the parent node
        replaceNode->changeParentNode(parentNode);

        // Sets the children of nodeDelete to replaceNode
        replaceNode->changeLeftNode(nodeDelete->getLeftNode());
        replaceNode->changeRightNode(nodeDelete->getRightNode());

        // Sets the parents
        if(nodeDelete->getLeftNode() != nullptr)
            nodeDelete->getLeftNode()->changeParentNode(replaceNode);

        if(nodeDelete->getRightNode() != nullptr)
            nodeDelete->getRightNode()->changeParentNode(replaceNode);
    }
    // If we want to delete the root of the whole BST
    else if ((nodeDelete->getLeftNode() != nullptr) && (nodeDelete->getRightNode() != nullptr) && (root == nodeDelete))
    {
        // Finds the least extrema
        Node *replaceNode = findSmallestNode(nodeDelete->getRightNode());

         // Recursive call
        remove(replaceNode);

        // Sets all the branches on the replaceNode to nullptr
        replaceNode->changeParentNode(nullptr);
        
        replaceNode->changeLeftNode(nodeDelete->getLeftNode());

        replaceNode->changeRightNode(nodeDelete->getRightNode());

        //Sets the left child's parent of nodeDelete(former root) to replaceNode
        if(replaceNode->getLeftNode() != nullptr)
            replaceNode->getLeftNode()->changeParentNode(replaceNode);

         //Sets the right child's parent of nodeDelete(former root) to replaceNode
        if(replaceNode->getRightNode() != nullptr)
            replaceNode->getRightNode()->changeParentNode(replaceNode);

        // The tree has a new root
        root = replaceNode;
    }

    nodeDelete->changeParentNode(nullptr);
    nodeDelete->changeLeftNode(nullptr);
    nodeDelete->changeRightNode(nullptr);

    return nodeDelete;

}

// Assumes that the node to be found exists
template <class T>
typename BST<T>::Node* BST<T>::search(Node *nodePtr,T delKey)
{
    if(delKey < nodePtr->getKey())
    {
        return search(nodePtr->getLeftNode(), delKey);
    }
    else if(delKey > nodePtr->getKey())
    {
        return search(nodePtr->getRightNode(), delKey);
    }
    else
    {
        // The specific node was found!
        return nodePtr;
    }
}

// Returns a pointer to the smallest node
template <class T>
typename BST<T>::Node* BST<T>::findSmallestNode(Node *nodePtr)
{
    Node *current = nodePtr;

    while(current->getLeftNode() != nullptr)
    {
        current = current->getLeftNode();
    }

    return current;
}

// Returns a pointer to the largest node
template <class T>
typename BST<T>::Node* BST<T>::findLargestNode(Node *nodePtr)
{
    Node *current = nodePtr;

    while(current->getRightNode() != nullptr)
    {
        current = current->getRightNode();
    }

    return current;
}

// Overloaded < operator
template <class T>
const bool BST<T>::Node::operator <(const Node& secondObj) const
{
    if(key < secondObj.key)
    {
        return true;
    }
    else
        return false;
}

// Overloaded > operator
template <class T>
const bool BST<T>::Node::operator >(const Node& secondObj) const
{
    if(key > secondObj.key)
    {
        return true;
    }
    else
        return false;
}

// Overloaded == operator
template <class T>
const bool BST<T>::Node::operator ==(const Node& secondObj) const
{
    if(key == secondObj.key)
    {
        return true;
    }
    else
        return false;
}

// Overloaded != operator
template <class T>
const bool BST<T>::Node::operator !=(const Node& secondObj) const
{
    if(key != secondObj.key)
    {
        return true;
    }
    else
        return false;
}

// Class Iterator-----------------------------------------------------------

//Constructor
template <class T>
BST<T>::iterator::iterator(Node *s)
{
    curr = s;
}

//Overloaded == operator
template <class T>
const bool BST<T>::iterator::operator ==(const iterator& r)
{
    return curr == r.curr;
}

//Overloaded != operator
template <class T>
const bool BST<T>::iterator::operator !=(const iterator& r)
{
    return curr != r.curr;
}

//Overloaded * operator
template <class T>
const T BST<T>::iterator::operator *()
{
    return curr->getKey();
}

//Overloaded ++ operator (heart of the iterator)
/*
    If the current node has a right child
        Takes a step down right
        Runs down to the left of tree as far as possible
    If the current node has no right child
        Moves up the tree until it moved over a left child link
*/
template <class T>
typename BST<T>::iterator& BST<T>::iterator::operator++()
{
    Node* p = nullptr;

    // If there is a child on the right
    if(curr->getRightNode() != nullptr)
    {
        curr = curr->getRightNode();
        curr = findSmallestNode(curr);
    }
    else
    {
        p = curr->getParentNode();

        while((p != nullptr) && (curr == p->getRightNode()))
        {
            curr = p;
            p = p->getParentNode();
        }

        curr = p;
    }

    return *this;
}