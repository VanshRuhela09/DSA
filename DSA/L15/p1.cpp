// book allocation problem
#include<iostream>
using namespace std;
    bool is_possible(int mid , int arr[] , int size , int stu){
        int stuCount = 1 , nopage=0;
        for (int i = 0; i < size; i++)
        {
            if(nopage+arr[i]<=mid){
                nopage += arr[i];
            }
            else{
                stuCount++;
                if(stuCount>stu || arr[i]>mid){
                    return false;
                }
            nopage = 0;
            nopage += arr[i];
            }
        }
        return true;
        
        
    }
    int Book(int arr[] , int size , int stu){
        int end = 0;
        for (int i = 0; i < size; i++)
        {
            end = end + arr[i];
        }
        
        int start = 0, ans = -1;
        int mid = start + (end - start)/2;
        while(start<=end){
            if(is_possible(mid , arr , size , stu)){
                end = mid - 1;
                ans = mid;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
int main(){
    int n;
    cout << "Enter number of students " << endl;
    cin >> n;
    int arr[] = {12,34,67,90};
    cout << "ans is " << Book(arr , 4 ,n); 
    return 0;
}