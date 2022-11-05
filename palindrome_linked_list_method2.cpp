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
Node *returnReverse(Node *head){
    /*returns the head of the reversed version of original linked list*/
    /*three pointer approach*/
    Node *r=head->next;
    Node *q=head;
    Node *p=NULL;
    while(q!=NULL){
        q->next=p;
        p=q;
        q=r;//here at last q will become null as r already null
        if(r!=NULL){
            /*r agar null tab next nahi kar skte*/
            r=r->next;
        }
    }
    head=p;
    return head;
}
int length(Node *head){
    /*Clearly temp lo at head next karte jao
        tab tak jab tak temp null na ho
        ie. linked list not khatam aur count++ krte jao*/
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
bool isPalindrome(Node *head){
    /*if linked list is empty or only one element is there 
    then it is palindrome*/
    if(head==NULL || head->next==NULL){
        return true;
    }
    int length_of_linked_list=length(head);
    int mid=(length_of_linked_list/2)-1;
    /*For even number of elements
    eg. 1->2->2->1 mid will go till first 2
    then head2 will ppint on 2nd 2
    so we got 2 linked lists 1->2 and 2->1
    now reversing the second linked list and comparing with first
    if equal then palindrome
    */
    /*
    For odd number of elements 
    eg. 1->2->3->2->1 mid will go till 2
    then head2 will point on 2->next->next ie 2nd 2
    so we again got 2 linked lists
    1->2 and 2->1 reversing the 2nd and 
    comparing if equal will tell us if the linked list is palindrome
    or not.
    */
    Node *mid_pointer=head;
    Node *head2=NULL;
    for(int i=0;i<mid;i++){
        mid_pointer=mid_pointer->next;
    }
    if(length_of_linked_list%2==0){
        /*ie.even number of elements*/
        //Now mid_pointer point on middle element
        head2=mid_pointer->next;
        mid_pointer->next=NULL;
    }
    else{
        head2=(mid_pointer->next)->next;
        mid_pointer->next=NULL;
        head2=returnReverse(head2);
    }
    while(head!=NULL){
        if(head->data!=head2->data){
            return false;
        }
        head=head->next;
        head2=head2->next;
    }
    return true;
}
int main(){
    Node *head=take_input();
    cout<<isPalindrome(head);
}