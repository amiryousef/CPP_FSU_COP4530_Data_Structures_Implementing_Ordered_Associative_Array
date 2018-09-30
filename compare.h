/*
    compare.h
    
    Defining and implementing the predicate classes
    LessThan<T> and GreaterThan<T>
    
*/

#ifndef _COMPARE_H
#define _COMPARE_H

namespace fsu
{

template < typename T >
class LessThan;

template < typename T >
class GreaterThan;

template < typename T >
class LessThan
{
  public:
    int operator () (const T& t1, const T& t2) const
    {
      return (t1 < t2);
    }
} ;

template < typename T >
class GreaterThan
{
  public:
    int operator () (const T& t1, const T& t2) const
    {
      return (t2 < t1);
    }
} ;

// technicality needed for generic algorithms: because these predicate objects
// are stateless, they are all equal

template < typename T >
int operator == ( const LessThan<T>& , const LessThan<T>& )
{ return 1; }

template < typename T >
int operator != ( const LessThan<T>& , const LessThan<T>& )
{ return 0; }

template < typename T >
int operator == ( const GreaterThan<T>& , const GreaterThan<T>& )
{ return 1; }

template < typename T >
int operator != ( const GreaterThan<T>& , const GreaterThan<T>& )
{ return 0; }

} // namespace fsu
#endif

