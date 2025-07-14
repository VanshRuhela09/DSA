// binary search by recursion
#include<iostream>
using namespace std;
    bool search(int arr[] , int val , int start , int end){
        int mid = start+(end-start)/2;
        if(end<start){
            return false;
        }
        if(arr[mid]==val){
            return true;
        }
        else if(val>arr[mid]){
            return search(arr , val , mid+1 , end);
        }
        else{
            return search(arr , val , start , mid-1);
        }
        
    }
int main(){
    int arr[] = {3,5,6,8,9,10};
    if(search(arr,8,0,5)){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    return 0;
}