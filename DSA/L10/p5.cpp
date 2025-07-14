#include<iostream>
using namespace std;
    void func(int arr[] , int size){
        int arr2[100],m=0;
        for (int i = 0; i < size; i++)
        { int count = 0;
           
        if(arr[i]!=0){

            for (int j=0; j < size; j++)
            {
                if(arr[i]==arr[j]){
                    count++;
                    arr[j] = 0;
                }
            }
            if(count == 2){
                arr2[m] = arr[i];
                m++;
            }
            
        }
            
        
            }

        for (int i = 0; i < m; i++)
        {
            cout<<arr2[i] << " ";
        }
        
    }
int main(){
    int arr[100]={1,2,3,3,4,5,6,6,7};
    func(arr,9);

    return 0;
}