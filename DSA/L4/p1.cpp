#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "enter n\n" <<endl;
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        
        for (int j = 1; j <n-i+1; j++)
        {
            cout<<" ";
        }

        for (int k = 1; k<=i; k++)
        {
            cout<<k;
        }
        
        for (int l = 1; l <i; l++)
        {
            
            cout<<i-l;
        }

        cout << endl;
        

    }
    
    return 0;
}