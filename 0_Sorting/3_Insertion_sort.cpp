#include<iostream>
using namespace std;
int main(){
    int arr[] = {9,3,1,0,2};
    for (int i = 1; i < 5; i++)
    {
        int current = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j]>current){
                arr[j+1]=arr[j];
                j--;
            }
            else{
                break;
            }
        }
        arr[j+1] = current;
    }

    for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
    return 0;
}