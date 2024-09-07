// ******** Array declare/ initilization  and 1 question solve ***************

#include<iostream>
using namespace std;

int main(){

    //******* This is static array *********

    // ****** array decleration ********

    // int arr[10];
    // cout<<"Array created successfully"<<endl;
    // base address
    // cout<<arr<<endl;
    // cout<<&arr<<endl;


    //***** Array initilization *******

    // int arr[5] = {2,3,4,5,6};
    //int brr[] ={1,3,5,7,9,10};
    // char crr[5] = {'a','b','c'};
    // cout<<"Array initilize successfully"<<endl;
    
    //cout<<"first array"<<endl;
    // ******First type value print *****
    // cout<<arr[0]<<endl;
    // cout<<arr[1]<<endl;
    // cout<<arr[2]<<endl;
    // cout<<arr[3]<<endl;
    // cout<<arr[4]<<endl;

    // cout<<"second array"<<endl;
    // ******* second type value print *******
    // for(int i = 0; i<6; i++){
    //     cout<<brr[i]<<" ";
    // }



    // ***** user define input *******

    // int arr[10];
    // cout<<"Enter the value of an array: "<<endl;
    // taking input in array
    // for(int i = 0; i < 10; i++){
    //     cin>>arr[i];
    // }
    // cout<<"Printing the value of an array: "<<endl;
    // for(int i = 0; i < 10; i++){
    //     cout<<arr[i]<<" ";
    // }


    // ****** Question-1:  user input array in size 5 and output is double.******



    int arr[500];
    int n;
    cout<<" How many number you want to add in array: ";
    cin>>n;
    cout<<"Enter the value of an array: "<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Printing the value of double in  array:"<<endl;
    for(int i = 0; i < n; i++){
        cout<< 2* arr[i]<<" ";
    }
}