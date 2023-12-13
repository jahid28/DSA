//part of polymorphism
#include <iostream>
using namespace std;

class Sample{
    public:
    void print(){
        cout<<"jahid"<<endl;
        
    }
    void print(string name){
        cout<<"jahid"<<name<<endl;

    }
    int print(int age){
        cout<<"jahid and age is "<<age<<endl;

    }
};

int main(){
    Sample s;
    s.print();
    s.print("khan");
    s.print(20);



    return 0;
}