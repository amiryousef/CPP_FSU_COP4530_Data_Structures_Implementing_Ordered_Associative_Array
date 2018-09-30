// Element of a binary tree
class Element{
public:
	// value
	int value;

	// pointers to two children
	// can be NULL if one or both of the children
	// don't exist
	Element *left, *right;

	// constructs element without children
	// storing specified value
	Element(int _value);
};
