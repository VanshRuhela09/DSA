#include<iostream>
using namespace std;
void heapyfy(int arr[] , int ind , int size){
    int lc = 2*ind + 1;
    int rc = 2*ind + 2;
    int max = ind;

    if(lc<size && arr[lc]>arr[max]){
        max = lc;
    }
    if(rc<size && arr[rc]>arr[max]){
        max = rc;
    }
    if(max!=ind){
        swap(arr[max],arr[ind]);
        heapyfy(arr,max,size);
    }
}

void HeapSort(int arr[] , int size){
    // int n = size;
    // while(n>0){
    //     swap(arr[0],arr[n-1]);
    //     heapyfy(arr,0,n-1);
    //     n--;
    // }
    if(size<=0){
        return;
    }
    swap(arr[0] , arr[size-1]);
    heapyfy(arr,0,size-1);
    HeapSort(arr,size-1);
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

    for(int i = (size/2)-1; i>=0; i--){
        heapyfy(arr,i,size);
    }

    HeapSort(arr,size);

    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}