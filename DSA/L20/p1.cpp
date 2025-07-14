// reverse an array(simple)
#include<iostream>
using namespace std;    
    void rev(int arr[] , int size){
        int start = 0 , end = size - 1;
        for (int i = 0; start<=end; i++)
        {
            int temp;
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
        
    }
int main(){
    int arr[] = {1,2,3,4,5};
    rev(arr,5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}