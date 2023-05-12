#include<iostream>
using namespace std;

// Node Class
class Node{
    public:
        int data;
        Node * next;

        // Constructor
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }

        ~Node(){
            int value = this -> data;
            // memory free
            if(this -> next != NULL){
                delete next;
                this->next = NULL;
            }
        }
};

// Inserting at Head
void InsertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;

}

// Inserting at Tail
void InsertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next= temp;
    tail = temp;

}

// Inserting at Given Position
void InsertAtPosition(Node* &head, Node* &tail, int position, int data){
    Node* temp = head;
    int cnt = 1;
    
    if(position == 1){
        InsertAtHead(head,data);
        return;
    }

    while( cnt < position-1 ){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        InsertAtTail(tail,data);
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Deletion on LinkedList
void Delete(int position, Node* &head){
    // delete at 0th/head position
   if(position == 1){
     Node* temp = head;
     head = head->next;
     temp->next = NULL;
     delete temp;
     return;
   }
//    deleting any middle or last node
   else{
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    while(cnt< position){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
   }

}

// Printing Linked List
void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
}


int main(){
    // Creating First Node
    Node* node1 = new Node(10);
    // cout << node1->data <<" ";
    // cout << node1->next <<" ";

    // Creating Head ptr
    Node* head =node1;
    InsertAtHead(head, 15);
    // Creating Tail ptr
    Node* tail = node1;
    InsertAtTail(tail,30);

    InsertAtPosition(head,tail,1,50);

    InsertAtTail(tail, 5);

    Delete(1, head);

    printList(head);

    
    cout <<endl;
    return 0;
}