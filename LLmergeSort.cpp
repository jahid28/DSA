#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }

};

void print(Node* &head){
    Node *temp=head;
while(temp!=NULL){
    cout<<temp->data<<endl;
    temp=temp->next;
}
}

Node* findMid(Node*head){
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node*merge(Node*&left, Node*&right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }

    Node* ans=new Node(-1);
    Node* temp=ans;

    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }

    while(left!=NULL){

            temp->next=left;
            temp=left;
            left=left->next;
    }
    while(right!=NULL){

            temp->next=right;
            temp=right;
            right=right->next;
    }
    ans=ans->next;
    return ans;
}

Node*mergeSort(Node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node*mid=findMid(head);
    Node*left=head;
    Node*right=mid->next;
    mid->next=NULL;

    left=mergeSort(left);
    right=mergeSort(right);

    Node*result=merge(left,right);
    // int a=99;

    return result;
}

int main(){
    Node *head=new Node(88);
    Node *node2=new Node(10);
    Node *node3=new Node(3);
    Node *node4=new Node(15);
    Node *node5=new Node(66);
    
    head->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=NULL;
    print(head);

    Node*newHead=mergeSort(head);

cout<<"after sorting"<<endl;
    print(newHead);

    
    // Node * head=node1;

    return 0;
}