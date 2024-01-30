// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
//abstract class
final class A{
    public:
    void m1(){} //closed 
    virtual void m2(){} //open for extensibility
    virtual void m3() =0;//pure virtual method
    
};
class Child:public A{
    
    public: 
    //shadowing
    void m1() {}
    void m2() override final{ } 
    void m3() override {}
};
class GrandChild:public Child{
    public:
    void m2() override{} 
};

class NewChild:public A{
    
    //override(virtual)
    public: void m2(){ } 
            void m1(){}
            void m3() override {}
};

int main(){
Child childObj;
A *obj=&childObj;
obj->m2();// Dynamic   binding 
obj->m1();
NewChild newChildObj;
obj=&newChildObj;
obj->m2();
obj->m1();
GrandChild gChildObj;
obj=&gChildObj;
obj->m2();
}
