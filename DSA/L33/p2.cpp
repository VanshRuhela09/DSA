// find the sum of elements of array
#include<iostream>
using namespace std;
// also can use p1.cpp logic
    int Sum(int arr[] , int i){
        if(i<0){
            return 0;
        }
        return arr[i] + Sum(arr,i-1);
    }
int main(){
    int arr[] = {2,4,9,9,9};
    cout<<Sum(arr,4);
    return 0;
}