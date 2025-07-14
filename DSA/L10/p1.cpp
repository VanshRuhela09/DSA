// swap alternate elements of array
#include<iostream>
using namespace std;
    void reverse_alt(int arr[] , int size){
       
        for (int i = 0; i < size; i+=2)
        {
            if(i+1<size){

            int temp;
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            }
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
    cout << endl;
    reverse_alt(arr,size);
    cout << "Reversed arrray is " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " ;
    }

    return 0;
}