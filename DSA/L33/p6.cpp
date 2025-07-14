// peek element in an array
#include<iostream>
using namespace std;
    int Peek(int arr[] , int start , int end){
        int mid = start+(end-start)/2;
        if(start==end){
            return arr[start];
        }
        if(arr[mid]>arr[mid+1]){
            return Peek(arr,start,mid);
        }
        else{
            return Peek(arr,mid+1,end);
        }
    }
int main(){
    int arr[] = {0,3,7,10,8,7,1};
    int start = 0 , end = 6;
    cout<<"peak element is "<<Peek(arr,start , end);
    return 0;
}