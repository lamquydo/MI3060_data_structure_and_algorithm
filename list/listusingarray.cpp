#include<bits/stdc++.h>
using namespace std;
class myList{
private:
    int *arr;
    int len;
    int capacity;

public:
    myList(int n){
        this->arr=new int[n];
        this->len=0;
        this->capacity=n;
    }
    void traversalList(){
        for(int i=0;i<this->len;i++){
            cout<<this->arr[i]<<" ";
        }
        cout<<endl;
    }
    bool isEmpty(){
        return this->len==0;
    }

    //O(n)
    void appendLast(int value){
        if(this->len<this->capacity){
            this->arr[this->len]=value;
            this->len++;
        }
        else{
            int *newArr= new int[2*this->capacity];
            for(int i=0;i<this->len;i++){
                newArr[i]=this->arr[i];
            }
            delete[] this->arr;
            this->arr=newArr;
            this->arr[this->len]=value;
            this->len++;
            this->capacity*=2;
        }
    }
    //O(n)
    void insertPos(int pos, int value){
        if(pos<=0||pos>this->len+1) cout<<"Pos is invalid";
        else{
            if(this->len>=this->capacity){
                int *newArr=new int[2*this->capacity];
                for(int i=0;i<pos-1;i++){
                    newArr[i]=this->arr[i];
                }
                newArr[pos-1]=value;
                for(int i=pos;i<=this->len;i++){
                        newArr[i]=this->arr[i-1];
                }

                delete[] this->arr;
                this->arr=newArr;
                this->len++;
                this->capacity*=2;

            }
            else{
                for(int i=this->len;i>=pos;i--){
                    this->arr[i]=this->arr[i-1];
                }
                this->arr[pos-1]=value;
                this->len++;
            }

        }
    }

    //O(n)
    void removePos(int pos){
       if(pos<=0||pos>this->len){
            cout<<"Pos is invalid";
            return;
       }

       if(this->isEmpty()){
            cout<<"List is empty";
            return;
       }

        for(int i=pos-1;i<this->len-1;i++){
            this->arr[i]=this->arr[i+1];
        }
        this->len--;

    }

    //O(1)
    int getValue(int pos){
        if(pos<=0||pos>this->len) return INT_MIN;
        else{
            return this->arr[pos-1];
        }
    }

    //O(1)
    int getLen(){
        return this->len;
    }
    ~myList(){
        delete[] arr;
    }
};
int main(){
    myList p(5);

    p.appendLast(3);
    p.appendLast(19);
    p.appendLast(3939);
    p.removePos(2);
    p.traversalList();
    p.insertPos(2,289);
    p.insertPos(10,2323);
    p.traversalList();
    return 0;
}
