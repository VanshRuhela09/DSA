#include<iostream>
using namespace std;
void heapify(int arr[] , int n , int i){
    int largest = i;
    int left = i*2;
    int right = i*2 + 1;
    
    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[] , int size){
    int n = size;
    while(n>1){
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
    }

}
int main(){
    
    int arr[] = {-1,5,4,2,1,3}; // this array should be an heap
    heapSort(arr,5);
    
    for(int i = 1; i<=5; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}