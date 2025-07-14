#include<iostream>
#include<math.h>
using namespace std;
// code is correct answer is not correct due to compiler
int main(){
    int n,bit,ans=0;
    cout << "enter number\n";
    cin>>n;
    int i = 0;
    while(n!=0){
        bit = n&1;
        // bit = n%10;   --->this is for number
    ans = bit*pow(10,i)+ans;
    n = n>>1;
    // n = n/10;
    i++;
    }
    cout<<ans;
    return 0;
}