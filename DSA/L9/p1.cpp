// find min and max from an array
#include<iostream>
using namespace std;
    int NumMax(int num[] , int size){
        int max = num[0];
        for (int i = 0; i < size; i++)
        {
            if(max<num[i]){
                max = num[i];
            }
        }
        return max;
    }

    int NumMin(int num[] , int size){
        int min = num[0];
        for (int i = 0; i < size; i++)
        {
            if(min>num[i]){
                min = num[i];
            }
        }
        return min;
    }
int main(){
    int size;
    cout << "enter size" << endl;
    cin >> size;
    int num[100];
    for (int i = 0; i < size; i++)
    {
        cout << "enter" << i+1 <<" th element of array "<< endl;
        cin >> num[i];
    }
    cout << "max number is :" << NumMax(num,size) << endl;
    cout << "min number is :" << NumMin(num,size) << endl;
    
    return 0;
}