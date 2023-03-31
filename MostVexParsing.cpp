struct B
{
    explicit B(int x) {}
    explicit B(){}
};

struct A
{
    A(B const& b) {}
    void doSomething() {}
};

struct C
{
    void doSomething() {}
};
int main()
{
    int x = 42;

    A a(B(x));
    A aobj(B()); //is parsed as a function that returns an A and that takes a function that returns a B and takes no parameter.

    C c();//is parsed as a function that returns an C and that takes zero argument 
  //  c.doSomething(); Error
   // a.doSomething(); Error
    
    //fixing the most vexing parse
    

    A a_obj((B(x)));//Before C++ 11
    a_obj.doSomething();

    auto a_object = A(B(x)); //auto to stick syntax
    a_object.doSomething();
   
    A a_new_object(B{ x });
    a_new_object.doSomething();
    
}
