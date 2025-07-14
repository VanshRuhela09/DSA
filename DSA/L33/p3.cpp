// linear search
#include<iostream>
using namespace std;
    bool check(int arr[] , int val , int i){
        if(i<0){
            return false;
        }
        if(arr[i]==val){
            return true;
        }
        return check(arr,val,i-1);
    }
int main(){
    int arr[] = {6,4,7,8,1};
    if(check(arr,8,4)){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    return 0;
}