#include<iostream>
using namespace std;
#define n 100

class stack{
    int* arr;
    int top;
    public:
        stack(){
            arr=new int[n];
            top = +1;
        }
        void push(int x){
            if(top==-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            top++;
            arr[top]=x;
        }
        void pop(){
            
            if(top==-1){
                cout<<"NO element to pop"<<endl;
                return;
            }

            top--;
        }
        int Top(){
            if(top==-1){
                cout<<"No element in stack"<<endl;
                return-1;         
                
            }
            return arr[top];
        }

        bool empty(){
            return top==-1;
        }
        
};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.push(4); 
    st.push(5);
    st.push(6);
    st.pop();
    st.pop();
    cout<<st.Top()<<endl;
    st.push(7);
    st.push(8);
    st.pop();
    cout<<st.Top()<<endl;
    cout<<st.empty()<<endl;

    return 0;


}
