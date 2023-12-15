#include <iostream>
#include <cmath>

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
            this->next = NULL;
        }
        cout << "mem is free for data = " << val << endl;
    }
};
// insertion
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
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
    temp->next = nodeToInsert;
}

void deleteNode(int pos, Node *&head, Node *&tail)
{
    if (pos == 1)
    { // if deleted node is first node
        Node *temp = head;
        head = head->next;
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
            delete curr;
            return;
        }
        prev->next = curr->next;
        curr->next = NULL;
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

void reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        // return head;
        cout << "empty list or only one element" << endl;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        // cout<<"pls"<<endl;
        // print(head);
    }
    // curr->next=prev;
    head = prev;
}

void findMiddleEle(Node *&head)
{
    Node *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    int mid = ceil(i / 2) + 1;
    // cout << mid << endl;

    Node *curr = head;
    for (int a = 1; a < mid; a++)
    {
        curr = curr->next;
    }
    cout << "mid ele is " << curr->data << endl;
}

int main()
{
    Node *node1 = new Node(12);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node *head = node1;
    Node *tail = node1;
    print(head);
    InsertAtHead(head, 14);
    print(head);
    InsertAtHead(head, 15);
    print(head);
    InsertAtTail(tail, 20);
    print(head);
    InsertAtMid(head, tail, 3, 99);
    print(head);
    InsertAtMid(head, tail, 1, 98);
    print(head);
    InsertAtMid(head, tail, 7, 100);
    print(head);
    deleteNode(7, head, tail);
    print(head);
    InsertAtTail(tail, 69);
    InsertAtTail(tail, 9);
    InsertAtTail(tail, 88);
    InsertAtTail(tail, 38);
    print(head);
    reverse(head);
    print(head);
    findMiddleEle(head);
    return 0;
}