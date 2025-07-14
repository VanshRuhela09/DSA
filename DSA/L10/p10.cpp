#include<iostream>
using namespace std;
    void Sort(int arr[] , int size){
        for (int i = 0; i < size; i++)
        {
            for(int j = i+1; j<size; j++){
                if(arr[i]>arr[j]){
                    int temp;
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        
    }
int main(){
    int arr[100] = {0,2,1,1,0,1,2,0,0,1};
    Sort(arr , 10);
    for (int i = 0; i < 10; i++)
    {
        cout<< arr[i] << " ";
    }
    
    return 0;
}