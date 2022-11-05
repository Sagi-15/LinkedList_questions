/*
Time Complexity=O(n)
Space Complexity=O(n) ,worst case mei agar no duplicates then created linked list of same size as input
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
Node *removeDuplicates(Node *head){
    /*Idea yeh ki ek aur linked list bana where
        original linked list se data tabhi add kar when
        original linked list ka data>new linked list 
        ka last ie. unique element mile.*/
    Node *temp=head;//pointer joh actual linked list mei travel
    Node *newHead=new Node(head->data);
    Node *newTemp=newHead; //initially newLinked list ka last new ke head mei hi point karega
    /*Now iterate on each element of linked list*/
    while(temp!=NULL){
        if(newTemp->data<temp->data){
            newTemp->next=new Node(temp->data);
            newTemp=newTemp->next;
        }
        temp=temp->next;
    }
    return newHead;
}