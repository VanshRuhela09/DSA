#include<iostream>
using namespace std;
    void countone(int a, int b){
        int count = 0;
        while((a&1) || (b&1)){
            if(a&1){
                count++;
            }
            if(b&1){
                count++;
            }
            a = a>>1;
            b = b>>1;
        }
        cout << "number of ones are : " << count;
    }
int main(){
    int a,b;
    cout << "Enter a and b" << endl;
    cin >> a >>b;
    countone(a,b);

    return 0;
}