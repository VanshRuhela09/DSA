#include<bits/stdc++.h>
using namespace std;

void buildTree(int seg[] , int arr[] , int ind , int low, int high, int flag){
    if(high == low){
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    buildTree(seg,arr,ind*2+1,low,mid,!flag);
    buildTree(seg,arr,ind*2+2,mid+1,high,!flag);
    if(flag == 0){
        seg[ind] = seg[ind*2+1] ^ seg[ind*2+2];
    }
    else{
        seg[ind] = seg[ind*2+1] | seg[ind*2+2];
    }
}

void update(int seg[] , int ind  , int low , int high, int i , int val , int flag){
    if(low == high){
        seg[ind] = val;
        return;
    }

    int mid = (low + high)/2;
    if(i <= mid){
        update(seg,ind*2 + 1 , low , mid , i , val , !flag);
    }
    else{
        update(seg,ind*2+2 , mid+1,high , i , val , !flag);
    }
    if(flag == 0){
        seg[ind] = seg[ind*2+1] ^ seg[ind*2+2];
    }
    else{
        seg[ind] = seg[ind*2+1] | seg[ind*2+2];
    }
}

int main(){
    int n , m;
    cin>>n>>m;
    int N = pow(2,n);
    int arr[N];
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }


    int seg[4*N];


    int flag = 0;
    if(n%2==0){
        flag = 0;
    }
    else{
        flag = 1;
    }
    buildTree(seg,arr,0,0,N-1,flag);

    int q = m;
    while(q--){
        int p , b;
        cin>>p>>b;
        update(seg,0,0,N-1,p-1,b,flag);
        cout<<"ans is : "<<seg[0]<<endl;
    }
    return 0;
}