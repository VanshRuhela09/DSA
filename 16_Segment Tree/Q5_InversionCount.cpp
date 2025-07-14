#include<bits/stdc++.h>
using namespace std;
void build(int seg[] , int arr[] , int ind , int low , int high){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }
    
    int mid = (low + high)/2;
    build(seg,arr,ind*2+1,low,mid);
    build(seg,arr,ind*2+2,mid+1,high);
    seg[ind] = seg[ind*2+1] + seg[ind*2+2];
}

int query(int seg[] , int ind , int l , int r , int low , int high){
    if(l > high || r < low){
        return 0;
    }
    else if(low >= l && high <= r){
        return seg[ind];
    }
    else{
        int mid = (low + high)/2;
        int left = query(seg,ind*2+1,l,r,low,mid);
        int right = query(seg,ind*2+2,l,r,mid+1,high);
        return left + right;
    }
}

void update(int seg[] , int ind ,int low , int high , int i){
    if(low == high){
        seg[ind]--;
        return;
    }

    int mid = (low + high)/2;
    if(i<=mid){
        update(seg,ind*2+1,low,mid,i);
    }
    else{
        update(seg,ind*2+2,mid+1,high,i);
    }

    seg[ind] = seg[ind*2+1] + seg[ind*2+2];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    int maxi = 0;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        maxi = max(maxi,arr[i]);
    }
    int freq[maxi+1] = {0};

    for(int i = 0; i<n; i++){
        freq[arr[i]]++;
    }

    int seg[4*maxi];

    build(seg,freq,0,0,maxi);
    int sum = 0;
    for(int i = 0; i<n; i++){
        freq[arr[i]]--;
        update(seg,0,0,maxi,arr[i]);
        sum += query(seg,0,0,arr[i]-1,0,maxi);      
    }
    cout<<"ans is : "<<sum<<endl;
    return 0;
}