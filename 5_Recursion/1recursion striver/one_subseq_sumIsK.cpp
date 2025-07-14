#include<bits/stdc++.h>
using namespace std;
bool print(int ind , int n, int arr[] , int sum , int s , vector<int> ds){
    if(sum==s){
        for(auto i : ds){
            cout<<i<<" ";
        }
        return true;
    }
    else if(ind==n){
        return false;
    }
    ds.push_back(arr[ind]);
    s+= arr[ind];
    if(print(ind+1,n,arr,sum,s,ds)){
        return true;
    }
    ds.pop_back();
    s-=arr[ind];
   if(print(ind+1,n,arr,sum,s,ds)){
        return true;
    }
    return false;
}
int main(){
    int arr[] = {3,1,2,2};
    vector<int> ds;
    print(0,4,arr,4,0,ds);
    return 0;
}