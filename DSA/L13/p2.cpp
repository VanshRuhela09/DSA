// find occurence of element
#include<iostream>
using namespace std;

        int First_Occ(int arr[] , int size , int key){
            int start = 0, end = size -1,ans = -1;
            int mid = start + (end-start)/2;
            while(start<=end){
                if(key == arr[mid]){
                    ans = mid;
                    end = mid - 1;
                }
                else if(key>arr[mid]){
                    start = mid + 1;
                }
                else {
                    end = end - 1;
                }
                mid = start + (end-start)/2;
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
    int first = First_Occ(arr,8,n);
    int last = Last_Occ(arr,8,n);
    cout << "Total number of occurence is :" << last - first +1;
    return 0;
}