#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    // Destructor
    ~Node() {
        int val= this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory if free for Node: "<<val;
    }

};

void insertNode(){
    
}

int main(){
    // There is no need to create tail pointer for cirCularLinked List


    return 0;
}