#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // ~Node(){  //it is not neccessary
    //     int val=this->data;
    //     if(this->next!=NULL){
    //         delete next;
    //         this->next=NULL;
    //     }
    //     cout<<"mem is free for data = "<<val<<endl;
    // }
};
// insertion
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = tail->next; // or tail=temp
}
void InsertAtMid(Node *&head, Node *&tail, int pos, int d)
{

    if (pos == 1)
    { // only if we want to insert at 1st pos
        InsertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    { // only if we want to insert at last pos
        InsertAtTail(tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next = nodeToInsert;
    (temp->next)->prev = nodeToInsert;
}

void deleteNode(int pos, Node *&head, Node *&tail)
{
    if (pos == 1)
    { // if deleted node is first node
        Node *temp = head;
        head = head->next;
        (temp->next)->prev=NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (curr->next == NULL)
        { // if deleted node is last node
            prev->next = NULL;
            tail = prev;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
            return;
        }
        prev->next = curr->next;
        (curr->next)->prev = prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node *head = node1;
    Node *tail = node1;
    print(head);
    InsertAtHead(head, 14);
    print(head);
    InsertAtTail(tail, 8);
    print(head);
    InsertAtMid(head, tail, 3, 99);
    print(head);
    deleteNode(3,head,tail);
    print(head);
    InsertAtMid(head, tail, 1, 100);
    print(head);

    return 0;
}