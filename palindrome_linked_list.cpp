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
    /*Base case agar koi node nahi/1 hi node ho then palindrome hi*/
    if(head==NULL or head->next==NULL){
        return -1;
    }
    /*Now our small calculation head->data==last->data or not*/
    Node *last=head;
    //ab isko linked list ke last tak le jaa
    while(last->next!=NULL){
        last=last->next;
    }
    //cout<<last->data;
    /*Now last on actual last of linked list*/
    bool smallCalculation=(head->data==last->data);
    //cout<<smallCalculation;
    /*
    now recursion call so uske liye naya smaller linked
        list bana with start and end element gayab*/
    Node *head_of_smaller_linked_list=new Node((head->next)->data); //as head of smaller will point on head->nxt only
    //cout<<head_of_smaller_linked_list->data;
    Node *temp=head; //temp to store data of last node in original linked list
    Node *pointer_to_last_node_of_new_linked_List=head_of_smaller_linked_list; // to insert new datas
    while((temp->next)->next!=NULL){
        Node *newNode=new Node((temp->next)->data);
        pointer_to_last_node_of_new_linked_List->next=newNode;
        pointer_to_last_node_of_new_linked_List=newNode;
        //cout<<pointer_to_last_node_of_new_linked_List->data<<" ";
        temp=temp->next;
    }
    
    bool ansReturnedByRecursion=isPalindrome(head_of_smaller_linked_list);
    if(smallCalculation==true && ansReturnedByRecursion==true){
        return true;
    }
    else{
        return false;
    }
    
}
int main(){
    Node *head=take_input();
    print(head);
    cout<<isPalindrome(head);
}