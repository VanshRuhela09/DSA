// find unique element in array
#include<iostream>
using namespace std;
    int find_uniq(int arr[] , int size){
         int ans = 0;
       for (int i = 0; i < size; i++)
       {
        ans = ans^arr[i];
       }
       return ans;
       
    }

    // int find_uniq(int arr[] , int size){
    //      for (int i = 0; i < size; i++)
    //      {
    //         int elem = 0;
    //         for (int j = 0; j < size; j++)
    //         {
    //             if(arr[i]==arr[j]){
    //                 elem++;
    //             }
    //         }
    //         if(elem == 1){
    //             return arr[i];
    //         }
            
    //      }
    // }

int main(){
     int arr1[5]= {3,5,7,5,3};

    cout << "unique elemet is " << find_uniq(arr1,5);

    return 0;
}