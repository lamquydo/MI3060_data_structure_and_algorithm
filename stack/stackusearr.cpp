#include<bits/stdc++.h>
using namespace std;
class myStack{
private:
    int top;
    int capacity;
    int *arr;
public:
    myStack(int cap){
        this->top=0;
        this->capacity=cap;
        this->arr=new int[cap];
    }
    bool isFull(){
        return this->top==this->capacity;
    }
    bool isEmpty(){
        return this->top==0;
    }
    void push(int value){
        if(this->isFull()){
            cout<<"Stack is full";
            return;
        }
        this->arr[this->top]=value;
        this->top++;
    }
    void pop(){
        if(this->isEmpty()){
            cout<<"Stack is empty";
            return;
        }
        this->top--;
    }
    int getTop() {
        if(this->isEmpty()){
            return INT_MIN;
        }
        return this->arr[this->top-1];
    }
    int getLen(){
        return this->top;
    }

    void traversalStack(){
        if(this->isEmpty()) cout<<"Stack is empty";
        else
            for(int i=0;i<=this->top-1;i++)
                cout<<this->arr[i]<<" ";
    }
    ~myStack(){
      delete[] arr;
    }
};
int main()
{
    myStack s(5);
    s.push(32);
    s.push(21);
    s.pop();
    cout<<s.getLen()<<endl;
    s.traversalStack();

}
