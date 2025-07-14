#include<iostream>
using namespace std;
 bool func(int n){
    if(n&1){
        return 0;
    }
    else{
        return 1;
    }
 }
int main(){
    int n;
    cout << "Enter a number\n";
    cin >> n ;
    if(func(n)){
        cout<<"even\n";
    }
    else{
        cout<<"odd";
    }
    return 0;
}