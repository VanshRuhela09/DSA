//merge sorted array
#include<iostream>
using namespace std;
    void merge_sort(int arr1[] , int s1 , int arr2[] , int s2 , int arr3[]){
        int start1 = 0 , start2 = 0 ,  start3=0;
       
                while(start1<s1 && start2<s2){
                if(arr1[start1]<arr2[start2]){
                    arr3[start3] = arr1[start1];
                    start1++;
                    start3++;
                }
                else{
                    arr3[start3] = arr2[start2];
                    start2++;
                    start3++;
                }

                }


            
            while(start1<=s1){
                arr3[start3] = arr1[start1];
                start1++;
                start3++;
            }
            while(start2<=s2){
                arr3[start3] = arr2[start2];
                start2++;
                start3++;
            }
        }
    void print(int arr3[] , int size){
        for (int i = 0; i < size; i++)
        {
            cout << arr3[i] << " ";
        }
        
    }
int main(){
    int arr1[] = {1,3,5,7,9};
    int arr2[] = {2,4,6};
    int arr3[100];
    merge_sort(arr1 , 4, arr2 , 3 , arr3);
    print(arr3 , 8);

    return 0;
}