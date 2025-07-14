// jagged array
#include<iostream>
using namespace std;
int main(){
    int row[100]; // for storing size of rows
    int m;
    cout << "enter number of rows" << endl;
    cin>>m;
    int **arr = new int*[m]; 
    for (int i = 0; i < m; i++)
    {
        cout << "Enter size of row" << endl;
        int n;
        cin>>n;
        arr[i] = new int[n];
        row[i] = n;
        cout << "Enter element of row" << endl;
        
       
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }

    }
    for (int k = 0; k < m; k++)
     {
        for (int j = 0; j < row[k]; j++)
        {
           cout << arr[k][j]<<" ";
        }
        cout << endl;
     }
    
    //for free the memory
    for (int i = 0; i < row[i]; i++)
    {
        delete []arr[i];
    }
    delete []arr;
    
    return 0;
}