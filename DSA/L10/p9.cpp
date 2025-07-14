// all zero one side and all one one side
#include<iostream>
using namespace std;
    void Sort(int arr[] , int size){
        int i = 0 , j = size-1;
        while(i<j){
            if(arr[i]==0){
                i++;
            }
            else if(arr[j]==0){
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

            if(arr[j]==1){
                j--;
            }

        }

        // for (int i = 0; i < size; i++)
        // {
        //     for (int j = i+1; j < size; j++)
        //     {
        //         if(arr[i]<arr[j]){
        //             int temp;
        //             temp = arr[i];
        //             arr[i] = arr[j];
        //             arr[j] = temp;
        //         }
        //     }
            
        // }
        
    }
int main(){
    int arr[100] = {1,1,1,0,0,0,1};
    Sort(arr,7);
    for(int i = 0; i<7; i++){
        cout << arr[i] << " ";
    }
    return 0;
}