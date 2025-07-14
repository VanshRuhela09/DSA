// find pair of elements whose sum is equal to n(input)
#include<iostream>
using namespace std;
        void Pair_Sum(int arr[] , int size , int n){
            
         for (int i = 0; i < size; i++)
         {
            for (int j = i+1; j <size; j++)
            {
                if(i!=j){  // this is for not occuring like 55(5+5)

                    if(arr[i]+arr[j]==n){
                        cout << arr[i] << arr[j] << " ";
                    }
                    
                }
            }
            
         }
         
          
        }
int main(){
    int n;
    cout << "Enter number " << endl;
    cin >> n;
    int arr[100] = {2,-3,3,3,-2};
    Pair_Sum(arr,5,n);
    return 0;
}