/*
Time Complexity=O(n)
Space Complexity=O(n)
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
class Pair{
    public:
        Node *head;
        Node *tail;
};
Pair reverseRecursive(Node *head){
    /*
    //Base case: agar 0 nodes or 1 nodes => already reversed so head hi return
    if(head==NULL or head->next==NULL){
        return head;
    }
    //Now 1->2->3->4 pe =>1 pe hum kaam aur 2->3->4 pe recursion kaam karke
    //answer laayega
    //Assume ki recursion 4->3->2->null lekar aayega hamare liye aur head on 4
    Node* smallOutput=reverseRecursive(head->next);
    //so small output mei head
    //But tail need so 2 cheeze function return ek head aur ek tail so pair bana
    */
    /*Now, pair par kaam karenge*/
    /*Base case=>agar 0 or 1 element then pair return head and tail both point on head 
    as null head then head aur tail of ans bhi null aur 1 element 
    matlab head aur tail dono point on that single element.*/
    if(head==NULL or head->next==NULL){
        Pair answer;
        answer.head=head;
        answer.tail=head;
        return answer;
    }    
    /*Now recursion call where Pair mei small output return
    let call on 2->3->4->null then return hoga 
    4->3->2->null walli linked list aur head->&4 and tail->&2*/
    Pair smallOutput=reverseRecursive(head->next);
    /*so smallOutput.head mei address of 4 aur smallOutput.tail mei address of 2*/
    /*Now head of original ko as tail->next*/
    smallOutput.tail->next=head;
    /*aur 1->null kar so head->next=NULL*/
    head->next=NULL;
    smallOutput.tail=head;
    Pair answer;
    /*Now smallOutput ka head 4 wahi reversed ka bhi head*/
    answer.head=smallOutput.head;
    /*Aur answer ka tail is small output ka hi tail*/
    answer.tail=smallOutput.tail;
    return answer;
}
/*But hame Node* type answer chahiye tha not pair type so another function below*/
Node *reverseLinkedListRec(Node *head){
    /*Only head recieved from above function return*/
    return reverseRecursive(head).head;
}