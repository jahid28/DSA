//part of polymorphism
#include <iostream>
using namespace std;

class Sample{
    public:
    int a;
    public:
    void operator+ (Sample &obj){
        cout<<"jj"<<endl;
        int val1=this->a;
        int val2=obj.a;
        cout<<val2-val1<<endl;
        
    }
    void operator() (){
        cout<<"jahid()"<<endl;
        
    }
   
};

int main(){
    Sample s1,s2;
    s1.a=3;
    s2.a=5;
    s1+s2;
    s1();



    return 0;
}