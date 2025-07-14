//find nth element of fibonacci series
#include<iostream>
using namespace std;
    int fib(int n){
        int a = 0, b = 1,nex = 0;
        if(n==1){
            return a;
        }
        else if(n==2){
            return b;
        }
        else {
            for(int i = 2; i<n; i++){
                nex = a+b;
                a = b;
                b = nex;
            }
            return nex;
        }
      
        
    }
int main(){
    int n;
    cout << "entr n" << endl;
    cin >> n;
    cout << "number is :" <<fib(n) << endl;
    return 0;
}