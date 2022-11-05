/*
Time Complexity=O(n)
Space Complexity=O(n)
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
Node* insertNode(Node *head,int index,int data){
    if(index<length(head) or index<0){
        /*Base case: agar head=NULL, then kuch karna hi nahi*/
        if(head==NULL){
            return head;
        }
        /*Small Calculation kar 
            index=0 then kaam kar as head handle karna hamara kaam*/
        if(index==0){
            Node *newNode=new Node(data);
            newNode->next=head;
            head=newNode;
            return head;
        }
        /*Nahi toh recursion call
            head->next=recursive call as aage ka linked
            list recursion sahi karke laayega.*/
        else{
            head->next=insertNode(head->next,index-1,data);//return joh bhi head edit karke recursion laake dega.
            return head;
        }
    }
}
Node* deleteNodeRec(Node *head,int index){
    if(head==NULL || index<0){
        return head;
    }
    /*our part when index=0 tab head update baas baki recursion*/
    if(index==0){
        head=head->next;
    }
    else{
        /*Aage walle part se deleteNodeRec karke lao aur linked list ko
            de do*/
        head->next=deleteNodeRec(head->next,index-1);
        return head;
    }
}
int main(){
    Node *head=take_input();
    print(head);
    head=insertNode(head,3,5);
    print(head);
    head=deleteNodeRec(head,5);
    print(head);
}