// creating 2D arrray dynamically
#include<iostream>
using namespace std;
int main(){
    int n;
    cout <<"entet size" <<endl;
    cin>>n;

    int m;
    cout <<"entet size" <<endl;
    cin>>m;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] <<" ";
        }
        cout<<endl;
    }
    
    // free the dynamic memeory manualy
    // first for rows
    for (int i = 0; i < n; i++)
    {
            delete []arr[i];
    }

    // for free the columns of array
    delete []arr;
    
    

    
    return 0;
}