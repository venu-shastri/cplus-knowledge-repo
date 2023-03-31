## Value Categories

`lvalue`, `rvalue`, `prvalue`, and `xvalue`

> Each expression in a C++ program has a value category.
>
> The value category is essential to decide what you can do with an expression.
>
> Whether a **call** or **operation** in C++ is valid depends on **both the type and the value category.**

Any expression in a C++ 11 program belongs to exactly one of these primary value categories:

![image-20230330214230926](valueCategories)

- **lvalue** (“locator value”)
-  **prvalue** (“pure readable value”)
-  **xvalue** (“eXpiring value”)
- The composite categories are:
  -  **glvalue** (“generalized lvalue”) as a common term for “lvalue or xvalue”
  -  **rvalue** as a common term for “xvalue or prvalue”



```C++
class X {

};
int main() {
	X v;
	const X c;

	f(v); // passes a modifiable lvalue
	f(c); // passes a non-modifiable lvalue
	f(X()); // passes a prvalue (old syntax of creating a temporary)
	f(X{}); // passes a prvalue (new syntax of creating a temporary)
	f(std::move(v)); // passes an xvalue
}
```



### lvalue

----

- An **lvalue** could occur on the **left-hand side** of an assignment

- An **lvalue** is an object that has a specified location in the program (so that you can take the address)
- a variable in itself is not an lvalue; only an expression denoting the variable is an lvalue:

```C++
int x; // x is an lvalue when used in an expression
x = 42; // OK, because x is an lvalue and the type matches
42 = x; // ERROR: 42 is an rvalue and can be only on the right-hand side of an assignment
int* p1 = &x; // OK: & is fine for lvalues (object has a specified location)
int* p2 = &42; // ERROR: & is not allowed for rvalues (object has no specified location)
const int c = 42; // Is c an lvalue or rvalue?
c = 42; // now an ERROR (so that c should no longer be an lvalue)
const int* p1 = &c; // still OK (so that c should still be an lvalue)
int x = 3; // here, x is a variable, not an lvalue
int y = x; // here, x is an lvalue
```



### Motivation for Move Semantics
---

- Reference
- Reference



### Move Constructor

----



```C++
class string {
private:
	int len; // current number of characters
	char* data; // dynamic array of characters
public:

		// move constructor: initialize the new string from s (stealing the value):
		string(string&& s)
		: len{ s.len }, data{ s.data } { // copy number of characters and pointer to memory
		s.data = nullptr; // release the memory for the source value
		s.len = 0; // and adjust number of characters accordingly
	}

};

we can call move constructor  for a string as follows:
std::string c = std::move(b); // initialize  c with the value of b (no longer needing its value here)

```

> The move constructor first copies both the members len and data, meaning that the new string gets ownership
> of the value of b .

![image-20230330230546307](moveConstructor)

> However, this is not enough, because the destructor of b would free the memory. Therefore, we also modify
> the source string to lose its ownership of the memory and bring it into a consistent state representing the
> empty string: The effect is that **c** now has the former value of  **b and that b is the empty string.**

![image-20230330230723339](moveConstructor_2)

Note

>The only guarantee is that b is subsequently in a valid but unspecified state. Depending on the way the move
>constructor is implemented in a C++ library, it might not be empty (but it usually is because this is the easiest
>and best way to improve performance here).
