#include<bits/stdc++.h>
using namespace std;
void print(int ind , int n, int arr[] , int sum , int s , vector<int> ds){
    if(sum==s){
        for(auto i : ds){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    else if(ind==n){
        return;
    }
    ds.push_back(arr[ind]);
    s+= arr[ind];
    print(ind+1,n,arr,sum,s,ds);
    ds.pop_back();
    s-=arr[ind];
    print(ind+1,n,arr,sum,s,ds);

}
int main(){
    int arr[] = {3,1,2,2};
    vector<int> ds;
    print(0,4,arr,4,0,ds);
    return 0;
}