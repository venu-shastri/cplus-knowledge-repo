## Exception Handling

- Errors that occur at program runtime can seriously interrupt the normal flow of a program.
- One of the programmer’s most important tasks is to predict and handle errors

#### Traditional Error Handling

---

- errors in function calls are indicated by special return values

  - If a function uses its return value to indicate errors, the return value must be examined whenever the function is called, even if no error has occurred.

    ![image-20230329211625127](E:\cplus-knowledge-repo\ErrorReturnValue)

- global error variables or flags are set when errors occur, and then checked again
  later.

#### Exception Handling Concept

----

> The basic idea is that errors occurring in one particular part of the program are reported to another part of
> the program, known as the calling environment. The calling environment performs central error handling

#### The throw Statement

---

- We also say that an exception has been thrown because when an exception happens, a throw statement records it to the caller environment.

  ```
  Syntax: throw fault;
  
  The expression fault is an exception object that is thrown to the calling environment. It can belong to any type except void.
  
  Example: throw "Fire!";
  
  In this example, the exception object is a string that is thrown to the calling environment.
  ```

  

  #### Exception Classes

  ----

  - We define our own exception classes to categorize exceptions

  - Generally, the exception class will contain members that provide more specific information on the
    cause of the error.

    

```C++
class Error
{
	// Infos about the error cause
};
double calc(int a, int b)
{
	if (b < 0)
		throw (string)"Denominator is negative!";
	if (b == 0)
	{
		Error errorObj;
		throw errorObj;
	}
	return ((double)a / b);
}
```



#### Exception Handlers

---

```C++
class Type1 {

};
class Type2 {

};
int main() {
	try
	{
		// Exceptions thrown by this block will be
		// caught by the exception handlers,
		// which are defined next.
	}
	catch (Type1 exc1)
	{
		// Type1 exceptions are handled here.
	}
	catch (Type2 exc2)
	{
		// Type2 exceptions are handled here.
	}
	catch (...)
	{
		// All other exceptions are handled here.
	}
}
```



#### try and catch Blocks

---

- A try block contains the program code in which errors can occur and exceptions can be thrown. Normally, a try block will consist of a group of functions that can produce similar errors.
- Each catch block defines an exception handler, where the exception declaration, which is enclosed in parentheses, defines the type of exceptions the handler can catch. Th catch blocks immediately follow the try block. A minimum of one catch block is required
- It is common practice to define specific handlers for certain types of errors and one generic handler for all other errors.



#### Searching for Handlers

---

- After leaving the try block, the program control is transferred to an matching handler in the catch blocks that follow
- A handler is called when the type in the exception declaration is
  ■ identical to the exception type thrown or
  ■ a base class of the exception type or
  ■ a base class pointer and the exception is a pointer to a derived class.



#### Nested try and catch blocks

---

```C++
try
{
	// Type1 exceptions are thrown here.
	try
	{
		// Type1 and Type2 exceptions are thrown here.
	}
	catch (Type2 e2)
	{
		// Type2 exceptions are pre-handled here
		throw; // and thrown again.
	}
	// Other Type1 exceptions
	// can be thrown.
}
catch (Type1 e1)
{
	// Type1 exceptions are handled here.
}
catch (...)
{
	// All remaining exceptions are handled here,
	// particularly Type2 exceptions.
}
```



#### Exception Specifications

---

- The exceptions a function can throw can be stated in a so-called exception specification list when you declare a function.
- The exceptions that a function can throw are features of that function.
- The application programmer must have knowledge of both the function prototype and the exceptions the
  function can throw to ensure that he or she will be capable of programming correct function calls and taking appropriate action in case of errors

```
Example: int func(int) throw(BadIndex, OutOfRange);

The list BadIndex, OutOfRange states the exceptions that the function func()can throw. If the list is empty, that is, if the list contains only the throw() statement, no exceptions are thrown. If the throw statement is also missing, there is no specific information about possible exceptions and any exception can be thrown.
```

#### Defining Our Exception Classes

---

```C++
#include <string>
#include <iostream>
using namespace std;
class MathError
{
private:
	string message;
public:
	MathError(const string& s) : message(s) {}
	const string& getMessage() const { return message; }
};
double calc(int a, int b) throw(MathError);
int main()
{
	int x, y; bool flag = false;
	do
	{
		try // try block
		{
			cout << "Enter two positive integers: ";
			cin >> x >> y;
			cout << x << "/" << y << " = " << calc(x, y) << '\n';
			flag = true; // To leave the loop.
		}
		catch (MathError& err) // catch block
		{
			cerr << err.getMessage() << endl;
		}
	} while (!flag);
	// continued ...
	return 0;
}
double calc(int a, int b) throw (MathError)
{
	if (b < 0)
		throw MathError("Denominator is negative!");
	if (b == 0)
		throw MathError("Division by 0!");
	return ((double)a / b);
}
```



#### Standard Exception Classes

---

- `logic_error` used to represent logic errors, caused by anomalies in the program’s logic. These errors can be avoided.

- `runtime_error` used to represent runtime errors, such as under- or overflows occurring
  in internal computations. These errors are unpredictable.

  

![image-20230329220012166](E:\cplus-knowledge-repo\exception classes)