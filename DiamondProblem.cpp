class A {

};
class C: virtual public A{

public:
	void sayHello() {
		cout << "Hello From C" << endl;
	}
};
class B:virtual public A {
public:
	void sayHello() {
		cout << "Hello From B" << endl;
	}
};
class D:public C,public B {

};
