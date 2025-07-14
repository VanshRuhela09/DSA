#include<iostream>
using namespace std;
void merge(int arr[] , int s , int e){
    int mid = (s+e)/2;
    int ind1 = mid-s+1;
    int ind2 = e - mid;
    int arr1[ind1];
    int arr2[ind2];
    int mind = s;
    for(int i = 0; i<ind1; i++){
        arr1[i] = arr[mind++];
    }

    for(int i = 0; i<ind2; i++){
        arr2[i] = arr[mind++];
    }

    mind = s;
    int i = 0 , j = 0;
    while(i<ind1 && j<ind2){
        if(arr1[i]<arr2[j]){
            arr[mind++] = arr1[i++];
        }
        else {
            arr[mind++] = arr2[j++];
        }
    }

    while(i<ind1){
        arr[mind++] = arr1[i++];
    }

    while(i<ind2){
        arr[mind++] = arr2[j++];
    }
}
void sort(int arr[] , int s, int e){
    if(s<e){
        int mid = (s+e)/2;
        sort(arr,s,mid);
        sort(arr,mid+1,e);
        merge(arr,s,e);
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

    sort(arr,0,size-1);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}