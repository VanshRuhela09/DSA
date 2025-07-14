// find pivot in an rotated sorted array
#include<iostream>
using namespace std;
    int Pivot(int arr[] , int start , int end ){
        int mid = start+(end-start)/2;
        if(start==end){
            return arr[start];
        }
        if(arr[mid]>arr[0]){
            return Pivot(arr,mid+1,end);
        }
        else{
            return Pivot(arr,start,mid);
        }

    }
int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int start = 0 , end = 6;
    cout<<"pivot element is "<<Pivot(arr,start,end);
    return 0;
}