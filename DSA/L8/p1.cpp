#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter a and b\n";
    cin>>a>>b;
    cout<<"Enter operation to be perform\n";
    char ch;
    cin>>ch;
    switch(ch){
        case '+':
        cout<<a+b;
        break;

        case '*':
        cout<<a*b;
        break;

        case '-':
        cout<<a-b;
        break;

        case '/':
        cout<<a/b;
        break;

        default:
        cout<<"no such cases\n";
        break;
    }


    return 0;
}