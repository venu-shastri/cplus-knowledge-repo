## Operator Overloading

>  Overloading operators allows you to apply existing operators to objects of class type



![image-20230329221412377](E:\cplus-knowledge-repo\overloadableOperators)

Note:

> Each operator such as assignment operator =, the address operator &, and the comma operator, have a predefined
> meaning for each built-in type. This meaning can be changed for classes by a definition of your own.

#### Operator Overloading Rules

---

- An operator is always overloaded in conjunction with a class
- You cannot create “new operators”—that is, you can only overload existing operators.
-  You cannot redefine the operators for fundamental types.
-  You cannot change the operands of an operator. A binary operator will always be binary and a unary operator will always be unary.
- The precedence and the order of grouping operators of the same precedence remains unchanged.
- To overload an operator, you just define an appropriate `operator` function
  - The name of an operator function must begin with the `operator keyword` followed by the `operator symbol`.
  - An operator function can be defined as a global function or as a class method

Examples:

```C++

```

```C++
#include <iostream>
using namespace std;
class DayTime
{
private:
	short hour, minute, second;
	bool overflow;
public:
	DayTime(int h = 0, int m = 0, int s = 0):hour(h),minute(m),second(s) { }
	bool setTime(int hour, int minute, int second = 0) {
		this->hour = hour; this->minute = minute; this->second = second;
		return true;
	}
	int getHour() const { return hour; }
	int getMinute() const { return minute; }
	int getSecond() const { return second; }
	int asSeconds() const // Daytime in seconds
	{
		return (60 * 60 * hour + 60 * minute + second);
	}
	bool operator<(const DayTime& t) const // compare
	{ // *this and t
		return asSeconds() < t.asSeconds();
	}
	DayTime& operator++() // Increment seconds
	{
		++second; // and handle overflow.
		return *this;
	}
	
};

int main() {
	DayTime depart1(11, 11, 11), depart2(12, 0, 0);
	
		if (depart1 < depart2)
			cout << "\nThe 1st plane takes off earlier!" << endl;
	
}
```

```C++
#include <iostream>
#include <cstdlib> // For exit()
using namespace std;
#define MAX 100
class FloatArr
{
private:
	float v[MAX]; // The array
public:
	float& operator[](int i);
	static int MaxIndex() { return MAX - 1; }
};
float& FloatArr::operator[](int i)
{
	if (i < 0 || i >= MAX)
	{
		cerr << "\nFloatArr: Outside of range!" << endl;
		exit(1);
	}
	return v[i]; // Reference to i-th element.
}
int main()
{
	cout << "\n An array with range checking!\n"
		<< endl;
	FloatArr random; // Create array.
	int i; // An index.
	// Fill with random euros:
	for (i = 0; i <= FloatArr::MaxIndex(); ++i)
		random[i] = (rand() - RAND_MAX / 2) / 100.0F;
	cout << "\nEnter indices between 0 and "
		<< FloatArr::MaxIndex() << "!"
		<< "\n (Quit by entering invalid input)"
		<< endl;
	while (cout << "\nIndex: " && cin >> i)
		cout << i << ". element: " << random[i];
	return 0;
}
```



### The Friend Concept

---

- You might want to give functions or specific classes access to the private members of another class if they are used in conjunction with that class. A "friend declaration" makes this feasible.
- A class can grant any function a special permit for direct access to its private members
- Eliminates data encapsulation in certain cases
- UseCase:

```
Imagine you need to write a global function that accesses the elements of a numerical array class. If you need to call the access methods of the class each time, and if these methods perform range checking, the function runtime will increase considerably. However, special permission to access the private data members of the class can dramatically improve the function’s response.
```

#### Declaring Friend Functions

---

![image-20230330051412343](E:\cplus-knowledge-repo\friendFunction)

- Here the global function **globFunc()** and the method **elFunc()** of class B are declared as friend functions of class A.
- This allows them direct access to the private members of class A
- It is important to note that the **class itself determine**s who its friends are
- friend functions can also be defined inline in a class.



#### Overloading Using Friend Function

---

```c++
class MyString {
private: int length;
	  const  char* data;
public:
	MyString(int lengthArg, const char* content) :length{ lengthArg }, data{ content }{

	}
	friend ostream& operator<<(ostream& out, const MyString& source) {
		out << source.data << endl;
		return out;

	}
};

int main(){
	MyString s{ 2,"hi" };
	cout << s << endl;
	
	
}
```



#### Declaring Friend Classes

----

- We  can also make entire classes “**friends**” of another class

  - All the methods in this “friendly” class automatically become friend functions in the class containing the friend declaration.

  - This technique is useful if a class is used in such close conjunction with another class that all the methods in that class need access to the private members of the other class.

    

```c++
For example, the class StatisticsGenerator uses objects of the DataAggregator class. Calculations with individual measurements are performed repeatedly. In this case, it makes sense to declare the StatisticsGenerator class as a friend of the DataAggregator class.

Example:
class DataAggregator
{
public:
friend class StatisticsGenerator;
};

you can consider a friend declaration as an extension of the public interface. For this reason, it is preferable to place a friend declaration in the public area of a class.
```



Note:

>
>
>extensive use of friend techniques diffuses the concept of data encapsulation. Allowing external functions to manipulate internal data can lead to inconsistency, especially if a class is modified or extended in a later version. For this reason, you should take special care when using friend techniques.