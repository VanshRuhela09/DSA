// power of two
#include<iostream>
using namespace std;
    int pow(int n){
        if(n==0){
            return 1;
        }
        return 2*pow(n-1);
    }
int main(){
    int n;
    cout<<"enter"<<endl;
    cin>>n;
    cout<<pow(n);
    return 0;
}