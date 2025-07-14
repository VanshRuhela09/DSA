// reverse an array
#include<iostream>
using namespace std;
    void reverse(int arr[] , int size){
        for (int i = 0; i < size/2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[size-i-1];
            arr[size-i-1] = temp;

        }
        
    }
int main(){
    int size,arr[100];
    cout << "Enter size of array " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element number " << i+1 <<endl;
        cin >> arr[i];
    }
     cout << "array before reversed is " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " ;
    }
    reverse(arr,size);
    cout << "Reversed arrray is " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " ;
    }
    
    return 0;
}