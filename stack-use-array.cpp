#include<iostream>
using namespace std;

class Stack{
    public:
        int *arr;
        int size;
        int top;


    Stack(int size)
    {
        this -> size = size;
        arr = new int[size];
        top = -1;  
    }

    void push(int element)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout<<"Stack is overflow"<<endl;
        }
    }

    void pop()
    {
        if(top >= 0)
        {
            top--;
        }
        else
        {
            cout<<"Stack is underflow"<<endl;
        }
    }
    void peek()
    {
        if(top >= 0)
        {
            cout<<arr[top]<<endl;
        }
        else
        {
            cout<<"Stack is empty"<<endl;
        }
    }
    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

int main()
{
    Stack st(5);
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(10);
    st.push(20);
    cout<<"The Top value is: ";
    st.peek();

    st.pop();
    cout<<"The Top value is: ";
    st.peek();

    st.pop();
    cout<<"The Top value is: ";
    st.peek();

    
    
    
}
