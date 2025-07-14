// reverse an integer between range of an integer
#include<iostream>
using namespace std;
int main(){
    int n,rev=0,r;
    cout<<"enter a number \n";
    cin>>n;
    while(n!=0){
        r = n%10;
        //condition
        // if(rev>INT_MAX/10|| rev<INT_MIN/10){
        //     return 0;
        // }
        rev = rev*10+r;
        n = n/10;
        
    }
    cout<<"reversed number is :"<<rev;
    return 0;
}