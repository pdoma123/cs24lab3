// intbst.cpp
// Implements class IntBST
// Prabhav Doma 4/25/2025

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
	root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
	IntBST::clear(root);
}

// recurisive helper for destructor
void IntBST::clear(Node *n) {
	if (n == nullptr)
	{
		return;
	}
	clear(n->left);
	clear(n->right);
	delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) 
{
    	if (root == nullptr)
	{
		root = new Node(value);
		return true;	
    	}
	
	Node* current = root;
	while(true)
	{
		if (current->info == value)
		{
			return false;
		}
		if (current->info > value)
		{
			if (current->left == nullptr)
			{
				current->left = new Node;
				current->left->info = value;
				Node* temp = current;
				current = current->left;
				current->parent = temp;
				current->left = nullptr;
				current->right = nullptr;
				return true;
			}
			current = current->left;
		}
		else
                {
                        if (current->right == nullptr)
                        {
                                current->right = new Node;
                                current->right->info = value;
                                Node* temp = current;
                                current = current->right;
                                current->parent = temp;
                                current->left = nullptr;
                                current->right = nullptr;
				return true;
                        }
			current = current->right;
                }
	}	
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    return false; // REPLACE THIS NON-SOLUTION
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
    cout<<endl;
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
	if (n == nullptr)
	{
		return;
	}
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    	printInOrder(root);
    	cout << endl;
}
void IntBST::printInOrder(Node *n) const {
    	if (n == nullptr)
	{
		return;
	}
	printInOrder(n->left);
	cout<< n->info << " ";
	printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
    cout << endl;
}

void IntBST::printPostOrder(Node *n) const {
    	if (n == nullptr)
    	{
	    	return;
    	}
    	printPostOrder(n->left);
    	printPostOrder(n->right);
	cout << n->info << " ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
     	if (n == nullptr)
        {
                return 0;
        }
        return n->info + sum(n->left) + sum(n->right);
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (n == nullptr)
    {
	    return 0;
    }
    return 1 + count(n->left) + count(n->right);
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
	if (n == nullptr)
	{
		return NULL;
	}
	while(n != nullptr)
	{
		if (n->info == value)
		{
			return n;
		}
		if (n->info < value)
		{
			n = n->right;
		}
		else
		{
			n = n->left;
		}
	}
	return nullptr;
	
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    	if (getNodeFor(value, root) != NULL)
    	{
		return true;
	}
	return false;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    	Node* current = getNodeFor(value, root);
    	if (current == nullptr || current == NULL)
    	{
		return nullptr;

	}
	if (current->left == nullptr)
        {
                while (current->parent != nullptr && current->parent->left == current)
                {
                        current = current->parent;
                }
                if (current->parent != nullptr)
                {
                        return current->parent;
                }
                return nullptr;

        }

	current = current->left;
	while (current->right != nullptr)
	{
		current = current->right;
	}
	return current;
}


// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* predecessor = getPredecessorNode(value);
    if (predecessor == nullptr)
    {
	    return 0;
    }
    else
    {
	    return predecessor->info;
    }
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
	Node* current = getNodeFor(value, root);
        if (current == nullptr || current == NULL)
        {
                return nullptr;

        }
        if (current->right == nullptr)
        {
                while (current->parent != nullptr && current->parent->right == current)
		{
			current = current->parent;
		}
		if (current->parent != nullptr)
		{
			return current->parent;
		}
		return nullptr;
		
        }
        current = current->right;
        while (current->left != nullptr)
        {
                current = current->left;
        }
        return current;
}


// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* successor = getSuccessorNode(value);
    if (successor == nullptr)
    {
            return 0;
    }
    else
    {
            return successor->info;
    }
}





// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value)
{
        if (contains(value) == false)
        {
                return false;
        }
        Node* n = getNodeFor(value, root);
        if (n->right == nullptr && n->left == nullptr)
        {
                if (n->parent == nullptr)
                {
                        delete n;
                        root = nullptr;
                        return true;
                }

                Node* parent = n->parent;
                if (parent->left == n)
                {
                        parent->left = nullptr;
                }
                else
                {
                        parent->right = nullptr;
                }
                delete n;
                return true;
        }
        else if (n->right == nullptr)
        {
                Node* temp = n;

                if (n->parent == nullptr)
                {
                        root = n->left;
                }
                else
                {
                        Node* parent = n->parent;
                        if (parent->left == n)
                        {
                                parent->left = n->left;
                                n->left->parent = parent;
                        }
                        else
                        {
                                parent->right = n->left;
                                n->left->parent = parent;
                        }
                }
                delete temp;
                return true;
        }
        else if (n->left == nullptr)
        {
                Node* temp = n;

                if (n->parent == nullptr)
                {
                        root = n->right;
                }
                else
                {
                        Node* parent = n->parent;
                        if (parent->left == n)
                        {
                                parent->left = n->right;
                                n->right->parent = parent;
                        }
                        else
                        {
                                parent->right = n->right;
                                n->right->parent = parent;
                        }
                }
                delete temp;
                return true;
        }
        else
        {
                //Node* tempA = n->left;
                //Node* tempB = n;
		
		Node* successor = n->right;
		while (successor->left != nullptr)
		{
			successor = successor->left;
		}

		n->info = successor->info;

		if (successor->parent->left == successor)
		{
			successor->parent->left = successor->right;
		}
		else
		{
			successor->parent->right = successor->right;
		}

		if (successor->right)
		{
			successor->right->parent = successor->parent;
		}

		delete successor;
	}

	return true;
       
}
