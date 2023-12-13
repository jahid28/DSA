//part of polymorphism
#include <iostream>
using namespace std;

class A{
    public:
    void print(){
        cout<<"inside a"<<endl;
    }
    
};
class B:public A{
   public:
    void print(){
        cout<<"inside b"<<endl;
    }
    
};

int main(){
   A a;
   B b;
   a.print();
   b.print();



    return 0;
}