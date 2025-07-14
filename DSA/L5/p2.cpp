#include<iostream>
using namespace std;
int main(){
    int n,prod=1,sum=0,res;
    cout<<"enter n\n";
    cin>>n;
    while(n!=0){
        int mod = n%10;
        prod = prod*mod;
        sum = sum + mod;
        n = n/10;
    }
    res = prod - sum;
    cout<<"answer is: "<<res;
    
    return 0;
}