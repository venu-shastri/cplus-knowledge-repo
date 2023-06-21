#include <iostream>
#include <string>
using namespace std;
class A{
    public:
    A(){
        std::cout<<"A - Default Constructor"<<std::endl;
     }
     A(string msg){
        std::cout<<"A - Overloaded Constructor "<<msg<<std::endl;
     }
};
class B:virtual public A{
    public:
    B(){
        std::cout<<"B - Default Constructor"<<std::endl;
     }
};

class C: virtual public A{
    public:
    C(){
        std::cout<<"C - Default Constructor"<<std::endl;
     }
};
class D:public B,public C{
    public:
    D():A{"Message from BC"}{
        std::cout<<"D - Default Constructor"<<std::endl;
     }
};

int main(){
    D obj;
}
