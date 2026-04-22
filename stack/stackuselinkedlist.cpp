#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int value){
        this->data=value;
        this->next=nullptr;
    }
};
class linkedList{
private:
    Node* head;
    int len;
public:
    linkedList(){
        this->head=nullptr;
        this->len=0;
    }
    Node* getHead(){
         return this->head;
    }

    int getLen(){
        return this->len;
    }

    bool isEmpty(){
        if(this->head==nullptr){
            return true;
        }
        else return false;
    }

    void traversalList(){
        if(this->head==nullptr) cout<<"Linked List is empty";
        else{
            Node* temp=this->head;
            while(temp!=nullptr){
                cout<<temp->data;
                if(temp->next!=nullptr) cout<<"->";
                temp=temp->next;

            }
        }
    }
    void appendFirst(int value){
        Node* temp=new Node(value);
        temp->next=this->head;
        this->head=temp;
        this->len++;
    }

    void appendLast(int value){
        if(this->isEmpty()){
            this->appendFirst(value);
            return;
        }
        Node* temp= this->head;
        Node* tol=new Node(value);
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=tol;
        this->len++;
    }

    //Gia su nguoi dung nhap pos hop le
    void appendPos(int pos, int value){
        if(pos<1||pos>this->len+1){
            cout<<"Pos is invalid"<<endl;
            return;
        }
        if(pos==1){
            this->appendFirst(value);
            return;
        }
        Node* tol=new Node(value);
        Node* temp=this->head;
        for(int i=2;i<=pos-1;i++){
            temp=temp->next;
        }
        tol->next=temp->next;
        temp->next=tol;
        this->len++;
    }

    void removeFirst(){
        if(this->isEmpty()){
            cout<<"List is empty";
            return;
        }
        Node* temp=this->head;
        this->head=this->head->next;
        delete temp;
        this->len--;
    }

    void removeLast(){
        if(this->isEmpty()){
            cout<<"List is empty";
            return;
        }
        Node* temp=this->head;
        if(temp->next==nullptr){
            this->removeFirst();
            return;
        }
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        Node* tol=temp->next;
        temp->next=nullptr;
        delete tol;
        this->len--;
    }

    void removePos(int pos){
        if(pos<1||pos>this->len){
            cout<<"Pos is invalid";
            return;
        }
        if(pos==1){
            this->removeFirst();
            return;
        }
        if(pos==this->len){
            this->removeLast();
            return;
        }
        Node* temp=this->head;
        for(int i=2;i<pos;i++){
            temp=temp->next;
        }
        Node* tol=temp->next;
        temp->next=temp->next->next;
        delete tol;
        this->len--;
    }

    ~linkedList(){
        Node* temp;
        while(this->head!=nullptr){
            temp=this->head;
            this->head=this->head->next;
            delete temp;
        }
        this->len=0;
    }
};


class myStack{
private:
    linkedList myList;

public:
    myStack(){
    }

    bool isEmpty(){
        return this->myList.getLen()==0;
    }

    void push(int value){
        this->myList.appendFirst(value);
    }

    void pop(){
        if(this->isEmpty()){
            cout<<"Stack is empty";
            return;
        }
        this->myList.removeFirst();
    }

    int top(){
        if(this->isEmpty()){
            cout<<"Stack is empty";
            return INT_MIN;
        }
        Node* temp=this->myList.getHead();
        return temp->data;
    }
    int len(){
        return this->myList.getLen();
    }
    void traversal(){
        if(this->isEmpty()){
            cout<<"Stack is empty";
            return;
        }
        this->myList.traversalList();
    }
};

int main()
{
    myStack s;
    s.push(333);
    s.push(32);
    s.push(15);

    cout<<s.len()<<endl;
    s.traversal();

    return 0;

}
