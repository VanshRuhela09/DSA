// merge two sorted array using recursion
#include<iostream>
using namespace std;
    int* merge(int arr1[] , int arr2[] , int arr3[] , int size1, int size2 , int i){
        if(size1<=0 && size2<=0){
            return arr3;
        }
        if(arr1[0]<arr2[0]){
            arr3[i] = arr1[0];
            return merge(arr1+1,arr2,arr3,size1-1,size2,i+1);
        }
        else{
            arr3[i] = arr2[0];
            return merge(arr1,arr2+1,arr3,size1,size2-1,i+1);
        }
    }
int main(){
    int arr1[] = {1,7,9,11,20};
    int arr2[] = {5,15,18,22,29,30};
    int arr3[100];
    int i = 0;
    int size1 = 5, size2 = 6;
    int* arr4 = merge(arr1,arr2 , arr3 ,size1, size2,i);
    for (int i = 0; i < 11; i++)
    {
        cout<<arr4[i]<<" ";
    }
    
    return 0;
}