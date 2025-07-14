#include<bits/stdc++.h>
using namespace std;
int partition(int arr[] ,int s , int e){
    srand(time(0));
    int kuchaur = s+rand()%(e-s+1);
    swap(arr[kuchaur],arr[e]);
    int pivot = arr[e];
    int i = s-1;
    for(int j = s; j<e; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }

    }
    swap(arr[i+1],arr[e]);
    return i+1;
}   
void Quick(int arr[] , int s , int e){
    if(s<e){
        int pivot = partition(arr,s,e);
        Quick(arr,s,pivot-1);
        Quick(arr,pivot+1,e);
    }
}
int main(){
    int size;
    cout<<"enter size : ";
    cin>>size;
    int arr[size];
    cout<<"enter array : ";
    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }
    Quick(arr,0,size-1);

    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}