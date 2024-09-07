#include<iostream>
using namespace std;

int queue[5];
long front,rear;


void initqueue()
{
    front = rear = -1;
}
void display()
{
    int i;
    for(i = front ; i<= rear; i++)
    {
        cout<<endl<<queue[i];
    }
    
}

int main()
{
    int choice,info;
    int init_queue();

    while(1)
    {
        cout<<"          MENU          "<<endl;
        cout<<"1. push an element in queue: "<<endl;
        cout<<"2. pop an element from queue: "<<endl;
        cout<<"3. Display the queue: "<<endl;
        cout<<"4. Exit: "<<endl;

        cout<<"your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                if(rear<4)
                {
                    cout<<"Enter the number: ";
                    cin>>info;

                    if(front == -1)
                    {
                        front==0;
                        rear == 0;
                    }
                    else
                    {
                        rear = rear+1;
                    }
                    queue[rear] = info;
                    
                }
                else
                {
                    cout<<"Queue is full";
                }
                break;

            case 2:
                if(front !=-1)
                {
                    info = queue[front];
                    if(front == rear)
                    {
                        front = -1;
                        rear = -1;
                    }
                    else
                    {
                        front = front +1;
                    }
                    cout<<"NO delete is ="<<info;
                }
                else
                {
                    cout<<"Queue is empty";
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:cout<<"You enter wrong choice!";
                break;
        }
    }
}

