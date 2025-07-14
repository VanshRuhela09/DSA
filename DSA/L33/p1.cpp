// check is array is sorted or not
#include<iostream>
using namespace std;
    bool check_sort(int arr[] , int size , int i){
        if(i>=size-1){  // agar i last element tak pahoocha toh array sorted hai
            return true;
        }
        if(arr[i]>arr[i+1]){
            return false;
        }
        return check_sort(arr,size,i+1);
    }
int main(){
    int arr[] = {2,9,3,8,9,10,19};
    if(check_sort(arr,7 , 0)){

        cout<<"array is sorted"<<endl;
    }
    else{
        cout<<"not sorted"<<endl;
    }
    return 0;
}