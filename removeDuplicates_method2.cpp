/*
Time Complexity=O(n)
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
Node* removeDuplicates(Node *head){
    /*See copy firstly took p1 and p2 at head*/
    Node *p1=head;
    Node *p2=head;
    while(p2!=NULL){
        /*tab tak p2 ko aage jab tak p2 not null ie.
        poora linked list not scanned.*/
        while(p2!=NULL && p2->data==p1->data){
            //p2!=NULL case bhi consider kar as aisa possible ki har case ke liye p1==p2 data ie. eg->5 5 5 5 5 5 5
            p2=p2->next;
        }
        /*Now 2 cases agar p2 null ban gaya =>2 cases p1 in head 
        ie. all elements same then head->next=NULL aur 
        ek hi element in head then*/
        if(p2==NULL && p1==head){
            head->next=NULL;
            return head;
        }
        else if(p2==NULL && p1!=head){
            /*matlab aisa case 1->2->2->3->3->3->null
            aur 3 tak pahuch p2 then null ban ja but p1 on 3 also 
            so p1->next=NULL*/
            p1->next=NULL;
            return head;
        }
        else if(p2!=NULL){
            /*matlab p2 kahi beech mei ruka where
            p1 ke data se badha value in p2 
            so p1->next=p2 kar de*/
            p1->next=p2;
            p1=p2;
        }
    }
    return head; 
    /*considering case agar head=null then while
    mei ghusega hi nahi so head hi return 
    also line 82 walle else if mei tabhi return head when p2 nei
    poora linked list mei traverse kar liya ho.*/
}