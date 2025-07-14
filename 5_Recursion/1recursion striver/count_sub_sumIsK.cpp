#include<bits/stdc++.h>
using namespace std;
int subsetSumk(int ind , int n, int arr[] , int sum , int s){
    if(sum==s){
        return 1;
    }
    else if(ind==n){
        return 0;
    }
    s+= arr[ind];
    int left = subsetSumk(ind+1,n,arr,sum,s);
    s-=arr[ind];
    int right = subsetSumk(ind+1,n,arr,sum,s);
    return left + right;
}
int main(){
    int arr[] = {3,1,2,2};
    cout<<"number of subseq are : "<<subsetSumk(0,4,arr,4,0);
    return 0;
}