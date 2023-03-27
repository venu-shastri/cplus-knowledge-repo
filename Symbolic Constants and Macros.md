## Symbolic Constants and Macros

simple mechanism for naming constants or sequences of commands

>  Syntax:  #define name substitutetext
>
> The preprocessor replaces name with substitutetext throughout the subsequent program.

#### Advantages

---

- good readability: You can name a macro to indicate the use of the macro
- easy to modify: If you need to change the value of a constant throughout a program,
  you simply change the value of the symbolic constant in the #define
  directive.



```C++
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI 3.1415926536
#define START 0.0 // Lower limit
#define END (2.0 * PI) // Upper limit
#define STEP (PI / 8.0) // Step width
#define HEADER (cout << \
" ***** Sine Function Table *****\n\n")
int main()
{
HEADER; // Title
// Table Head:
cout << setw(16) << "x" << setw(20) << "sin(x)\n"
<< " -----------------------------------------"
<< fixed << endl;
double x;
for( x = START; x < END + STEP/2; x += STEP)
cout << setw(20) << x << setw(16) << sin(x)
<< endl;
cout << endl << endl;
return 0;
}


```



#### Macros with Parameters

---

```C++
#include <iostream>
#include <string>
using namespace std;


#define PRINT(z,s) (cout << z <<';'<< s<<endl)
#define SQUARE(a) ((a) * (a))

void main()
{

	PRINT(1, 25); 
	PRINT(25, 1); 
	PRINT(SQUARE(2), SQUARE(3));
}


```



#### Using macros in different source files

---

![image-20230327221319912](E:\Bosch_C++_Training\macorsInSourceFiles)

> If you need to use the same macros in different source files, it makes sense to create a header file. You can then include the header file in your source files



####  Redefining Macros

---

> A macro definition is valid until it is removed by using an ` #undef` directive.

```C++
#include <iostream>
#include <string>
using namespace std;
#define MIN(a,b) ((a)<(b)? (a) : (b))

void main()
{

	cout << MIN(3, 2) << endl;
    #undef MIN;
	cout << MIN(3, 2) << endl; //error
    #define MIN(a,b) ((a)>(b)? (a) : (b))
	cout << MIN(3, 2) << endl;

}

```

#### Conditional Inclusion

---

> You can use the preprocessor directives ` #ifdef ` and `#ifndef` to allow the compiler to check whether a macro has been defined

```
#include <iostream>
#include <string>

using namespace std;

#define MIN(a,b) ((a)<(b)? (a) : (b))
#define name

void main()
{
#ifdef name
	 // Block, which will be compiled  if name is defined.
	cout << MIN(3, 2) << endl;
    #undef MIN;
	#define MIN(a,b) ((a)>(b)? (a) : (b))
	cout << MIN(3, 2) << endl;
#endif

}
```



#### EXCERSISE

---

Please write

- The macro `ABS`, which returns the absolute value of a number,
- The macro `MAX`, which determines the greater of two numbers.
- In both cases use the conditional operator ?: .
- Add these macros  to the header file `mathMacors.h` and then test the macros.

