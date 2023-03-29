# Parametric Polymorphism

Every Program  requires us to declare variables, functions, and most other kinds of entities using specific types. However, a lot of code looks the same for different types. Especially if you implement algorithms, such as quicksort, or if you implement the behavior of data structures, such as a linked list or a binary tree for different types, the code looks the same despite the type used.

- You can implement the same behavior again and again for each type that needs this behavior.
  - If you implement a behavior again and again, you reinvent the wheel. You make the same mistakes and you tend to avoid complicated but better algorithms because they lead to even more mistakes.
- You can write general code for a common base type such as Object or void*.
  - If you write general code for a common base class you lose the benefit of type checking. In addition, classes may be required to be derived from special base classes, which makes it more difficult to maintain your code.
- You can use special preprocessors.
  - If you use a special preprocessor such as the C/C++ preprocessor, you lose the advantage of formatted source code. Code is replaced by some "stupid text replacement mechanism" that has no idea of scope and types.

## Templates

A **template** is a construct that generates an **ordinary type or function at compile time** based on arguments the user supplies for the template parameters

- **Function Template**
- **Class Template**



#### Defining  the Template

---

> template < comma-separated-list-of-parameters >

```c++
template <typename T> //The keyword typename introduces a so-called type parameter
inline T const& max (T const& a, T const& b)
{
// if a < b then use b else use a
return a<b?b:a;
}
/* Here, the type parameter is T. You can use any identifier as a parameter name, but usinTg is the convention. The type parameter represents an arbitrary type that is specified by the caller when the caller calls the function. You can use any type (fundamental type, class, and so on) as long as it provides the operations that the template uses. In this case, type T has to support operator < because a and b are compared using this operator */

//For historical reasons, you can also use class instead of typename to define a type parameter.
template <class T>
inline T const& max (T const& a, T const& b)
{
// if a < b then use b else use a
return a<b?b:a;
}
```

#### template instantiation

---

> The process of **replacing** template parameters by **concrete** types is called **instantiation**

```C++
int main()
{
int i = 42;
std::cout << "max(7,i): " << ::max(7,i) << std::endl;
double f1 = 3.4;
double f2 = -6.7;
std::cout << "max(f1,f2): " << ::max(f1,f2) << std::endl;
std::string s1 = "mathematics";
std::string s2 = "math";
std::cout << "max(s1,s2): " << ::max(s1,s2) << std::endl;
}
```

>Normally, templates aren't compiled into single entities that can handle any type. Instead, different entities are
>generated from the template for every type for which the template is used. 

```
 max(7,10) …
uses the function template with int as template parameter T. Thus, it has the semantics of calling the following code:
inline int const& max (int const& a, int const& b)
{
// if a < b then use b else use a
return a<b?b:a;
}
```

### Note:

- An attempt to instantiate a template for a type that doesn't support all the operations used within it will result in a
  compile-time error
- templates are compiled twice:
  - Without instantiation, the template code itself is checked for correct syntax. Syntax errors are discovered,
    such as missing semicolons.
  - At the time of instantiation, the template code is checked to ensure that all calls are valid. Invalid calls are discovered, such as unsupported function calls.

#### Function Template Parameters

-- -

Function templates have two kinds of parameters

- Template parameters, which are declared in angle brackets before the function template name:
  template <typename T> // T is template parameter
- Call parameters, which are declared in parentheses after the function template name:
  … max (T const& a, T const& b) // a and b are call parameters
- in function templates (unlike class templates) no default template arguments can be specified
- Supports Multiple  template parameters

```C++
template <typename T1, typename T2>
inline T1 max (T1 const& a, T2 const& b)
{
return a < b ? b : a;
}
```



### Function template argument deduction.

---

It allows you to call a function template as you would an ordinary function. Because the types of the call parameters are constructed from the template parameters, template and call parameters are usually related.

instantiate a template explicitly for certain types:

```C++
template <typename T>
inline T const& max (T const& a, T const& b);
…
max<double>(4,4.2) // instantiate T as double
```

> template argument deduction does not match up return types

```C++
template <typename T1, typename T2, typename RT>
inline RT max (T1 const& a, T2 const& b);

max<int,double,double>(4,4.2)
    
template <typename RT, typename T1, typename T2>
inline RT max (T1 const& a, T2 const& b);
…
max<double>(4,4.2)
```

## Template Parameters

There are three kinds of template parameters:

- Type parameters (these are by far the most common)
  - Type parameters are introduced with either the keyword **typename** or the keyword **class**

- Nontype parameters
  - Nontype template parameters stand for constant values that can be determined at compile or link time.
  - Nontype template parameters must be one of the following:
    - An integer type or an enumeration type
    - A pointer type (including regular object pointer types, function pointer types, and pointer-to-member types)
    - A reference type (both references to objects and references to functions are acceptable)
  - nontype parameters are always rvalues: Their address cannot be taken, and they cannot be assigned to.

- Template template parameters

  ```C++
  template<typenameT,template<typename U,int I> class Arr>
  class MyClass2
  {
  T t;
  //OK
  Arr<T,10> a;
  U u;//Error. U not in scope
  };
  
  //template<typenameT,template<typename,int> class Arr>
  ```

  



### Class Templates

---

- Used to implement container classes while the element type is still open
- Member functions can be defined inside or outside of a class template
- Member functions  defined like function templates if defined outside the class template.



```c++
template <typename T>
class Stack {
private:
std::vector<T> elems; // elements
public:
void push(T const&); // push element
void pop(); // pop element
T top() const; // return top element
bool empty() const { // return whether the stack is empty
return elems.empty();
}
};


template <typename T>
void Stack<T>::push (T const& elem)
{
elems.push_back(elem); // append copy of passed elem
}

template<typename T>
void Stack<T>::pop ()
{
if (elems.empty()) {
throw std::out_of_range("Stack<>::pop(): empty stack");
}
elems.pop_back(); // remove last element
}

template <typename T>
T Stack<T>::top () const
{
if (elems.empty()) {
throw std::out_of_range("Stack<>::top(): empty stack");
}
return elems.back(); // return copy of last element
}
```



### Specializations of Class Templates

---

```C++
template<>
class Stack<std::string> {
…
};

//Partial Specialization
template <typename T1, typename T2>
class MyClass {
…
};

// partial specialization: both template parameters have same type
template <typename T>
class MyClass<T,T> {
…
};

// partial specialization: second type is int
template <typename T>
class MyClass<T,int> {
…
};

// partial specialization: both template parameters are pointer types
template <typename T1, typename T2>
class MyClass<T1*,T2*> {
…
};

MyClass<int,float> mif; // uses MyClass<T1,T2>
MyClass<float,float> mff; // uses MyClass<T,T>
MyClass<float,int> mfi; // uses MyClass<T,int>
MyClass<int*,float*> mp; // uses MyClass<T1*,T2*>

If more than one partial specialization matches equally well, the declaration is ambiguous:
MyClass<int,int> m; // ERROR: matches MyClass<T,T> and MyClass<T,int>
MyClass<int*,int*> m; // ERROR: matches MyClass<T,T> and and MyClass<T1*,T2*>
```

#### Default Template Arguments

---

Class templates supports  default values for template parameters. These values are called default template arguments

```C++
template <typename T, typename CONT = std::vector<T> >
class Stack {
private:
CONT elems; // elements
public:
void push(T const&); // push element
void pop(); // pop element
T top() const; // return top element
bool empty() const { // return whether the stack is empty
return elems.empty();
}
};

template <typename T, typename CONT>
void Stack<T,CONT>::push (T const& elem)
{
elems.push_back(elem); // append copy of passed elem
}

ex: 2 
//When using a template whose parameters are all defaulted, use empty angle brackets
template<typename A=int,typename B= double>
class Bar
{
//...
};
...
int main()
{
Bar<> bar;
// use all default type arguments
}
```



### Nested class templates

---

- Templates can be defined within classes or class templates, in which case they're referred to as member templates
- Nested class templates are declared as class templates inside the scope of the outer class.

```C++
// nested_class_template1.cpp

#include <iostream>
using namespace std;

class X
{

   template <class T>
   struct Y
   {
      T m_t;
      Y(T t): m_t(t) { }
   };

   Y<int> yInt;
   Y<char> yChar;

public:
   X(int i, char c) : yInt(i), yChar(c) { }
   void print()
   {
      cout << yInt.m_t << " " << yChar.m_t << endl;
   }
};

int main()
{
   X x(1, 'a');
   x.print();
}
```

#### Reuse of Template Parameters

---

- Template parameters can be reused in the template parameter list.

  ```c++
  // template_specifications2.cpp
  
  class Y
  {
  };
  template<class T, T* pT> class X1
  {
  };
  template<class T1, class T2 = T1> class X2
  {
  };
  
  Y aY;
  
  X1<Y, &aY> x1;
  X2<int> x2;
  
  int main()
  {
  }
  ```

  

#### Summary

---



- A class template is a class that is implemented with one or more type parameters left open.
- To use a class template, you pass the open types as template arguments. The class template is then instantiated (and compiled) for these types.
- For class templates, only those member functions that are called are instantiated.
- You can specialize class templates for certain types.
- You can partially specialize class templates for certain types.
- You can define default values for class template parameters. These may refer to previous template
  parameters.



##### Nontype Class Template Parameters

----

- You cannot use floating-point numbers, class-type objects, and objects with internal linkage (such as string
  literals) as arguments for nontype template parameters

```C++
template <typename T, int MAXSIZE>
class Stack {
private:
T elems[MAXSIZE]; // elements
int numElems; // current number of elements
    
public:
Stack(); // constructor
void push(T const&); // push element
void pop(); // pop element
T top() const; // return top element
bool empty() const { // return whether the stack is empty
return numElems == 0;
}
bool full() const { // return whether the stack is full
return numElems == MAXSIZE;
}
};

// constructor
template <typename T, int MAXSIZE>
Stack<T,MAXSIZE>::Stack ()
: numElems(0) // start with no elements
{
// nothing else to do
}

template<auto x> constexpr auto constant = x;
auto v1 = constant<5>;
// v1 == 5, decltype(v1) is int
auto v2 = constant<true>;
// v2 == true, decltype(v2) is bool
auto v3 = constant<'a'>;
// v3 == 'a', decltype(v3) is char
```

### template restriction

---

The primary restriction when using templates is that a type argument must support any operations that are applied to the type parameters

```C++
template<typename T>
T minimum(const T& lhs,const T& rhs)
{
return lhs < rhs ? lhs : rhs;
}

class MyClass
{
public:
int num;
std::wstring description;
};

int main()
{
MyClass mc1 {1,L"hello"};
MyClass mc2 {2,L"goodbye"};
auto result = minimum(mc1, mc2);
// Error! C2678
}
```

