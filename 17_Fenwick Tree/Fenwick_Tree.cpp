#include<bits/stdc++.h>
using namespace std;
void update(int fen[] , int i , int val , int n){
    while(i<=n){
        fen[i] += val;
        i = i + (i &(-i));
    }
}

int sum(int fen[] , int i){ // finding sum from (0,i)
    int ans = 0;
    while(i>0){
        ans += fen[i];
        i = i - (i & (-i));
    }
    return ans;
}

int rangeSum(int fen[] , int l , int r){
    return sum(fen , r) - sum(fen , l-1);
}

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

    int q;
    cout<<"enter number of queries : ";
    cin>>q;
    while(q--){
        int type;
        cout<<"enter type : ";
        cin>>type;
        if(type == 1){
            int r;
            cout<<"enter r : ";
            cin>>r;
            int s = sum(fen,r);
            cout<<"sum is : "<<s<<endl;
        }
        else{
            int i , val;
            cout<<"enter i and val ";
            cin>>i>>val;
            update(fen , i  ,val ,n);
        }
    }

    return 0;
}