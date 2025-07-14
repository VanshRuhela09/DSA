#include<iostream>
using namespace std;
    void sort(int arr[] , int size){
        for (int i = 0; i < size-1; i++)
        {
            int min = i;
            for (int j = i+1; j < size; j++)
            {
                if(arr[min]>arr[j]){
                    min = j;
                }
                // if(arr[i]>arr[j]){
                //     int temp;
                //     temp = arr[i];
                //     arr[i] = arr[j];
                //     arr[j] = temp;
                }
                    int temp;
                    temp = arr[i];
                    arr[i] = arr[min];
                    arr[min] = temp;
            
        }
        
    }
int main(){
    int arr[] = {8,4,5,2,0};
    sort(arr , 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}