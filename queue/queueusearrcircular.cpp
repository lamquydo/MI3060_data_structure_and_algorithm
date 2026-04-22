#include<bits/stdc++.h>
using namespace std;
class myQueue{
private:
    int *arr;
    int head;
    int tail;
    int capacity;
public:
    myQueue(int len){
        this->head=0;
        this->tail=0;
        this->capacity=len;
        this->arr=new int[len];
    }

    bool isFull(){
        return (this->tail+1)%this->capacity==this->head;
    }

    bool isEmpty(){
        return this->head==this->tail;
    }

    void enQueue(int value){
        if(this->isFull()){
            cout<<"Queue is Full ";
            return;
        }
        this->arr[this->tail]=value;
        this->tail=(this->tail+1)%this->capacity;
    }
    void deQueue(){
        if(this->isEmpty()){
            cout<<"Queue is empty ";
            return;
        }
        this->head=(this->head+1)%this->capacity;
    }

    int getTop(){
        if(this->isEmpty()){
            return INT_MIN;
        }
        return this->arr[this->head];
    }

    int getRear(){
        if(this->isEmpty()){
            return INT_MIN;
        }
        int rearIndex=(this->tail-1+this->capacity)%this->capacity;
        return this->arr[rearIndex];

    }
    void traversal(){
        int temp=this->head;
        while(temp!=this->tail){
            cout<<this->arr[temp]<<" ";
            temp=(temp+1)%this->capacity;
        }
        cout<<endl;
    }
    ~myQueue(){
        delete[] arr;
    }
};
int main() {

    myQueue q(333);
    q.enQueue(32);
    cout<<q.getRear()<<" ";
    cout<<q.getTop();
    return 0;
}
