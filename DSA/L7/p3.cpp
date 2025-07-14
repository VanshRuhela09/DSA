#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n,flag=0;
    cout << "enter n\n";
    cin>>n;
   for (int i = 0; i <=30; i++)
   {
    int p = pow(2,i);
    if(p==n){
        flag = 1;
        break;
    }
    
   }
   if(flag == 1){
    cout << "power of 2";
   }
   else{
    cout<<"not power of 2";
   }
    return 0;
}