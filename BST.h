#include "Element.h"

// BST (Binary Search Tree)
class BinarySearchTree{
	// root element
	Element *root;

	// recursive function
	// adds new element to a particular subtree
	// return false if element with the same value
	// already exists in a specified subtree
	bool AuxAdd(Element *elem, Element *add_elem);

	// recursive function
	// looks for value in a particular subtree
	// return false if element doesn't exist
	// true otherwise 
	bool AuxFind(Element *elem, int value);

	// recursive function
	// deletes value in a particular subtree
	// return false if element doesn't exist
	// true otherwise
	// require pointer to parent element and knowledge,
	// is it right or left child of it's parent
	bool AuxDelete(Element *elem, Element* parent, int value, bool left_right);

	// recursive function
	// prints particular subtree
	void AuxPrint(Element *elem);
public:
	// constructs empty BST
	BinarySearchTree();

	// adds value to the tree
	// return true if element added
	// false, if element already exists in the tree
	bool Add(int value);

	// deletes value from the tree
	// return true if element deleted
	// false, if element doesn't exists in the tree
	bool Delete(int value);

	// looks for value in the tree
	// return true if element found
	// false, if element doesn't exist in the tree
	bool Find(int value);

	// prints tree values in ascending order (LUR traversing)
	bool Print();
};