// ********** the doubly linked list **************

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this -> data = 0;
        this -> prev = NULL;
        this -> next = NULL;
    }

    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
    ~Node(){
        cout<<"Node with value: "<<this-> data<<" deleted"<<endl;
    }
};

// Write the Print function
void printList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// find the length
int getlength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp -> next;
        len++;
    }
    return len;
}

//******* 1. I want to insert at head in a linked list **********
void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        // mari Linked list empty hai
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // linked list is non empty
        // step 1 : create a new node
        Node* newNode = new Node(data);
        // step 2 : connect the new node with head
        newNode -> next = head;
        // step 3 : connect the head with new node
        head -> prev = newNode;
        // step 4 : change the head
        head = newNode;
    }
}

//********* 2. I want to inset at tail in a linked list ***********
void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        // linked list is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // linked list is non empty
        // step 1 : create a new node
        Node* newNode = new Node(data);
        // step 2 : connect the tail with new node
        tail -> next = newNode;
        // step 3 : connect the new node with tail
        newNode -> prev = tail;
        // step 4 : tail ko chane karna hai
        tail = newNode;
    }
}

// ********** 3. I want to insert at position in a linked list *************
void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    if(head == NULL){
        // linked list is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // linked list is non empty
        if(position == 1){
            // insert at head
            insertAtHead(head, tail, data);
            return;
        }
        int len = getlength(head);
        if(position > len){
            // insert at tail
            insertAtTail(head, tail, data);
            return;
        }
        // insertion in middle
        // step 1 : find prev & curr 
        int i = 1;
        Node* prevNode = head;
        while( i < position-1){
            prevNode = prevNode -> next;
            i++;
        }
        Node* curr = prevNode -> next;

        // Step 2 : crate a new node
        Node* newNode = new Node(data);
        // step 3 : prev -> next ko newNode per connect karo
        prevNode -> next = newNode;
        // step 4 : newNode -> prev hai usko connect karo prevNode per
        newNode -> prev = prevNode;
        // step 5 : curr -> prev ko connect karo new node per
        curr -> prev = newNode;
        // step 6 : newNOde -> next ko connect karo curr
        newNode -> next = curr;

    }

}
// ********* 4. I want to delete from the position ***********
void deleteFromPosition(Node* &head, Node* &tail, int position){
    if(head == NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }

    // single node are there and delete 
    if(head -> next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    // position handle kar li
    int len = getlength(head);
    if(position > len){
        cout<<"Please enter a valid position"<<endl;
    }

    // I want to delte the first node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
        return;
    }

    // I want to delete last node
    if(position == len){
        Node* temp = tail;
        tail = tail -> prev;
        temp -> prev = NULL;
        tail -> next = NULL;
        delete temp;
        return;
    }

    // ********* 5. I want to delete the middle node **************

    // step 1: find left, curr, right
    int i = 1;
    Node* left = head;
    while( i < position - 1){
        left = left -> next;
        i++;
    }
    Node* curr = left -> next;
    Node* right = curr -> next;

    // step 2: 
    left -> next = right;
    // step 3: 
    right -> prev = left;
    // step 4:
    curr -> prev = NULL;
    // step 5: 
    curr -> next = NULL;
    //step 6:
    delete curr;
    return;
    



}



int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* head = first;
    Node* tail = third;

    first -> next = second;
    second -> prev = first;

    second -> next = third;
    third -> prev = second;

    // printList(first);
    // cout<<endl;

    insertAtHead(head, tail, 101);
    //cout<<endl;
    //cout<<"Insert at head :"<<endl;
    //printList(head);
    //cout<<endl;

    insertAtTail(head, tail, 102);
    //cout<<endl;
    //cout<<"Insert at tail :"<<endl;
    //printList(head);
    //cout<<endl;

    insertAtPosition(head, tail, 110, 6);
    // cout<<endl;
    // cout<<"Insert at position :"<<endl;
    printList(head);
    cout<<endl;


    deleteFromPosition(head, tail, 4);
    cout<<endl;
    cout<<"After deletion linked list is :"<<endl;
    printList(head);

    return 0;
}

