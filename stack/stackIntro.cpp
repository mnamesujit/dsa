#include<iostream>
using namespace std;

class Stack {
    // properties
    public:
        int top;
        int *arr;
        int size;

    // behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int elem){
        if(size - top > 1){
            top++;
            arr[top] = elem;
        }
        else{
            cout << "StackOverflow" << endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout << "StackUnderflow" << endl;
        }
    }

    int peek(){
        if(top >=0){
            return arr[top];
        }
        else{
            cout <<"Stack is Empty" <<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top ==  -1)
            return true;
        else
            return false;
    }

};

int main(){
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.peek()<<endl;    

    st.pop();
    cout << st.peek()<<endl;    
    
    st.pop();
    cout << st.peek()<<endl;    
    
    st.pop();
    cout << st.peek()<<endl;

    if(st.isEmpty()){
        cout << "Stack is Empty" <<endl;
    }
    else{
        cout << "Stack is not Empty";
    }
    
    return 0;
}