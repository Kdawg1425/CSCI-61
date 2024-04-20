#ifndef MAIN_SAVITCH_set_H
#define MAIN_SAVITCH_set_H
#include <cstdlib> // Provides size_t and NULL
#include "node1.h" // Provides node class

namespace main_savitch_5
{
//template<class T>
class set
{
public:
// TYPEDEFS
typedef std::size_t size_type;
typedef node::value_type value_type;
// CONSTRUCTORS and DESTRUCTOR
set( );
set(const set& source);
~set( );
// MODIFICATION MEMBER FUNCTIONS
bool erase(const T& target);

bool insert(const T& entry);
set intersect(const set<T>& set2);
void operator +=(const set<T>& addend);
void operator -=(const set<T>& set2);
void operator =(const set<T>& source);
// CONSTANT MEMBER FUNCTIONS
size_type size( ) const { return many_nodes; }
bool isPresent(const T& target) const;

T grab( ) const;
void display() ;
private:
node *head_ptr; // List head pointer
size_type many_nodes; // Number of nodes on the list
};

// NONMEMBER FUNCTIONS for the set class:
set<T> operator +(const set& b1, const set& b2);
set<T> operator -(const set& b1, const set& b2);
}

#endif
//Template class source file
//set.cpp
#include "set.h"
namespace main_savitch_5
{
set::size_type len;
set::value_type v;
template<class T>
set::set()
{
len=0;
}
template<class T>
set::set(const set& source)
{
v=source.v;
len++;
}
template<class T>
set::~set()
{
//delete v;
}
template<class T>
bool set<T>::erase(const T& target)
{
if(target==v)
{
len--;
return 1;
}
else
return 0;
}
template<class T>
bool set<T>::insert(const T& target)
{
if(target!=v)
{
len++;
return 1;
}
else
return 0;
}
template<class T>
set set<T>::intersect(const set& set2)
{
set t;
if(v==set2.v)
t.v=v;
return t;
}
template<class T>
void set<T>::operator +=(const set& addend)
{
if (v!=addend.v)
{
v+=addend.v;
}
}
template<class T>
void set<T>::operator -=(const set& set2)
{
if (v!=addend.v)
{
v-=addend.v;
}
}
template<class T>
void set<T>::operator =(const set& source)
{
if (v!=addend.v)
{
v-=addend.v;
}
}
// CONSTANT MEMBER FUNCTIONS
template<class T>
size_type set<T>::size( ) const
{
return len;
}
template<class T>
bool set<T>::isPresent(const T& target) const
{
if(target==v)
return 1;
else
return 0;
}
template<class T>
T set<T<::grab( ) const
{
if(len>0)
return v;
}
template<class T>
void set<T>::display()
{
cout<<v;
}
template<class T>
friend set<T> operator +(const set& b1, const set& b2)
{
set t;
t.v=b1.v+b2.v;
return t;
}
template<class T>
set<T> operator -(const set& b1, const set& b2)
{
set t=b1.v-b2.v;
return t;
}
#endif
