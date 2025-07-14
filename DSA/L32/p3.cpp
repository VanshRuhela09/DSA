#include<iostream>
using namespace std;
    void SayDigit(int n , string arr[]){
        if(n==0){
            return;
        }
        int dig = n%10;
        n=n/10;
        SayDigit(n,arr);
        cout<<arr[dig]<<" ";
    }
int main(){
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cout<<"enter"<<endl;
    cin>>n;
    SayDigit(n,arr);
    return 0;
}