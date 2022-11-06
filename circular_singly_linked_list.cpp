#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};
Node* take_input(){
    Node *head=NULL;
    Node *tail=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    /*Now linked list over when data null so tail->next=head*/
    if(tail!=NULL){
        //to handle empty linked list case
        tail->next=head;
    }
    return head;
}
void print(Node *head){
    cout<<head->data<<" ";
    Node *temp=head->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
class Pair{
    public:
        Node *head;
        Node *tail;
};
class CircularSinglyLinkedList{
    private:
        Node *head;//stores address of head
        Node *tail;//stores address of tail
        //constructor
    public:
        CircularSinglyLinkedList(){
            /*Initialised head and tail with null*/
            this->head=NULL;
            this->tail=NULL;
        }
        Pair take_input(){
            /*Pair banaya taaki outside class can access both head and tail*/
            Node *head=NULL;
            Node *tail=NULL;
            int data;
            cin>>data;
            while(data!=-1){
                Node *newNode=new Node(data);
                if(head==NULL){
                    head=newNode;
                    tail=newNode;
                }
                else{
                    tail->next=newNode;
                    tail=newNode;
                }
                cin>>data;
            }
            /*Now linked list over when data null so tail->next=head*/
            if(tail!=NULL){
                //to handle empty linked list case
                tail->next=head;
            }
            Pair answer;
            answer.head=head;
            answer.tail=tail;
            this->head=head;
            this->tail=tail;
            return answer;
        }
        void print(){
            cout<<(this->head)->data<<" ";
            Node *temp=(this->head)->next;
            while(temp!=head){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        int length(){
            int count=1;
            Node *temp=(this->head)->next;
            while(temp!=head){
                count++;
                temp=temp->next;
            }
            return count;
        }
        void insert(int index,int data){
            if(index==0){
                /*matlab insert at 1st position ie. head mei yeh*/
                Node *newNode=new Node(data);
                newNode->next=this->head;
                this->head=newNode;
                /*now tail->next mei woh*/
                (this->tail)->next=this->head;
            }
            else if(index<length()){
                /*index-1 aage move karo*/
                Node *temp=this->head;
                for(int i=0;i<index-1;i++){
                    temp=temp->next;
                }
                Node *newNode=new Node(data);
                newNode->next=temp->next;
                temp->next=newNode;
            }
        }
        void Delete(int index){
            if(index==0){
                Node *temp=this->head;
                this->head=(this->head)->next;
                (this->tail)->next=this->head;
                delete temp;
            }
            else{
                Node *temp=this->head;
                for(int i=0;i<index-1;i++){
                    temp=temp->next;
                }
                temp->next=(temp->next)->next;
            }
        }
};
int main(){
    CircularSinglyLinkedList circularLL;
    Pair LinkedList=circularLL.take_input();
    Node *head=LinkedList.head;
    Node *tail=LinkedList.tail;
    cout<<head->data<<" "<<tail->data<<endl;
    circularLL.print();
    cout<<"Length : "<<circularLL.length()<<endl;
    circularLL.insert(2,7);
    circularLL.insert(0,9);
    circularLL.print();
    circularLL.Delete(3);
    circularLL.print();
    circularLL.Delete(0);
    circularLL.print();
}