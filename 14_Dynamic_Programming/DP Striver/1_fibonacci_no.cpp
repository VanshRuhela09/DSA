#include<iostream>
#include<vector>
using namespace std;

// this is recursion code fibonacci
int fib(int n , vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = fib(n-1,dp) + fib(n-2,dp);
}

// its tabulation code and for loop code is present in notebook.
int main(){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<"ans is : "<<fib(n,dp);
    return 0;
}