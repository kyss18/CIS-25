#include<iostream>
using namespace std;
typedef struct node{
    int data;
    node *next;
};
 node *createNode(int data){
    node *temp= new node();
    temp->data=data;
    temp->next=nullptr;
    return temp;
 }
//  node *addTail(node *head,int data){
//    // node *newNode=createNode(data);
//     if (head== nullptr)
//     {
//         return createNode(data);
        
//     }
//         head->next= addTail(head->next,data);
//         return head;
//  }
void addTail(node *(&head),int data){
    node *newNode=createNode(data);
    if (head== nullptr)
        head=newNode;
    else{
        addTail(head->next,data);
    }
}
void addHead(node *&head,int data){
    node *newNode=createNode(data);
    if (head== nullptr)
        head=newNode;
    else{
        newNode->next=head;
        head=newNode;
    }
}
 void printlist(node *head){
    for (node *k=head;k!= nullptr;k=k->next){
        cout<<k->data;
    }
 }
 void sum(int *a){
    int b=10;
    *a=b;
 }
int main(){
    node *s=nullptr;
    addHead(s,10);
    addHead(s,11);
    addHead(s,12);
    addHead(s,13);
    //s=addTail(s,14);
    printlist(s);
    // int a=0;
    // sum(&a);
    // cout<<a;
}