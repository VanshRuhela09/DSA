// find triplet sum of input n
#include<iostream>
using namespace std;
    void Find_Triple(int arr[] , int size , int n){
        for (int i = 0; i < size; i++)
        {
            for (int j = i+1; j < size; j++)
            {
                for (int k = j+1; k<size; k++)
                {
                    if(arr[i]+arr[j]+arr[k]==n){
                        cout << arr[i] << arr[j] << arr[k] << " ";
                    }
                }
                
            }
            
        }
        
    }
int main(){
    int n;
    cout << "Enter number " << endl;
    cin >> n;
    int arr[] = {1,2,3,4,5};
    Find_Triple(arr,5,n);
    return 0;
}