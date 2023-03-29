## References and Pointers

- A reference is another name, or alias, for an object that already exists
- Defining a reference does not occupy additional memory
- Any operations defined for the reference are performed with the object to which it refers.
- References are particularly useful as parameters and return values of functions.
- The **ampersand character, &,** is used to define a reference. Given that **T is a type, T& denotes a reference to T.**
- A reference must be initialized when it is declared, and cannot be modified subsequently.

```C++
Example: 
float x = 10.7;
float& rx = x; // or: float &rx = x;

The & character, which indicates a reference, only occurs in declarations and is not related to the address operator &! The address operator returns the address of an object. If you apply this operator to a reference, it returns the address of the referenced object.
```

```C++
// --------------------------------------------------
// Demonstrates the definition and use of references.
// ---------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
float x = 10.7F; // Global
int main()
{
	float& rx = x; // Local reference to x
	
	//double &ref = x; // Error: different type!
	rx *= 2;
	cout << " x = " << x << endl // x = 21.4
		<< " rx = " << rx << endl; // rx = 21.4
	const float& cref = x; // Read-only reference
	cout << "cref = " << cref << endl; // ok!
	// ++cref; // Error: read-only!
	const string str = "I am a constant string!";
	// str = "That doesn't work!"; // Error: str constant!
	// string& text = str; // Error: str constant!
	const string& text = str; // ok!
	cout << text << endl; // ok! Just reading.
	return 0;
}
```



#### Read-Only References 

---

- A reference that addresses a constant object must be a constant itself,
- it is conversely possible to use a reference to a constant to address a non-constant object

```
Example: 

int a; 
const int& cref = a; // ok!
The reference cref can be used for read-only access to the variable a, and is said to be a read-only identifier.

A read-only identifier can be initialized by a constant, in contrast to a normal reference:
Example:

const double& pi = 3.1415927;

Since the constant does not take up any memory space, the compiler creates a temporary object which is then referenced.
```



#### References as Parameters

---

- Passing By Reference : 

```
Example: 
void test( int& a) { ++a; }
Based on this definition, the statement
test( var); // For an int variable var
```

> If an object is passed as an argument when passing by reference, the object is not copied. Instead, the address of the object is passed to the function internally, allowing the function to access the object with which it was called.



```C++
// --------------------------------------------------
// Demonstrating functions with parameters
// of reference type.
// --------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
// Prototypes:
bool getClient(string& name, long& nr);
void putClient(const string& name, const long& nr);
int main()
{
	string clientName;
	long clientNr;
	cout << "\nTo input and output client data \n"
		<< endl;
	if (getClient(clientName, clientNr)) // Calls
		putClient(clientName, clientNr);
	else
		cout << "Invalid input!" << endl;
	return 0;
}
bool getClient(string& name, long& nr) // Definition
{
	cout << "\nTo input client data!\n"
		<< " Name: ";
	if (!getline(cin, name)) return false;
	cout << " Number: ";
	if (!(cin >> nr)) return false;
	return true;
}
// Definition
void putClient(const string& name, const long& nr)
{ // name and nr can only be read!
	cout << "\n-------- Client Data ---------\n"
		<< "\n Name: "; cout << name
		<< "\n Number: "; cout << nr << endl;
}
```





#### References as Return Value

----

- The return type of a function can also be a reference type.
- References are commonly used as return types when overloading operators

```
Example: 
string& message() // Reference!
{
	static string str = "Hello";
	return str;
}

 The object referenced by the return value must exist after leaving the function.
```



#### Calling a Reference Type Function

---

```C++
message();
//represents a string type object, and the following statements are valid:
message() = "Let's go to the beer garden!";
message() += " Cheers!";
cout << "Length: " << message().length();

In these examples, a new value is first assigned to the object referenced by the function call. Then a new string is appended before the length of the referenced string is output in the third statement.
    
If you want to avoid modifying the referenced object, you can define the function type as a read-only reference.
    
Example: const string& message(); // Read-only!
```



#### Expressions with Reference Type

----

```C++
// Ref4.cpp
// Expressions with reference type exemplified by
// string assignments.
// --------------------------------------------------
#include <iostream>
#include <string>
#include <cctype> // For toupper()
using namespace std;
void strToUpper(string&); // Prototype
int main()
{
	string text("Test with assignments \n");
	strToUpper(text);
	cout << text << endl;
	strToUpper(text = "Flowers");
	cout << text << endl;
	strToUpper(text += " cheer you up!\n");
	cout << text << endl;
	return 0;
}
void strToUpper(string& str) // Converts the content
{ // of str to uppercase.
	int len = str.length();
	for (int i = 0; i < len; ++i)
		str[i] = toupper(str[i]);
}
```



#### References and Pointers

---

- References are similar to pointers: both refer to an object in memory.
- A pointer is not merely an alias but an individual object that has an identity separate from the
  object it references
- A pointer has its own memory address and can be manipulated by pointing it at a new memory address and thus referencing a different object.