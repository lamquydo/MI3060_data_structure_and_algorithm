#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int value){
        this->data=value;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
class doubleLinkedList{
private:
    Node* head;
    Node* tail;
    int len;
public:
    doubleLinkedList(){
        this->head=nullptr;
        this->tail=nullptr;
        this->len=0;
    }
    int getLen(){
        return this->len;
    }
    int getHead(){
        if(this->isEmpty()){
            cout<<"List is empty";
            return INT_MIN;
        }
        return this->head->data;
    }

    int getTail(){
        if(this->isEmpty()){
            cout<<"List is empty";
            return INT_MIN;
        }
        return this->tail->data;
    }


    bool isEmpty(){
        return this->head==nullptr;
    }
    void appendFirst(int value){
        Node* temp=new Node(value);
        if(this->isEmpty()){
            this->head=temp;
            this->tail=temp;
            this->len++;
            return;
        }
        temp->next=this->head;
        this->head->prev=temp;
        this->head=temp;
        this->len++;
    }
    void appendLast(int value){
        Node* temp=new Node(value);
        if(this->isEmpty()){
            this->head=temp;
            this->tail=temp;
            this->len++;
            return;
        }
        this->tail->next=temp;
        temp->prev=this->tail;
        this->tail=temp;
        this->len++;
    }
    void appendPos(int pos,int value){
        if(pos<1||pos>this->len+1){
            cout<<"Pos is invalid";
            return;
        }
        if(pos==1){
            this->appendFirst(value);
            return;
        }
        if(pos==this->len+1){
            this->appendLast(value);
            return;
        }
        Node* temp=this->head;
        Node* tol=new Node(value);
        for(int i=2;i<pos;i++){
            temp=temp->next;
        }
        tol->next=temp->next;
        temp->next->prev=tol;
        tol->prev=temp;
        temp->next=tol;
        this->len++;
    }
    void removeFirst(){
        if(this->isEmpty()){
            cout<<"List is empty";
            return;
        }
        if(this->len==1){
            this->head=nullptr;
            this->tail=nullptr;
            this->len=0;
            return;
        }
        Node* temp=this->head;
        this->head=this->head->next;
        this->head->prev=nullptr;
        delete temp;
        this->len--;
    }
    void removeLast(){
        if(this->isEmpty()){
            cout<<"List is empty";
            return ;
        }
        if(this->len==1){
            this->head=nullptr;
            this->tail=nullptr;
            this->len=0;
            return;
        }
        Node* temp= this->tail;
        this->tail=this->tail->prev;
        this->tail->next=nullptr;
        delete temp;
        this->len--;
    }
    void removePos(int pos) {
        if (pos < 1 || pos > this->len) {
            cout << "Pos is invalid" << endl;
            return;
        }
        if (pos == 1) {
            this->removeFirst();
            return;
        }
        if (pos == this->len) {
            this->removeLast();
            return;
        }
        Node* cur = this->head;
        for (int i = 2; i <= pos; i++) {
            cur = cur->next;
        }
        cur->next->prev=cur->prev;
        cur->prev->next=cur->next;
        delete cur;
        this->len--;

    }
    void traversalList(){
        Node* temp=this->head;
        if(temp==nullptr)
            cout<<"List is empty";
        while(temp!=nullptr){
            cout<<temp->data;
            if(temp->next!=nullptr)
                cout<<"<->";
            temp=temp->next;
        }
        cout<<endl;
    }
     ~doubleLinkedList(){
        while(this->head!=nullptr){
            Node* temp=this->head;
            this->head=this->head->next;
            delete temp;
        }
        this->tail=nullptr;
        this->len=0;
    }
};

class myQueue{
private:
    doubleLinkedList myList;
public:
    myQueue(){}
    bool isEmpty(){
        return this->myList.isEmpty();
    }
    void enQueue(int value){
        this->myList.appendLast(value);
    }
    void deQueue(){
        if(this->isEmpty()){
            cout<<"Queue is empty";
            return;
        }
        this->myList.removeFirst();
    }
    int getFront(){
        if(this->isEmpty()){
            cout<<"Queue is empty";
            return INT_MIN;
        }
         return this->myList.getHead();
    }
    int getRear(){
        if(this->isEmpty()){
            cout<<"Queue is empty";
            return INT_MIN;
        }
        return this->myList.getTail();
    }
};
int main(){
    myQueue q;
    q.enQueue(32);
    cout<<q.getFront();

}

