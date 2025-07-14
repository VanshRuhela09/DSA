#include<bits/stdc++.h>
using namespace std;
void buildSegmentTree(int arr[] , int seg[] , int ind , int low , int high){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    buildSegmentTree(arr,seg,ind*2+1,low,mid);
    buildSegmentTree(arr,seg,ind*2+2,mid+1,high);
    seg[ind] = min(seg[ind*2+1] , seg[ind*2+2]);

}

int query(int seg[] , int ind , int l ,int r , int low , int high){

    if(high < l || low > r){
        return INT_MAX;
    }
    else if(low >= l && high <= r){
        return seg[ind];
    }
    else{
        int mid = (low + high)/2;
        int left = query(seg , ind*2+1,l,r,low,mid);
        int right = query(seg , ind*2+2,l,r,mid+1,high);
        return min(left,right);
    }
}

void update(int seg[] , int ind , int i , int val , int low ,int high){

    if(low == high){
        seg[ind] = val;
        return;
    }

    int mid = (low+high)/2;
    if(i <= mid ){
        update(seg,ind*2+1,i,val,low,mid);
    }
    else{
        update(seg,ind*2+2,i,val,mid+1,high);
    }
    seg[ind] = min(seg[ind*2+1] , seg[ind*2+2]);
}

int main(){
    int n;
    cout<<"enter size of array : ";
    cin>>n;
    int arr[n];
    int seg[n*4 + 1];
    cout<<"enter elements : ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    buildSegmentTree(arr,seg , 0 , 0 , n-1);


    int q;
    cout<<"enter number of querires : ";
    cin>>q;
    while(q--){
        int type;
        cout<<"enter type: ";
        cin>>type;
        if(type == 1){
            int l , r ;
            cout<<"enter l , r : ";
            cin>>l>>r;
            cout<<"\nminimum is : "<<query(seg,0,l,r,0,n-1)<<endl;
        }
        else{
            int i ,val;
            cout<<"enter i and val : ";
            cin>>i>>val;
            update(seg,0,i,val,0,n-1);
            arr[i] = val;
            cout<<"\nupdated"<<endl;
        }
        
    }
    return 0;
}