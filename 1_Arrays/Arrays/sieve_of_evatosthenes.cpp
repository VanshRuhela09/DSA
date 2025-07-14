//method to find how many prime number are there between 1 to n
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    int count = 0;
    vector<int> prime(n+1 , true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if(prime[i]){
            count++;
        }
        for (int j = 2*i; j < n; j=j+i)
        {
            prime[j] = false;
        }
        
    }
    cout << "there are " << count << " prime numebers" << endl;
    
    return 0;
}