#include <iostream>
#include "BST.h"

using namespace std;

// enum of possible commands
enum cmd {CMD_ADD, CMD_DELETE, CMD_FIND, CMD_PRINT, CMD_EXIT, CMD_UNKNOWN};

// determines, which command was entered
cmd GetCommand(const char* strCommand)
{
	if (strcmp(strCommand, "add") == 0)
	{
		return CMD_ADD;
	}
	if (strcmp(strCommand, "delete") == 0)
	{
		return CMD_DELETE;
	}
	if (strcmp(strCommand, "find") == 0)
	{
		return CMD_FIND;
	}
	if (strcmp(strCommand, "print") == 0)
	{
		return CMD_PRINT;
	}
	if (strcmp(strCommand, "bye") == 0)
	{
		return CMD_EXIT;
	}
	return CMD_UNKNOWN;
}

// read integer value
// with appropriate error checking
int DoRead()
{
	int value;
	cout << "Enter integer value: ";
	while (true) 
	{ 
		cin >> value;
		if (cin.good())
		{
			cin.ignore(256, '\n');
			break;
		} else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Wrong input, try again: ";
		}
	}
	return value;
}

// handles "Add" command
void DoAdd(BinarySearchTree *tree)
{
	int value;
	value = DoRead();
	if (tree->Add(value))
	{
		cout << "Element " << value << " has been added" << endl;
	} else
	{
		cout << "Element " << value << " already exists in the tree" << endl;
	}
}

// handles "Delete" command
void DoDelete(BinarySearchTree *tree)
{
	int value;
	value = DoRead();
	if (tree->Delete(value))
	{
		cout << "Element " << value << " has been deleted" << endl;
	} else
	{
		cout << "Element " << value << " doesn't exist in the tree" << endl;
	}
}

// handles "Find" command
void DoFind(BinarySearchTree *tree)
{
	int value;
	value = DoRead();
	if (tree->Find(value))
	{
		cout << "Element " << value << " has been found" << endl;
	} else
	{
		cout << "Element " << value << " doesn't exist in the tree" << endl;
	}
}

// handles "Print" command
void DoPrint(BinarySearchTree *tree)
{
	if (!tree->Print()) cout << "Tree is empty";
	cout << endl;
}

int main()
{
	char strCommand[256];
	cmd command;
	BinarySearchTree *tree = new BinarySearchTree();
	do
	{
		cout << "Enter command (""add"", ""delete"", ""find"", ""print"", ""bye""): ";
		cin >> strCommand;
		command = GetCommand(strCommand);
		if (command == CMD_EXIT) break;
		switch (command)
		{
		case CMD_ADD:
			DoAdd(tree);
			break;
		case CMD_DELETE:
			DoDelete(tree);
			break;
		case CMD_FIND:
			DoFind(tree);
			break;
		case CMD_PRINT:
			DoPrint(tree);
			break;
		default: cout << "Unknown command" << endl;
		}
	} while (command != CMD_EXIT);
	return 0;
}