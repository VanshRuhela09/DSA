#include<iostream>
using namespace std;
int main(){
    int n,n1=100,n2=50,n3=20,n4=1;
    cout << "Enter amount\n";
    cin >> n;
    cout<<"100 rupees notes required are : "<<n/100 <<endl;
    n = n-(n/100)*100;
    cout << " 50 rupees notes required are : " << n/50 <<endl;
    n = n - (n/50)*50;

    cout << " 20 rupees notes required are : "<<n/20 <<endl;
    n = n-(n/20)*20;

    cout<<"1 rupees notes required are : " << n <<endl;
    return 0;
}