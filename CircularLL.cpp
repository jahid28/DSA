#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    { // it is not neccessary
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "mem is free for data = " << val << endl;
    }
};

// insertion
void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    { // empty list
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    { // non empty list
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
            /* code */
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, int val)
{
    if (tail == NULL)
    { // if deleted node is first node
        cout << "list is empty" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        // int count = 1;
        while (curr->data != val)
        {
            prev = curr;
            curr = curr->next;
            // count++;
        }

        prev->next = curr->next;

        if (curr == prev)
        { // if list has 1 ele
            tail = NULL;
        }

        else if (tail == curr)
        { // if list has >=2 ele
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&tail)
{
    Node *temp = tail;

if(tail==NULL){
    cout<<"list is empty"<<endl;
    return;
}

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 0, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    insertNode(tail, 5, 6);
    print(tail);
    deleteNode(tail, 3);
    print(tail);

    return 0;
}