// string subsequence for a given string in the output.
#include<iostream>
#include<vector>
using namespace std;

// void printSubSequences(string str, string output, int i){
//     //base case
//     if(i >= str.length()){
//         cout<<output<<endl;
//         return;
//     }
//     // Exclude
//     printSubSequences(str, output, i+1);

//     //include
//     output.push_back(str[i]);
//     printSubSequences(str, output, i+1);

// }

// int main(){
//     string str = "abc";
//     string output = "";
//     int i = 0;
//     printSubSequences(str, output, i);
//     return 0;
// }




// *********** agar mujhe is string ko store karana hai string ki form mai . *********

void printSubSequences(string str, string output, int i, vector<string>& v){
    //base case
    if(i >= str.length()){
        v.push_back(output);
        return;
    }
    // Exclude
    printSubSequences(str, output, i+1, v);

    //include
    output.push_back(str[i]);
    printSubSequences(str, output, i+1, v);

}

int main(){
    string str = "abc";
    string output = "";
    vector<string> v;
    int i = 0;
    printSubSequences(str, output, i, v);

    cout<<"printing all subsequences: ";
    for(auto val: v){
        cout<<val<<" ";
    }

    cout<<endl<<"size of vector is: "<<v.size()<<endl;
    return 0;
}