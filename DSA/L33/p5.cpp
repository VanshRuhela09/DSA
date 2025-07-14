// first and last position of given n
#include<iostream>
using namespace std;
    int First(int arr[] , int start , int end , int val , int ans){
        int mid = start+(end-start)/2;
        if(start>end){
            return ans;
        }
        if(arr[mid]==val){
            ans = mid;
          return First(arr,start,mid-1,val , ans);
        }
        else if(val>arr[mid]){
           return First(arr,mid+1,end,val,ans);
        }
        else{
           return First(arr,start,mid-1,val,ans);
        }
    }

    int Last(int arr[] , int start , int end , int val , int ans){
        int mid = start+(end-start)/2;
        if(start>end){
            return ans;
        }
        if(arr[mid]==val){
            ans = mid;
           return Last(arr,mid+1,end,val , ans);
        }
        else if(val>arr[mid]){
           return Last(arr,mid+1,end,val,ans);
        }
        else{
           return Last(arr,start,mid-1,val,ans);
        }
    }
int main(){
    int arr[] = {1,2,2,2,3,3,5,5,5,7,7,7};
    cout<<"First position "<<First(arr,0,11,7,-1)<<endl;
    cout<<"last position "<<Last(arr,0,11,7 ,-1);
    return 0;
}