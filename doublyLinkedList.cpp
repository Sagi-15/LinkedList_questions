#include <iostream>
using namespace std;
class Node{
    public:
        Node *previous;
        int data;
        Node *next;
        Node(int data){
            this->previous=NULL;
            this->data=data;
            this->next=NULL;
        }
};
class Pair{
    public:
        Node *head;
        Node *tail;
};
class DoublyLinkedList{
    private:
        Node *head;
        Node *tail;
    public:
        DoublyLinkedList(){
            this->head=NULL;
            this->tail=NULL;
        }
        Pair take_input(){
            Node *head=NULL;
            Node *tail=NULL;
            Node *previous=NULL;
            int data;
            cin>>data;
            while(data!=-1){
                Node *newNode=new Node(data);
                if(head==NULL){
                    /*matlab no elements till now*/
                    head=newNode;
                    tail=newNode;
                    /*Below 2 lines constructor aise hi kar de but still do*/
                    newNode->next=NULL;
                    newNode->previous=NULL;
                }
                else{
                    tail->next=newNode;
                    previous=tail; //purane tail mei previous daal
                    tail=newNode;
                    newNode->previous=previous;
                    newNode->next=NULL;
                }
                cin>>data;
            }
            Pair answer;
            answer.head=head;
            answer.tail=tail;
            this->head=head;
            this->tail=tail;
            return answer;
        }
        void print(){
            Node *temp=this->head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        int length(){
            Node *temp=this->head;
            int count=0;
            while(temp!=NULL){
                count++;
                temp=temp->next;
            }
            return count;
        }
        void insert(int index,int data){
            Node *newNode=new Node(data);
            if(index==0){
                (this->head)->previous=newNode;
                newNode->next=this->head;
                this->head=newNode;
            }
            else if(index<length()){
                Node *temp=this->head;
                for(int i=0;i<index-1;i++){
                    temp=temp->next;
                }
                (temp->next)->previous=newNode;
                newNode->next=temp->next;
                temp->next=newNode;
                newNode->previous=temp;
            }
        }
        void Delete(int index){
            if(index==0){
                Node *temp=this->head;
                this->head=(this->head)->next;
                (this->head)->previous=NULL;
                delete temp;
            }
            else if(index<length()){
                Node *temp=this->head;
                for(int i=0;i<index-1;i++){
                    temp=temp->next;
                }
                Node *node_to_be_deleted=temp->next;
                temp->next=(temp->next)->next;
                ((temp->next)->next)->previous=temp;
                delete node_to_be_deleted;
            }
        }
};
int main(){
    DoublyLinkedList doublyLL;
    Pair p=doublyLL.take_input();
    Node *head=p.head;
    Node *tail=p.tail;
    cout<<"Length : "<<doublyLL.length()<<endl;
    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;
    doublyLL.print();
    doublyLL.insert(3,7);
    doublyLL.print();
    doublyLL.insert(0,5);
    doublyLL.print();
    doublyLL.Delete(5);
    doublyLL.print();
    doublyLL.Delete(0);
    doublyLL.print();
}