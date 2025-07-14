#include<bits/stdc++.h>
using namespace std;
void update(int fen[] , int i , int val , int n){
    while(i<=n){
        fen[i] += val;
        i = i + (i &(-i));
    }
}

int find(int fen[] , int k , int n){
    int pointer = 0, sum = 0;
    for(int i = log2(n); i>=0; i--){
        if(fen[pointer + (1<<i)] + sum < k){
            pointer = pointer + (1<<i);
            sum += fen[pointer];
        }
    }
    return (pointer + 1);
}

// int find(int fen[] , int k , int n){
//     int pointer = 0 , sum = 0;
//     int p = log2(n);
//     while(p>=0){
//         pointer += pow(2,p);
//         if(sum + fen[pointer] < k){
//             sum += fen[pointer];
//         }
//         else{
//             pointer -= pow(2,p);
//         }
//         p--;
//     }
//     return pointer + 1;
// }

int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;

    //this n+1 bcs we are not considering the 0th index we are considering the 1 based indexing
    int fen[n+1] = {0};
    int arr[n+1];
    cout<<"enter array : ";
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i = 1; i<=n; i++){
        update(fen,i,arr[i],n);
    }

    for(int i = 1; i<=n; i++){
        cout<<fen[i]<<" ";
    }
    cout<<endl;

    int k;
    cout<<"enter number to find lower bound : ";
    cin>>k;
    cout<<"lower bound is : "<<find(fen,k,n)<<endl;
    

    return 0;
}