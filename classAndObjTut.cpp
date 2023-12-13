
#include <iostream>
#include "class.cpp"
#include "string.h"
using namespace std;

class Sample
{
private:
    int age = 18;

public:
    char surname[6] = "khan";
    char *name;
    int grade = 12;
    static int time;//static keyword

    int getAge()
    { // getter(used to get private values)
        return age;
    }

    void setAge(int a)
    { // setter
        age = a;
    }
    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    void print()
    {
        cout << "name is " << this->name << endl;
    }

    Sample()
    { // default constructor
        cout << "constructor is called" << endl;
        name = new char[100];
    }
    Sample(int grade)
    { // parameterized constructor
        cout << "parameterized constructor is called" << endl;
        this->grade = grade; //"this" stores the addr of current opr. So it will be easy
        cout << "this is " << this << " and addr of grade is " << &grade << endl;
        cout << "val of grade is " << grade << endl;
    }
    Sample(Sample &temp)
    { // copy constructor (you can also write only Sample s2(s) without writing this )

        cout << "copy constructor is called" << endl;

        this->grade = temp.grade;
        cout << "this is " << this << " and addr of grade is " << &grade << endl;
        cout << "val of grade is " << grade << endl;

        // this below thing is deep copy
        // if it now written , then there will be shallow copy by default
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
    }
};

int Sample::time=5;//initialise the static keyword

int main()
{

    // static allocation

    A a;
    // Sample s;//calling default const
    // Sample s(99);//calling parameter const
    // s.setAge(20);         // setter is used to set a new value
    // int age = s.getAge(); // getter is used to get the value
    // cout << age << endl;  // so using getter , we can get private values also

    // dynamic allocation
    //  Sample *samp=new Sample;
    //  cout<<(*samp).surname<<endl;
    //  cout<<samp->surname<<endl;

    // copy const
    //  Sample s2(s); //if we only write this and not the copy function up there, then it is called default copy const

    // Sample s;
    // char name[6] = "jahid";
    // s.setName(name);
    // s.print();

    // Sample s2(s); // shallow copy
    // s2.print();

    // s.name[0] = 's';
    // s.print();
    // s2.print(); // name of s2 will also be changed, known as shallow copy

cout<<Sample::time<<endl;

    return 0;
}