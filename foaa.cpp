/*
    foaa.cpp
*/

#include <oaa.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

// <String, int>
#include <xstring.h>
// #include <xstring.cpp>  // in lieu of makefile
typedef fsu::String KeyType;
typedef int         DataType;
const char fill = '-';
// */

template < typename T >
int CorrectColumnWidth(const T& t, int cw)
{
  int digits = 1+(size_t)log10(t);
  if (cw <= digits)
    cw = 1 + digits;
  return cw;
}
template <>
int CorrectColumnWidth(const fsu::String& t, int cw)
{
  int digits = t.Size();
  if (cw <= digits)
    cw = 1 + digits;
  return cw;
}

void DisplayMenu(std::ostream& os = std::cout);

/* // copy test
template < class C >
void CopyTest ( const C& x1,  C x2 )
{
  size_t size1, size2,
    height1, height2;
  bool ok = 1;
  if (x1 != x2)
  {
    std::cout << " ** CopyTest: original and copy not equal\n";
    ok = 0;
  }
  if (!x2.CheckRBLLT(0))
  {
    std::cout << " ** CopyTest: copy.CheckRBLLT() failed\n";
    ok = 0;
  }
  size1   = x1.Size();
  height1 = x1.Height();
  size2   = x2.Size();
  height2 = x2.Height();
  if (size1  != size2)
  {
    std::cout << " ** CopyTest: original and copy have different size\n";
    ok = 0;
  }
  if (height1 != height2)
  {
    std::cout << " ** CopyTest: original and copy have different height\n";
    ok = 0;
  }
  if (ok) std::cout << " CopyTest OK\n";
} // CopyTest */

		       /* // assign test
template < class C >
void AssignTest ( const C& x1 )
{
  C x2;
  size_t size1, size2,
    height1, height2;
  bool ok = 1;
  size2 = x2.Size();
  x2 = x1;
  if (x1 != x2)
  {
    std::cout << " ** AssignTest: original and copy not equal\n";
    ok = 0;
  }
  if (!x2.CheckRBLLT(0))
  {
    std::cout << " ** AssignTest: assignee.CheckRBLLT() failed\n";
    ok = 0;
  }
  size1   = x1.Size();
  height1 = x1.Height();
  size2   = x2.Size();
  height2 = x2.Height();
  if (size1  != size2)
  {
    std::cout << " ** AssignTest: original and copy have different size\n";
    ok = 0;
  }
  if (height1  != height2)
  {
    std::cout << " ** AssignTest: original and copy have different height\n";
    ok = 0;
  }
  if (ok) std::cout << " AssignTest OK\n";
} // AssignTest */

int main(int argc, char* argv[])
{
  fsu::OAA<KeyType, DataType> aa;
  KeyType     key;
  DataType    data;
  char        command;
  size_t      size, nsize, digits, ndigits;
  int cw1 = 3, cw2 = 3;
  std::ifstream ifs;
  std::istream * inptr = &std::cin;
  bool BATCH = 0;
  if (argc > 1)
  {
    BATCH = 1;
    ifs.open(argv[1]);
    if (ifs.fail()) return 0;
    inptr = &ifs;
  }
  if (!BATCH) DisplayMenu();
  do
  {
    std::cout << "command ('M' for menu, 'Q' to quit): ";
    *inptr >> command;
    if (BATCH) std::cout << command;
    switch(command)
    {
    case '[':
      *inptr >> key;
      if (BATCH) std::cout << key;
      *inptr >> command;
      if (BATCH) std::cout << command;
      if (command != ']')
      {
	std::cout << " ** close bracket expected - re-enter command\n";
	inptr->clear();
	while (command != '\n') command = inptr->get();
	inptr->clear();
	break;
      }
      command = inptr->peek();
      if (command == '\n')
      {
	if (BATCH) std::cout << '\n';
	std::cout << "  " << aa[key]
		  << " = aa[" << key << "]\n";
	size = key.Size();
	if (cw1 <= (int)size) cw1 = 1 + size;
	break;
      }
      *inptr >> command; // assume '='
      *inptr >> data;
      if (BATCH) std::cout << command << data << '\n';
      std::cout << "aa[" << key << "] = " << data << '\n';
      aa[key] = data;
      cw1 = CorrectColumnWidth(key,cw1);
      cw2 = CorrectColumnWidth(data,cw2);
      break;

    case '1':
      *inptr >> key >> data;
      if (inptr->fail())
      {
	std::cout << " ** bad key or data encountered - re-enter command\n";
	inptr->clear();
	while (command != '\n') command = inptr->get();
	inptr->clear();
	break;
      }
      if (BATCH) std::cout << ' ' << key << ' ' << data << '\n';
      std::cout << "aa.Put(" << key << ',' << data << ")\n";
      aa.Put(key,data);
      cw1 = CorrectColumnWidth(key,cw1);
      cw2 = CorrectColumnWidth(data,cw2);
      break;
    case '2':
      *inptr >> key;
      if (inptr->fail())
      {
	std::cout << " ** bad key encountered - re-enter command\n";
	inptr->clear();
	while (command != '\n') command = inptr->get();
	inptr->clear();
	break;
      }
      if (BATCH) std::cout << ' ' << key << '\n';
      std::cout << "  " << aa.Get(key)
		<< " = aa.Get(" << key << ")\n";
      cw1 = CorrectColumnWidth(key,cw1);
      break;
    case 'd': case 'D':
      *inptr >> command;
      if (BATCH) std::cout << command << '\n';
      switch (command)
      {
      case '1': aa.Dump(std::cout); break;
      case '2': aa.Dump(std::cout,cw1); break;
      case '3': aa.Dump(std::cout,cw1,fill); break;
      default: std::cout << " ** undefined command (level 2)\n";
      }
      break;
    case 's': case 'S':
      if (BATCH) std::cout << '\n';
      size = aa.Size();
      std::cout << "  aa.Size()           = " << size << '\n'
                << "  aa.Height()         = " << aa.Height() << '\n'
		<< "  optimal ht (size)   = " << (size_t)(floor(log2(size))) << '\n';
      break;
    case 'c': case 'C':
      if (BATCH) std::cout << '\n';
      aa.Clear();
      break;
    case 't':  case 'T':
      if (BATCH) std::cout << '\n';
      std::cout << std::setw (2 + cw1) << "key" << std::setw(2+cw2) << "data" << '\n';
      std::cout << std::setw (2 + cw1) << "---" << std::setw(2+cw2) << "----" << '\n';
      aa.Display(std::cout,2 + cw1,2 + cw2);
      std::cout << '\n';
      break;
    case 'x': case 'X':
      if (BATCH)
      {
	std::cout << '\n';
	ifs.close();
	inptr = &std::cin;
	std::cout << "   ** switched to keyboard input **\n";
	BATCH = 0;
	DisplayMenu();
      }
      else
      {
	std::cout << "  ** already using keyboard input\n";
      }
      break;
    case '=':
      if (BATCH) std::cout << '\n';
      // CopyTest(aa, aa);
      // AssignTest(aa);
      std::cout << " ** copy and assign tests not implemented\n";
      break;
    case 'l': case 'L':
      *inptr >> key;
      ifs.open(key.Cstr());
      if (ifs.fail())
      {
	std::cout << "  ** Unable to open file " << key << '\n';
	ifs.clear();
	break;
      }
      size = 0;
      digits = 0;
      while (ifs >> key >> data)
      {
	aa[key] = data;

	nsize = key.Size();
	ndigits = 1 + (size_t)log10(data);
	if (size < nsize) size = nsize;
	if (digits < ndigits) digits = ndigits;
      }
      if (cw1 <= (int)size)   cw1 = 1 + size;
      if (cw2 <= (int)digits) cw2 = 1 + digits;
      ifs.clear();
      ifs.close();
      std::cout << "  ** table data read and stored\n";
      break;
    case 'm': case 'M':
      if (BATCH) std::cout << '\n';
      DisplayMenu();
      break;
    case 'q': case 'Q':
      if (BATCH)
      {
	std::cout << '\n';
	ifs.close();
      }
      command = 'q';
      break;
    default:
      if (BATCH) std::cout << '\n';
      std::cout << " ** undefined command (level 1)\n";
      // while (command != '\n')
      //   command = *inptr.get(); 
    }
  }
  while (command != 'q');
}

void DisplayMenu(std::ostream& os)
{
  os << "   OPERATION                ENTRY\n"
     << "   ---------                -----\n"
     << "   Load data from file  .......... L filename\n"
     << "   x.Put(key,data)  .............. 1 key data\n"
     << "   x.Get(key) .................... 2 key\n"
     << "   aa[key] = data  ............... [ key ] = data\n"
     << "   data = aa[key]  ............... [ key ]\n"
     << "   x.Clear() ..................... C\n"
     << "   x.Dump(cout) .................. D1\n"
     << "   x.Dump(cout,ofc) .............. D2\n"
     << "   x.Dump(cout,ofc,fill) ......... D3\n"
     << "   traversal  .................... T\n"
    // << "   Copy/Assign test .............. =\n"
     << "   switch from batch mode ........ X\n"
     << "   quit program .................. Q\n";
}
