#include<iostream>
#include<math.h>
//binary to decimal conversion
using namespace std;
int main(){
    int n,i=0,sum=0;
    cout << "enter number\n";
    cin >> n;
    while(n!=0){
        int mod = n%10;
        sum = sum + pow(2,i)*mod;
        i++;
        n = n/10;
    }
    cout << sum;
    return 0;
}