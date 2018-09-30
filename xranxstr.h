/*  xranxstr.h
    
    Definition of the class random_String.

*/

#ifndef _XRANXSTR_H
#define _XRANXSTR_H

#include <xran.h>
#include <xstring.h>

namespace fsu
{

  class Random_String  :  private Random_cstring
  {
  public:
    Random_String();
    String Get (int n = 10);
    // returns random String object of size n
    String operator () (int n = 10) { return Get(n); }
  }  ;

}   // namespace fsu
#endif

