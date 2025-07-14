#include<iostream>
using namespace std;
int main(){
    int arr[] = {6,3,1,0,5,0};
    bool check = false;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6-1-i; j++)
        {
            if(arr[j]>arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                check = true;
            }
        }
        if(check == false){
            break;
        }
        
    }

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    
    
    return 0;
}