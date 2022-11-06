/*
Time Complexity=O(n)
Space Complexity=O(1)
*/
#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        //constructor
        Node(int data){
            this->data=data;
        }
};
Node* take_input(){
    int data;
    cin>>data;
    //data mei first element
    Node *head=NULL;
    Node *last=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            //matlab 1st element
            head=newNode;
            last=newNode;
        }
        else{
            //last se inserted new node aur last ko at naya node hi took so that next data enter
            last->next=newNode;
            last=newNode;
        }
        cin>>data;
    }
}
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node *reverseLinkedList(Node *head) {
  /*three pointer approach*/
  if(head==NULL or head->next==NULL){
	  return head;
  }
  Node *r = head->next;
  Node *q = head;
  Node *p = NULL;
  while (q != NULL) {
    q->next = p;
    p = q;
    q = r; // here at last q will become null as r already null
    if (r != NULL) {
      /*r agar null tab next nahi kar skte*/
      r = r->next;
    }
  }
  head = p;
  return head;
}