// count number of ways to climb steps
#include<iostream>
using namespace std;
    int find(int n){
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        return find(n-1)+find(n-2);
    }
int main(){
    int n;
    cout<<"enter"<<endl;
    cin>>n;
    cout<<find(n);
    return 0;
}