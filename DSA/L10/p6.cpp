//finding intersection of two array
#include<iostream>
using namespace std;
    void Array_Intersection(int arr1[] , int size1 , int arr2[] , int size2){
           //good and optimise code
        int i = 0, j = 0;
        while(i<size1 && j<size2){
            if(arr1[i]==arr2[j]){
                cout << arr2[j] << " ";
                i++;
                j++;
            }
            else if(arr1[i]<arr2[j]){
                i++;
            }
            else{
                j++;
            }
        }






        // for (int i = 0; i < size1; i++)
        // {
        //     for (int j = 0; j < size2; j++)
        //     {
        //         if(arr1[i]==arr2[j]){
        //             cout<<arr2[j]<<" ";
        //             arr2[j]=0;
        //             break;
        //         }
        //     }
            
        // }
        
        
    }
int main(){
    int arr1[100] = {1,2,2,2,3,4};
    int arr2[100] = {2,2,3};
    Array_Intersection(arr1 , 6 , arr2 , 3);
    return 0;
}