#include<bits/stdc++.h>
using namespace std;
class SegmentTree{

    private:
        vector<int> seg;
    public:
        SegmentTree(int n){
            seg.resize(4 * n + 1);
        }

    void buildSegmentTree(int arr[] , int ind , int low , int high){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        buildSegmentTree(arr,ind*2+1,low,mid);
        buildSegmentTree(arr,ind*2+2,mid+1,high);
        seg[ind] = min(seg[ind*2+1] , seg[ind*2+2]);
    
    }
    
    int query(int ind , int l ,int r , int low , int high){
    
        if(high < l || low > r){
            return INT_MAX;
        }
        else if(low >= l && high <= r){
            return seg[ind];
        }
        else{
            int mid = (low + high)/2;
            int left = query( ind*2+1,l,r,low,mid);
            int right = query( ind*2+2,l,r,mid+1,high);
            return min(left,right);
        }
    }
    void update(int ind , int i , int val , int low ,int high){
    
        if(low == high){
            seg[ind] = val;
            return;
        }
    
        int mid = (low+high)/2;
        if(i <= mid ){
            update(ind*2+1,i,val,low,mid);
        }
        else{
            update(ind*2+2,i,val,mid+1,high);
        }
        seg[ind] = min(seg[ind*2+1] , seg[ind*2+2]);
    }
};


int main(){
    // giving two arrays
    cout<<"enter size and element of array1 : ";
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i = 0; i<n1; i++){
        cin>>arr1[i];
    }
    SegmentTree seg1(n1);
    seg1.buildSegmentTree(arr1,0,0,n1-1);
    
    cout<<"enter size and element of array2 : ";
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int i = 0; i<n2; i++){
        cin>>arr2[i];
    }
    
    //creating two segment trees;
    SegmentTree seg2(n2);
    seg2.buildSegmentTree(arr2,0,0,n2-1);

    int q;
    cout<<"enter number of queries : ";
    cin>>q;
    while(q--){
        cout<<"enter type : ";
        int type;
        cin>>type;
        if(type == 1){
            cout<<"enter l1 , r1 , l2 , r2 : ";
            int l1 , r1 , l2 , r2;
            cin>>l1>>r1>>l2>>r2;
            int min1 = seg1.query(0,l1,r1,0,n1-1);
            int min2 = seg2.query(0,l2,r2,0,n2-1);
            cout<<"minimum is : "<<min(min1,min2)<<endl;
        }
        else{
            int arrNO , i , val;
            cout<<"enter arrNo , i and val : ";
            cin>>arrNO>>i>>val;
            if(arrNO == 1){
                seg1.update(0,i,val,0,n1-1);
                arr2[i] = val;
            }
            else{
                seg2.update(0,i,val,0,n1-1);
                arr2[i] = val;
            }
        }
    }
    return 0;
}