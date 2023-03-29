### Storage Classes and Namespaces

---

- The storage class is responsible for defining those parts of a program where an object or function can be used
- Namespaces can be used to avoid conflicts when naming global identifiers.



##### Storage Class Specifiers

---

The storage class of an object is determined by

- The position of its declaration in the source file
- The storage class specifier, which can be supplied optionally
  - `extern` 
  - `static`
  -  `auto`
  -  `register`

The storage class specifies the lifetime of the object

> The period of time from the construction of the object until its destruction, In addition, the storage class delimits the part of the program in which the object can be accessed directly by its name, the so-called object scope



######  A translation unit

---

Also referred to as module, comprises the source file you are compiling and any header files you have included.

##### object scope

---

- `block scope` : The object is only available in the code block in which it was defined. The object is no longer visible once you have left the code block.
- `file scope`: The object can be used within a single module. Only the functions within this module can reference the object. Other modules cannot access the object directly.
- `program scope`: The object is available throughout the program, providing a common space in memory that can be referenced by any program function. For this reason, these objects are often referred to as global.



##### Availability Of an Object

---

![image-20230329051547067](E:\Bosch_C++_Training\AvailabilityOfAnObject)



#### THE STORAGE CLASS `extern` (Defining Global Objects and Use Global Objects)

---

**Example** :     `extern long position; // Declaration`

- If an object is not defined within a function, it belongs to the extern storage class
- The extern declaration thus allows you to “import” an object from another source file.
- An extern declaration only refers to an object and should therefore not be used to initialize the object
- External objects thus allow you to exchange information between any functions without passing any arguments.

```C++
//one.cpp
#include <iostream>
#include <string>
using namespace std;
void printLine(void); // Prototype
string line; // Global string
int main()
{
	while (getline(cin, line)) // As long as a line  can be read.
	{ 
	printLine(); // Print  the line.
	
	}
	return 0;
}

//two.cpp

/* Containing the function printLine(), which prints the line
  The string line has to be globally defined in another
 source file.
*/
#include <string>
#include <iostream>
using namespace std;
extern string line; // extern declaration
void printLine()
{
	cout << line << endl;
}
```

Note:

> Global objects affect the whole program and should be used sparingly. Large programs in particular should contain no more   than a few central objects defined as extern.





#### THE STORAGE CLASS `static`

----

**Example**:   `static int count;`

- **Definition external to all program functions** : In this case, the object is external static, that is, the object can be designated using its name within the module only, but will not collide with any objects using the same name in other modules.

- **Definition within a code block**: This means that the object is internal static, that is, the object is only visible within a single block. However, the object is created only once and is not destroyed on leaving the block. On re-entering the block, you can continue to work with the original object.

  

  ```C++
  // Passw1.cpp
  // The functions getPassword() and timediff()
  // to read and examine a password.
  // -----------------------------------------------------
  #include <iostream>
  #include <iomanip>
  #include <string>
  #include <ctime>
  using namespace std;
  long timediff(void); // Prototype
  static string secret = "ISUS"; // Password
  static long maxcount = 3, maxtime = 60; // Limits
  bool getPassword() // Enters and checks a password.
  { // Return value: true, if password is ok.
  	bool ok_flag = false; // For return value
  	string word; // For input
  	int count = 0, time = 0;
  	timediff(); // To start the stop watch
  	while (ok_flag != true &&
  		++count <= maxcount) // Number of attempts
  	{
  		cout << "\n\nInput the password: ";
  		cin.sync(); // Clear input buffer
  		cin >> setw(20) >> word;
  		time += timediff();
  		if (time >= maxtime) // Within time limit?
  			break; // No!
  		if (word != secret)
  			cout << "Invalid password!" << endl;
  		else
  			ok_flag = true; // Give permission
  	}
  	return ok_flag; // Result
  }
  long timediff() // Returns the number of
  { // seconds after the last call.
  	static long sec = 0; // Time of last call.
  	long oldsec = sec; // Saves previous time.
  	time(&sec); // Reads new time.
  	return (sec - oldsec); // Returns the difference.
  }
  
  int main(){
      if( !getPassword() )
  cout << "No authorization!\n"; exit(1);
  }
  ```

  

  Note:

  > In contrast to objects with an extern definition, the name of an external static object is unknown to the linker and thus retains its private nature within a module.

  

#### THE SPECIFIERS `auto` AND `register`

---

`auto` Objects :

**Example: auto float radius; // Equivalent to  float radius;**

- The storage class auto (automatic) includes all those objects defined within a function but without the static keyword
- The parameters of a function are also auto objects
- When the Thread reaches the function definition, the object is created on the stack, but in contrast to a static type object, the object is destroyed on leaving the block.
- auto objects have no specific initial value if they are not initialized explicitly

`register` Objects:

**Example: register int i = 0;**

- To increase the speed of a program, commonly used auto variables can be stored in CPU registers instead of on the stack.
- A register is normally the size of an int variable.it only makes sense to define register variables if the variable is not too large
- The compiler can ignore the register keyword : The number of registers available for register variables depends on your hardware, although two registers are normally available. If a program defines too many register variables in a code block, the
  superfluous variables are placed in the auto storage class.



## Namespaces

Using global names in large-scale software projects can lead to conflicts, especially when multiple class libraries are in operation

- C++ provides for the use of namespaces in order to avoid naming conflicts with global identifiers.
- Using namespaces global scope is subdivided into isolated parts.
- A  namespace is identified by a name preceded by the `namespace` keyword.

![image-20230329060715592](E:\Bosch_C++_Training\namespace)

- If you need to reference an element from outside of the namespace, you must additionally supply the namespace. To do so, place the **scope resolution operator, ::,** before the element name
- **Example: myLib::count = 7; // Outside of myLib**
- how to reference global names  ?    **::demo(); // Not belonging to any namespace**
- Global identifiers belonging to the C++ standard library automatically belong to the `standard namespace std`.

```c++
// ----------------------------------------------------
// Defines and tests namespaces.
// ----------------------------------------------------
#include <string> // Class string defined within
// namespace std
namespace MySpace
{
	std::string mess = "Within namespace MySpace";
	int count = 0; // Definition: MySpace::count
	double f(double); // Prototype: MySpace::f()
}
namespace YourSpace
{
	std::string mess = "Within namespace YourSpace";
	void f() // Definition of
	{ // YourSpace::f()
		mess += '!';
	}
}
namespace MySpace // Back in MySpace.
{
	int g(void); // Prototype of MySpace::g()
	double f(double y) // Definition of
	{ // MySpace::f()
		return y / 10.0;
	}
}
int MySpace::g() // Separate definition
{ // of MySpace::g()
	return ++count;
}
#include <iostream> // cout, ... within namespace std
int main()
{
	std::cout << "Testing namespaces!\n\n"
		<< MySpace::mess << std::endl;
	MySpace::g();
	std::cout << "\nReturn value g(): " << MySpace::g()
		<< "\nReturn value f(): " << MySpace::f(1.2)
		<< "\n---------------------" << std::endl;
	YourSpace::f();
	std::cout << YourSpace::mess << std::endl;
	return 0;
}
```

#### THE KEYWORD `using`

----

- You can simplify access to the elements of a namespace by means of a using declaration or using directive
- `using declarations` and `using directives` can occur at any part of the program
- `using decalartion` : 

```
A using declaration makes an identifier from a namespace visible in the current scope.
Example: using myLib::calculate; // Declaration
You can then call the function calculate() from the myLib namespace.
double erg = calculate( 3.7, 5);
```

- `using directives`:

```
The using directive allows you to import all the identifiers in a namespace.
Example: using namespace myLib;

If identical identifiers occur in the current namespace and an imported namespace, the using directive does not automatically result in a conflict. However, referencing an identifier can lead to ambiguities. In this case, you should use the scope resolution operator to resolve the situation.

C++ header files without file extensions are used to declare the global identifiers in the standard namespace std
```

```C++
// namesp2.cpp
// Demonstrates the use of using-declarations and
// using-directives.
// ----------------------------------------------------
#include <iostream> // Namespace std
void message() // Global function ::message()
{
	std::cout << "Within function ::message()\n";
}
namespace A
{
	using namespace std; // Names of std are visible here
	void message() // Function A::message()
	{
		cout << "Within function A::message()\n";
	}
}
namespace B
{
	using std::cout; // Declaring cout of std.
	void message(void); // Function B::message()
}
void B::message(void) // Defining B::message()
{
	cout << "Within function B::message()\n";
}
int main()
{
	using namespace std; // Names of namespace std
	using B::message; // Function name without
	// braces!
	cout << "Testing namespaces!\n";
	cout << "\nCall of A::message()" << endl;
	A::message();
	cout << "\nCall of B::message()" << endl;
	message(); // ::message() is hidden because
	// of the using-declaration.
	cout << "\nCall of::message()" << endl;
	::message(); // Global function
	return 0;
}
```

Note;

> When developing large-scale programs or libraries, it is useful to declare the elements of any proprietary namespaces in header files. Normal source files are used to define these elements.

 