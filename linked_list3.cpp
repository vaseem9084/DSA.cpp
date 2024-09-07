// ******** Insertion or reverse of the linked list (program) ***************
// ***** 1. insert at head ***********
// ***** 2. indert at tail ***********
// ***** 3. insert at position/ middle ***********
// ***** 4. I want to reverse the string ***********
// ***** 5. Iwant to reverse the string using loop *********


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
// ********** 4. I want to reverse the string using recursion  *****************
// Node* reverse(Node* &prev, Node* &curr){
    // base case
//     if(curr == NULL){
          // linked list reverse ho chuki 
//         return prev;
//     }
     // 1 case solve karna hai baki recursion sambhal lega
//     Node* forward = curr -> next;
//     curr -> next = prev;

    // recursive call
//     reverse(curr, forward);
// }

//  ****** 5. I want to reverse the string using loop *************
Node* reverseusingloop(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp; 
    }
    return prev;
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
   // printlist(head);

    //cout<<endl;
    //cout<<"head "<<head->data <<endl;
    //cout<<"Tail "<<tail->data<<endl;

    insertAtPosition(101 , 7, head, tail);
    //cout<<endl;
    printlist(head);
    cout<<endl;
    //cout<<"head "<<head->data <<endl;
    //cout<<"Tail "<<tail->data<<endl;

    // **** reverse using recursion code for main function ******
    // Node* prev = NULL;
    // Node* curr = head;
    // head = reverse (prev, curr);
    // cout<<endl;
    // printlist(head);
    // cout<<endl;

    // **** reverse using loop code for main function ******
    Node* prev = NULL;
    Node* curr = head;
    head = reverseusingloop(head);
    cout<<endl;
    printlist(head);
    cout<<endl;

    return 0;
}