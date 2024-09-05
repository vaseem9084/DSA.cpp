// ******** Insertion/Deletion of the linked list (program) ***************
// ***** 1. insert at head ***********
// ***** 2. indert at tail ***********
// ***** 3. insert at position/ middle ***********
// ***** 4. delete at head ***********
// ***** 5. delete at tail ***********
// ***** 6. delete at position/middle ***********


#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // create a constructor
        Node(){
            this->data = 0;
            this->next = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        // write a destructor to delete a node
        ~Node(){
            cout<<"Node with value "<<this->data<<" deleted."<<endl;
        }
};

//  ************* 1. I want to insert a node right at the (head) of the linked list **************
void insertAtHead(Node* &head, Node* &tail, int data){
    // check for empty linked list
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //Step - 1 : node create karna hai
    Node* newNode = new Node(data);
    //Step - 2 : head ko new node se connect karna hai
    newNode->next = head;
    //Step - 3 : head ko new node se replace karna hai
    head = newNode;
}

// ************ 2. I want to insert a node left at the (tail) of the linked list **********
void insertAtTail(Node* &head, Node* &tail, int data){
    // check for empty linked list
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //Step - 1 : node create karna hai
    Node* newNode = new Node(data);
    //Step - 2 : tail ko new node se connect karna hai
    tail->next = newNode;
    //Step - 3 : tail ko new node se replace karna hai
    tail = newNode;

}
// create a find function
int findLength(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp -> next;
        count++;
    }
    return count;
}

//  ************** 3. I want to instert a node to the (position) of the linked list ****************8
void insertAtPosition(int data, int position, Node* &head, Node* &tail){
    // check for empty linked list
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    //  handle the case position = 0 
    if(position == 0){
        insertAtHead(head, tail, data);
        return ;
    }
    // handle the case position = end the linked list
    int len = findLength(head);
    if(position > len){
        insertAtTail(head, tail, data);
    }

    // Step 1 : find the position : previous & current
    int i = 1;
    Node* previous = head;
    while(i < position){
        previous =  previous -> next;
        i++;
    }
    
    Node* current = previous->next;
    //Step 2 : create a node
    Node* newNode = new Node(data);
    // Step 3 : connect the new node to current node
    newNode->next = current;
    // Step 4 : connect the previous node to new node
    previous->next = newNode;

}

//***********  print the linked list ***********
void printlist(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}
//*********** I want to delete a node for a linked list **********************
void deleteNode(int position, Node* &head, Node* &tail){
    // check for empty linked list
    if(head == NULL){
        cout<<"Can't delete, linked list is empty"<<endl;
        return;
    }
    //********** 4. TO delete first node ***********
    if(position ==1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return;
    }
    // ********* 5. To delete a last node ************
    int len = findLength(head);
    if(position == len){
        // step 1: find previous
        int i = 1;
        Node* previous = head;
        while(i < position -1){
            previous = previous -> next;
            i++;
        }
        // Step 2 : previous ke next ko NULL kar do
        previous-> next = NULL;
        // step 3 : create a temp node
        Node* temp = tail;
        // step 4 : update tail
        tail = previous;
        // step 5 : delete the tail node
        delete temp;
        return;
    }

    // ********** 6. To delete middle node *************

    // Step 1 : find previous ans current
    int i = 1;
    Node* previous = head;
    while(i < position - 1){
        previous = previous -> next;
        i++;
    }
    Node* current = previous -> next;

    // Step 2 : previous -> next =  current -> next karo
    previous -> next = current -> next;

    // Step 3 : current -> next ko NULL karo
    current -> next = NULL;

    // Step 4 : node ko delete kar do
    delete current;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);
    printlist(head);

    cout<<endl;
    // cout<<"head "<<head->data <<endl;
    // cout<<"Tail "<<tail->data<<endl;

    // insertAtPosition(101 , 7, head, tail);
    // cout<<endl;
    // printlist(head);
    // cout<<endl;
    // cout<<"head "<<head->data <<endl;
    // cout<<"Tail "<<tail->data<<endl;


    deleteNode(6, head, tail);
    cout<<endl;
    printlist(head);
    cout<<endl;
    return 0;
}