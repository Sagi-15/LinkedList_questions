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
bool allEven(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        if((temp->data)%2!=0){
            return false;
        }
        temp=temp->next;
    }
    return true;
}
bool allOdd(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        if((temp->data)%2==0){
            return false;
        }
        temp=temp->next;
    }
    return true;
}
Node *evenAfterOdd(Node *head){
    /*Handling boundary conditions 1st*/
    if(head==NULL or head->next==NULL){
        return head;
    }
    if(allEven(head)){
        return head;
    }
    else if(allOdd(head)){
        return head;
    }
    /*Agar saare elements odd when */
    Node *lastEven=NULL;
    Node *lastOdd=NULL;
    Node *headEven=NULL;
    Node *headOdd=NULL;
    if((head->data)%2==0){
        headEven=head;
        lastEven=head;
    }
    else{
        headOdd=head;
        lastOdd=head;
    }
    Node *temp=head->next;
    /*to initialise head odd and head even*/
    while(temp!=NULL && !(lastEven==NULL && lastOdd==NULL)){
        /*if else below se head of odd and even set kar rhe */
        if(lastOdd==NULL && (temp->data)%2==1){
            lastOdd=temp;
            headOdd=temp;
        }
        else if(lastEven==NULL && (temp->data)%2==0){
            lastEven=temp;
            headEven=temp;
        }
        temp=temp->next;
    }
    /*Now proceeding with creation of even and odd list furthur*/
    temp=head->next;
    while(temp!=NULL){
        if((temp->data)%2==0){
            Node *previous_temp=temp; // so that lastEven previous temp pe point kar ske
            temp=temp->next;//so that address not loose
            lastEven->next=previous_temp;
            lastEven=previous_temp;
        }
        else if((temp->data)%2!=0){
            Node *previous_temp=temp;
            temp=temp->next;
            lastOdd->next=previous_temp;
            lastOdd=previous_temp;
        }
    }
    /*now have odd and even list separated*/
    lastOdd->next=headEven;
    lastEven->next=NULL;
    return headOdd;
}
int main(){
    Node *head=take_input();
    print(head);
    head=evenAfterOdd(head);
    print(head);
}