#include<iostream>
using namespace std;

// Node Class
class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        // Constructor
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
        ~Node(){
            int val = this->data;
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"memory free for node: "<<val;
            cout<<endl;
        }
};

void printList(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// getting length of linkedlist
void Length(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    cout<<"Length of List: "<<len;
    cout <<endl;
}

// Inserting node at head
void InsertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head->prev= temp;
    head = temp;
}

// Inserting Node at Tail
void InsertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// Ineserting Node at given index
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
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// Delete Node
void DeleteNode(Node* &head, int position){
    
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head= head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        // Deleting at middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        
    }



}

int main(){
    Node* node1 = new Node(20);
    Node* head = node1;
    Node* tail = node1;

    InsertAtHead(head,40);
    InsertAtTail(tail,110);
    InsertAtPosition(head,tail,3,200);
    InsertAtPosition(head,tail,1,300);


    printList(head);
    Length(head);


    // Deleting Node at head
    // DeleteNode(head,1);
    // printList(head);
    // Length(head);

    // Delete Node at middle or last
    DeleteNode(head, 3);
    printList(head);

    // Printing head and tail node
    cout<<"Head-> "<<head->data<<endl;
    cout<<"Tail-> "<<tail->data<<endl;


    return 0;
}