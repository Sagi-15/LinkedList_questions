/*
Time Complexity=O(m+n) ,where m=number of elements in 1st linked list and n is number of elements in 2nd linked list
Space Complexity=O(1)
*/
#include <iostream>
using namespace std;
/*Pehle Node class bana le rahe.
    Uska data members har jagah use
    outside class so public make*/
class Node{
    public:
        int data; //data of the node/element
        Node *next; //Pointer to next node or element in linked list
        //Constructor
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};
/*Will take elements as an input from user and return head of 
    linked list*/
Node* take_input(){
    Node *head=NULL; //points on first element
    Node *tail=NULL; //points on last element
    int data;
    cin>>data; //pehli element ki data input leli
    while(data!=-1){
        //agar data=-1 input kiya user nei tab terminate
        /*made a new node with the data inputed by user*/
        Node *newNode=new Node(data);
        if(head==NULL){
            /*matlab abhi Linked list empty so first node 
                aaya ab newNode mei so, head aur tail ko
                ussi par point karao*/
            head=newNode;
            tail=newNode;
        }
        else{
            /*else tab run when empty nahi linked list 
                so, tail ke next se point karwao on newNode
                as last node need to be connected to newNode,*/
            tail->next=newNode;
            /*as once naya node inserted wahi last 
                node hoga so tail ko point on new as tail point on last*/
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    /*head stores address of first node so usko use 
        karke print karenge baaki nodes.*/
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    /*Boundary conditions*/
	if(head1==NULL and head2!=NULL){
		return head2;
	}
	else if(head2==NULL and head1!=NULL){
		return head1;
	}
	else if(head1==NULL and head2==NULL){
		return NULL;
	}
    Node *temp1=head1;
    Node *temp2=head2;
    Node *finalHead=NULL;
    Node *finalTail=NULL;
    /*initialisation of final head and tail*/
    if(head1->data<head2->data){
        finalHead=finalTail=head1;
        temp1=temp1->next;
    }
    else if(head1->data>head2->data){
        finalHead=finalTail=head2;
        temp2=temp2->next;
    }
    /*Agar 1->3->4->null and 1->5->8->null then final head on 1 aur dono move aage*/
    else if(head1->data==head2->data){
        finalHead=finalTail=head1;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    /*Now loop start for dono mei processing simulataneously*/
    while(temp1!=NULL and temp2!=NULL){
        if(temp1->data<temp2->data){
            finalTail->next=temp1;
            finalTail=finalTail->next;
            temp1=temp1->next;
        }
        else if(temp1->data>temp2->data){
            finalTail->next=temp2;
            finalTail=finalTail->next;
            temp2=temp2->next;
        }
        else if(temp1->data==temp2->data){
            finalTail->next=temp1;
            finalTail=finalTail->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    /*Now koi ek linked list khatam so next linked list onwards poora*/
    if(temp1==NULL){
        /*matlab temp2 bacha hua*/
        finalTail->next=temp2;
    }
    else if(temp2==NULL){
        finalTail->next=temp1;
    }
    return finalHead;
}