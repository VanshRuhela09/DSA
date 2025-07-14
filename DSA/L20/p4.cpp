#include<iostream>
using namespace std;
    void move(int arr[] , int size){
        // for (int i = 0; i < size; i++)  by nested loop
        // {
            
        //         for (int j = 0; j < size-i-1; j++)
        //         {
        //             if(arr[j]==0){
        //            int temp;
        //            temp = arr[j];
        //            arr[j] = arr[j+1];
        //            arr[j+1] = temp;
        //          }
        //         }
                
            
        // }
            int j = 0;
        for (int i = 0; i < size; i++)
        {
            if(arr[i]!=0){
                swap(arr[j],arr[i]);
                j++;
            }
        }
        
        
    }

    void print(int arr[] , int size){
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        
    }
int main(){
    int arr[] = {1,0,7,0,0,4};
    move(arr , 6);
    print(arr , 6);

    return 0;
}