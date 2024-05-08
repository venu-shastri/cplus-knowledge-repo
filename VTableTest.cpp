// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
class A{
public:
	virtual void M1() { cout << "A.M1()" << endl; }
	void M2(){ cout << "A.M2()" << endl; }
};
class B:public A {
public :
		 void M1() override  { cout << "B.M1()" << endl; }
		 void M2() { cout << "B.M2()" << endl; }
		 virtual void M3(){ cout << "B.M3()" << endl; }
		 void M4() { cout << "B.M4" << endl; }
};
class C:public B {
public:
	void M1()  { cout << "C.M1()" << endl; }
	void M3() override { cout << "C.M3()" << endl; }
	void M4()  { cout << "C.M4()" << endl; }
};
int main() {
	A aObj;
	A* aPtr=&aObj;
	aPtr->M1();
	aPtr->M2();

	B bObj;
	B* bPtr = &bObj;
	bPtr->M1();
	bPtr->M2();
	bPtr->M3();
	bPtr->M4();

	aPtr = &bObj;
	aPtr->M1();
	aPtr->M2();

	C cObj;
	cObj.M1();
	cObj.M2();
	cObj.M3();
	cObj.M4();

	aPtr = &cObj;
	aPtr->M1();
	aPtr->M2();

	bPtr = &cObj;
	bPtr->M1();
	bPtr->M2();
	bPtr->M3();
	bPtr->M4();


	
}
