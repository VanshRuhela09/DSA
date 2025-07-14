// a^b
#include<iostream>
using namespace std;
    int fastExp(int a , int b){
     int ans = 1;
     while(b>0){
        if(b&1){
            ans = ans * a;
        }
        a = a * a;
       b = b>>1;
     }
     return ans;
        
    }
int main(){
    int a , b;
    cout << "enter " << endl;
    cin >> a >> b;
    cout << "ans is :" << fastExp(a,b);
    return 0;
}