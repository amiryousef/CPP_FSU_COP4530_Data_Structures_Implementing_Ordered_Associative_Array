#include <iostream>
#include "BST.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

bool BinarySearchTree::Add(int value)
{
	if (root == NULL)
	{
		root = new Element(value);
		return true;
	} else
	{
		return AuxAdd(root, new Element(value));
	}
}

bool BinarySearchTree::Print()
{
	if (root == NULL)
	{
		return false;
	} else
	{
		AuxPrint(root);
	}
}

bool BinarySearchTree::Find(int value)
{
	if (root == NULL)
	{
		return false;
	} else
	{
		return AuxFind(root, value);
	}
}

bool BinarySearchTree::Delete(int value)
{
	if (root == NULL)
	{
		return false;
	} else
	{
		return AuxDelete(root, NULL, value, true);
	}
}

bool BinarySearchTree::AuxAdd(Element *elem, Element *add_elem)
{
	if (add_elem->value == elem->value)
	{
		return false;
	}
	if (add_elem->value < elem->value)
	{
		if (elem->left == NULL)
		{
			elem->left = add_elem;
			return true;
		} else
		{
			return AuxAdd(elem->left, add_elem);
		}
	}
	if (add_elem->value > elem->value)
	{
		if (elem->right == NULL)
		{
			elem->right = add_elem;
			return true;
		} else
		{
			return AuxAdd(elem->right, add_elem);
		}
	}
}

void BinarySearchTree::AuxPrint(Element *elem)
{
	if (elem->left != NULL) AuxPrint(elem->left);
	cout << elem->value << " ";
	if (elem->right != NULL) AuxPrint(elem->right);
}

bool BinarySearchTree::AuxFind(Element *elem, int value)
{
	if (value == elem->value)
	{
		return true;
	}
	if (value < elem->value)
	{
		if (!(elem->left == NULL))
		{
			return AuxFind(elem->left, value);
		}
	}
	if (value > elem->value)
	{
		if (!(elem->right == NULL))
		{
			return AuxFind(elem->right, value);
		}
	}
	return false;
}

bool BinarySearchTree::AuxDelete(Element *elem, Element *parent, int value, bool left_right)
{
	if (value == elem->value)
	{
		if (parent == NULL)
		{
			root = elem->right;
			if (elem->left != NULL) AuxAdd(root, elem->left);
		} else
		{
			if (!left_right)
			{
				parent->left = elem->left;
				if (elem->right != NULL) AuxAdd(parent, elem->right);
			} else
			{
				parent->right = elem->right;
				if (elem->left != NULL) AuxAdd(parent, elem->left);
			}
		}
		return true;
	}
	if (value < elem->value)
	{
		if (!(elem->left == NULL))
		{
			return AuxDelete(elem->left, elem, value, false);
		}
	}
	if (value > elem->value)
	{
		if (!(elem->right == NULL))
		{
			return AuxDelete(elem->right, elem, value, true);
		}
	}
	return false;
}