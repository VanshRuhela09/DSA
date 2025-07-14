// compliment of base 10 number
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n,ans;
    cout << "enter n\n";
    cin >>n;
    int mask= 0;
    int k = n;
    if(n==0){ //edge case
        ans = 1;
        cout<<ans;
    }
    else{

    while(n!=0){
        mask = mask<<1;
        mask = mask|1;
        // cout<<mask<<endl;
        n = n>>1;
    }
    ans = (~k)&mask; // and kara diya ~k or ~n ke sath
    cout << ans;
    }
    


    return 0;
}