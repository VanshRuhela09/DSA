//peak element in an array
#include<iostream>
using namespace std;
    int Find_Peak(int arr[] , int size){
        int start = 0 , end = size -1 , ans = -1;
        int mid = start + (end-start)/2;
        while(start<end){
            if(arr[mid]>arr[mid+1]){
                end = mid;
            }
            else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return end;
    }
int main(){
    int arr[] = {1,5,6,9,10,14,16,2,1};
    cout << "Peak element is at index number:" << Find_Peak(arr,9);
    return 0;
}