#include<iostream>
using namespace std;
int main(){
    int arr[3][4] = {1,2,4,6,8,9,10,14,16,18,20,21};
     for (int i = 0; i < 3; i++)
     {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] <<" ";
        }
        cout<<endl;
     }
    int flag = 0;
     int start = 0;
     int end = 12 - 1;
     cout << "enter target" << endl;
     int n;
     cin >> n;
     while(start<=end){

    int a = start + (end - start)/2;
    int mid =   arr[a/4][a%4];
    if(mid==n){
        flag = 1;
        break;
    }
    else if(n<mid){
        end = a - 1;
    }
    else{
        start = a + 1;
    }
       
     }

     if(flag == 1){
        cout << "found " << endl;
     } 
     else{
        cout << "not found" << endl;
     }
     
    return 0;
}