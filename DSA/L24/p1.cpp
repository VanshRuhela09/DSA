// gcd or hcf of two numbers
#include<iostream>
using namespace std;
    int gcd(int a , int b){
        while(a!=0 && b!=0){
            if(a>b){
                a = a - b;
            }
            else{
                b = b - a;
            }
        }

        if(a==0){
            return b;
        }
        else{
            return a;
        }
    }
int main(){
    int a , b;
    cout << "enter number" << endl;
    cin>>a>>b;
    cout << "gcd is " << gcd(a,b);
    return 0;
}