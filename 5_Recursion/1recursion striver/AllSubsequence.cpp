#include<bits/stdc++.h>
using namespace std;
void print(int ind , int n , int arr[] , vector<int> ds){
    if(ind==n){
        for(auto i : ds){
            cout<<i<<" ";
        }
        if(ds.size()==0){
            cout<<"{ }"<<endl;
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]);
    print(ind+1,n,arr,ds);
    ds.pop_back();
    print(ind+1,n,arr,ds);
}
int main(){
    int arr[] = {3,1,2};
    vector<int> ds;
    print(0,3,arr,ds);
    return 0;
}