// stack implement using linked list

#include<iostream>
#include<stdlib.h>
using namespace std;

/* Structure to create a node with data and pointer */

struct Node
{
    int data;
    struct Node *next;
}
// Initially the list is empty
*top = NULL; 
void push(int);
void pop();
void display();

int main()
{
    int choice, value;
    cout<<"IMPLEMENTING STACKS USING LINKED LISTS\n"<<endl;
    while(1)
    {
        cout<<"1. Push\n2. Pop\n3. Display\n4. Exit\n"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1: printf("Enter the value to insert: ");
            cin>>value;
            push(value);
            break;

            case 2: pop();
            break;

            case 3: display();
            break;

            case 4: exit(0);
            break;

            default: cout<<"Invalid Choice"<<endl;;
        }
    }
}

void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value; // get value for the node
    if(top == NULL)
    newNode->next = NULL;
    else
    newNode->next = top; // Make the node as TOP
    top = newNode;
    cout<<"Node is Inserted"<<endl;
}

void pop()
{
    if(top == NULL)
    cout<<"EMPTY STACK"<<endl;
    else
    {
        struct Node *temp = top;
        cout<<"Popped Element : %d"<<temp->data<<endl;

        top = temp->next; // After popping, make the next node as TOP
        free(temp);
    }
}

void display()
{
    // Print the stack
    if(top == NULL)
    cout<<"EMPTY STACK"<<endl;
    else
    {
        cout<<"The stack is "<<endl;
        struct Node *temp = top;
        while(temp->next != NULL)
        {
            cout<<"--->"<<temp->data;
            temp = temp -> next;
        }
        cout<<"--->"<<temp->data;
        cout<<"--->NULL"<<endl;
    }
}