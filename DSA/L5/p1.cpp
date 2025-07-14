#include<iostream>
using namespace std;
int main(){
    int n,x = 0,y = 1;
    cout << "enter n\n";
    cin >> n;
    cout << x << " " << y <<" ";
    for (int i = 1; i <=n; i++)
    {
        int next = x+y;
        cout<<next<<" ";
        x = y;
        y = next;

    }
    
    return 0;
}