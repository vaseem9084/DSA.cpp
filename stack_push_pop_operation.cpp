#include<iostream>
using namespace std;
#define n 100
int stack[n] = {10,20,30,40,50};

int top=4;
void push(int stack[], int item)
{
    
    if(top ==n-1)
    {
        cout<<"Stack overflow";
    }
    else
    {
        top = top +1;
        stack[top] = item;
    }
}
int pop()
{
        if(top == -1)
        {
            cout<<"Stack underflow";
            return 0;
        }
        else
        {
            return stack[top--];
        }
}

int main()
{
    int item;
    cout<<"Enter the item";
    cin>>item;

    
    push(stack,item);
    for(int i = top ;i>=0;i-- )
    {
        cout<<" "<<stack[i]<<" ";
    }
    cout<<endl;
    pop();
    for(int i = top ;i>=0;i-- )
    {
        cout<<" "<<stack[i]<<" ";
    }

}


   