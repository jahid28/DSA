//it is simply putting all DM and func in single unit
#include <iostream>
#include <vector>

using namespace std;

class Parent{
    private:
    int age=4;

    public:
    int num =8;

    int getAge(){
        return this->age;
    }
};

class Child:public Parent{
    public:
    string name;
    void print(){
        cout<<"hi"<<endl;
    }
};

int main(){

    Child c;
    cout<<c.getAge()<<endl;
    cout<<c.num<<endl;



    return 0;
}