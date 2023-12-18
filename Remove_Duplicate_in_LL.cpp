#include <bits/stdc++.h>
// #include <cmath>

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

    // ~Node()
    // { // it is not neccessary
    //     int val = this->data;
    //     if (this->next != NULL)
    //     {
    //         delete next;
    //         this->next = NULL;
    //     }
    //     cout << "mem is free for data = " << val << endl;
    // }
};
// insertion
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
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

void removeDuplicate(Node* &head)
{
    unordered_set<int> s;
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        int d = curr->data;
        // If this node is already present
        // in hashmap it means there is a cycle
        // (Because you will be encountering the
        // node for the second time).
        if (s.find(d) != s.end())
        {

            // return true;
            cout << "duplicate is " << d << endl;

            // prev = curr;
            // curr = curr->next;

            // if (curr->next == NULL)
            // { // if deleted node is last node
            //     prev->next = NULL;
            //     tail = prev;
            //     curr->next = NULL;
            //     delete curr;
            //     return;
            // }
            prev->next = curr->next;
            // curr->next = NULL;
            delete curr;
            // prev = curr;
            curr = prev->next;
        }

        // If we are seeing the node for
        // the first time, insert it in hash
        else{
            s.insert(d);
        prev = curr;
        curr = curr->next;
        cout<<"inserted "<<d<<endl;
        }
        cout<<"loop"<<endl;
    }

    // return false;
}

int main()
{
    Node *node1 = new Node(12);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node *head = node1;
    InsertAtHead(head, 12);
    print(head);
    InsertAtHead(head, 15);
    InsertAtHead(head, 15);
    print(head);
    InsertAtHead(head, 18);
    InsertAtHead(head, 18);
    InsertAtHead(head, 18);
    InsertAtHead(head, 18);
    print(head);
    InsertAtHead(head, 19);
    InsertAtHead(head, 19);
    print(head);
    removeDuplicate(head);
    print(head);

    return 0;
}