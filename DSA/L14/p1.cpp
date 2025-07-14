//find pivot element in an array
#include<iostream>
using namespace std;
    int Find_Pivot(int arr[] , int size){
        int start = 0 , end = size - 1 ,ans = -1;
        int mid = start + (end - start)/2;
        while(start<end){

            
            // if((arr[mid]<arr[mid-1]) && (arr[mid]<arr[mid+1])){
            //     ans = arr[mid];
            //     return ans;
                
            // }
            // else if(arr[mid]>arr[0]){
            //     start = mid+1;

            // }
            // else if(arr[mid]<arr[0]) {
            //     end = mid ;
            // }          
            // mid = start + (end - start)/2;




            if(arr[mid]>=arr[0]){
                start = mid +1;
            }
            else{
                end = mid;
            }
            mid = start + (end-start)/2;
        }
        return start;
        
    }
int main(){
    int arr[] = {11,13,15,17};
    cout << "pivot element is at index number: " << Find_Pivot(arr , 4);
    return 0;
}