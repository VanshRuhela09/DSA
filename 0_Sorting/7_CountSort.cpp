#include<bits/stdc++.h>
using namespace std;
void countSort(vector<int> &V1 , int size){

    int max = V1[0];
    for(auto i : V1){
        if(max<i){
            max = i;
        }
    }
    max++;

    vector<int> Farr(max,0);
    for(auto i : V1){
        Farr[i]++;
    }

    vector<int> Carr(max,0);
    int temp = 0;
    for(int i = 0; i<max; i++){
        temp = temp + Farr[i];
        Carr[i] = temp;
    }
    vector<int> ans(size,0);
    for(int i = size -1; i>=0; i--){
        int temp = --Carr[V1[i]];
        ans[temp] = V1[i];
    }
    cout<<"sorted array is : ";
    for(auto i : ans){
        cout<<i<<" ";
    }
}
int main(){
    int size;
    cout<<"enter size : ";
    cin>>size;
    vector<int> V1;
    for(int i = 0; i<size; i++){
        int temp;
        cin>>temp;
        V1.push_back(temp);
    }
    countSort(V1,size);

    return 0;
}