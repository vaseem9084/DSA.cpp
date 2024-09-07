#include<iostream>
using namespace std;

// int main(){
//     // declare 2-D array
//     int arr[6][6];

//     cout<<"Enter the value of an array: "<<endl;
//     //taking input in array
//     for(int i = 0; i < 6; i++){
//         for(int j = 0; j < 6; j++){
//             cin>>arr[i][j];
//         } 
//     }
//     // printing array
//     for(int i = 0; i < 6; i++){
//         for(int j = 0; j < 6; j++){
//             cout<<arr[i][j];
//         }
//     }
    
// }


bool binarySearch(int arr[][4], int row, int col, int target){
    int start = 0;
    int end  = row * col -1;
    int mid =  start + (end-start)/2;

    while(start <= end){
        int rowIndex = mid / col;
        int colIndex = mid % col;

        if(arr[rowIndex][colIndex] == target){
            cout<<"Element found at index "<<"["<<rowIndex<<"]"<<" "<<"["<<colIndex<<"]"<<endl;
            return true;
        }
        else if(arr[rowIndex][colIndex] < target){
            //right search
            start = mid + 1;
        }
        else{
            //left search
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return false;

}
int main(){
    int arr[5][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    int row = 5;
    int col = 4;
    int target = 15;

    bool ans = binarySearch(arr, row, col, target);
    if(ans){
        cout<<"Found"<<endl;

    }
    else{
        cout<<"not found"<<endl;
    }
    
}