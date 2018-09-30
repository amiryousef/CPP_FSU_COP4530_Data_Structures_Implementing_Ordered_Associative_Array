/*  xranxstr.cpp
    Implementation of the class random_String.
*/

#ifndef _XRANXSTR_CCP
#define _XRANXSTR_CCP

#include <xranxstr.h>
#include <xran.h>

namespace fsu
{

  Random_String::Random_String()  :  fsu::Random_cstring()
  {}

  String Random_String::Get(int n)
  // returns random String object of size n (default size in header file)
  {
    String S;
    char* str = Random_cstring::Get(n);
    S.Wrap(str);
    delete [] str;
    return S;
  }

} // namespace fsu
#endif
