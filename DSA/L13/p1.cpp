 // first and last  position of Element in sorted Array
#include<iostream>
using namespace std;          
    int First_Occ(int arr[] , int size , int key){
        int start = 0 , end = size-1 , cur = 0,ans = -1;
        cur = start + (end-start)/2;
        while(start<=end){

            if(key == arr[cur]){
                ans = cur;
                end = cur - 1;
                
            }
            else if(key<arr[cur]){
                end = cur - 1;
            }
            else {
                start = cur + 1;
            }

            cur = start + (end-start)/2;

        }
        return ans;
    }

    int Last_Occ(int arr[] , int size , int key){
        int start = 0 , end = size-1 , cur = 0,ans = -1;
        cur = start + (end-start)/2;
        while(start<=end){

            if(key == arr[cur]){
                ans = cur;
                start = start +1;
            }
            else if(key<arr[cur]){
                end = cur - 1;
            }
            else {
                start = cur + 1;
            }

            cur = start + (end-start)/2;

        }
        return ans;
    }
int main(){
    int arr[] = {0,0,1,1,2,2,2,2};
    int n;
    cout << "Enter element" << endl;
    cin >> n;
    cout << "first index of element is :" << First_Occ(arr,8,n) <<endl;
    cout << "last index of element is :" << Last_Occ(arr,8,n);
    return 0;
}