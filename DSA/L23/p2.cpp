// print like a wave
#include<iostream>
using namespace std;
int main(){
    int arr[3][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[j][i];
        }
        
    }
    cout << "print" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }

    int i = 0;
    int j = 0;
    while(i<4){

       if(i%2==0){
        while(j<3){
            cout << arr[j][i] << " ";
            j++;
        }
        j--;
       }
        else{
            while(j>=0){
                cout << arr[j][i] << " ";
                j--;
            }
            j++;
        }

        i++;
    }
    

    
    
    return 0;
}