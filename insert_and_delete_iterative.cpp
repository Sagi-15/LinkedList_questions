/*
Time Complexity=O(n)
Space Complexity=O(1) 
for both the functions
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
Node* insert(Node *head,int index,int data_of_new_node){
    /*3 cases (I)index=0,(II)index>length,(III)else*/
    /*Case I*/
    if(index==0){
        Node *newNode=new Node(data_of_new_node);
        newNode->next=head;
        head=newNode;
        return head;
    }
    /*Case II*/
    else if(index>=length(head)){
        //do nothing as invalid entry
        return head;
    }
    /*Case III*/
    else if(index>0 && index<length(head)){
        Node *newNode=new Node(data_of_new_node);
        /*created a new Node jisse insert karna hai*/
        int count=0;
        /*issi count variable ko index-1 times aage move krenge*/
        Node *temp=head; //temp ko hi move karenge as head ko change karna not good
        while(count<index-1){
            temp=temp->next;
            count++;
        }
        /*now, temp point on (i-1)th node so isko link to newNode*/
        newNode->next=temp->next;
        /*so now newNode points on ith previous node*/
        temp->next=newNode;
        /*so (i-1)th walla node point on newNode*/
        return head;
    }
}
Node* deleteNode(Node *head,int index){
    /*Again same 3 case as delete*/
    if(index>=length(head)){
        return head;
    }
    else if(index==0){
        /*baas head ko ek aage badha do so lost previous head address aur whi head return*/
        head=head->next;
        return head;
    }
    else if(index>0 && index<length(head)){
        Node *temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        /*now temp reached previous node of node to be deleted
            so now, uske next ko uske agle ke next mei point krwa do*/
        temp->next=(temp->next)->next;
        return head;
    }
}
int main(){
    Node *head=take_input();
    print(head);
    int index,data;
    cin>>index>>data;
    head=insert(head,index,data);
    print(head);
    int index_to_be_deleted;
    cin>>index_to_be_deleted;
    head=deleteNode(head,index_to_be_deleted);
    print(head);
}