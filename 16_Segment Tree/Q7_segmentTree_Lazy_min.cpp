#include<bits/stdc++.h>
//this is for range min query and update
using namespace std;
class ST{
        vector<int> seg,lazy;
    public:
        ST(int n){
            seg.resize(n*4);
            lazy.resize(n*4);
        }
        void build(int ind , int arr[], int low , int high){
            if(low == high){
                seg[ind] = arr[low];
                return;
            }
            int mid = (low + high)/2;
            build(ind*2+1,arr,low,mid);
            build(ind*2+2,arr,mid+1,high);
            seg[ind] = min(seg[ind*2+1] , seg[ind*2+2]);
        }

        void update(int ind , int low , int high , int l , int r , int val){
            // first update the previous remaining updates
            // and propogate downwards
            if(lazy[ind] != 0){
                seg[ind] += lazy[ind];
                
                //one you update now propogate downwards 
                
                //checking is there is children of this node
                if(low != high){
                    lazy[2*ind+1] += lazy[ind];
                    lazy[2*ind+2] += lazy[ind];
                }

                lazy[ind] = 0;

            }
            //no overlap we don't do anything we just return
            if(l>high || r < low){
                return;
            }
            else if(low >= l && high <= r){
                seg[ind] += val;
                if(low != high){
                    lazy[ind*2+1] = val;
                    lazy[ind*2+2] = val;
                }
                return;
            }
            else{
                int mid = (low + high)/2;
                update(ind*2+1 , low , mid , l , r , val);
                update(ind*2 + 2 , mid+1 , high , l , r , val);
                seg[ind] = min(seg[ind*2 + 1] , seg[ind*2 + 2]);
            }
        }

        int query(int ind , int low , int high , int l , int r){

             // first update the previous remaining updates
            // and propogate downwards
            if(lazy[ind] != 0){
                seg[ind] += lazy[ind];
                
                //one you update now propogate downwards 
                
                //checking is there is children of this node
                if(low != high){
                    lazy[2*ind+1] += lazy[ind];
                    lazy[2*ind+2] += lazy[ind];
                }

                lazy[ind] = 0;

            }

            if(l > high  || r < low){
                return INT_MAX;
            }
            else if(low >= l && high <= r){
                return seg[ind];
            }
            else{
                int mid = (low + high)/2;
                int left = query(ind*2 + 1 , low , mid , l , r);
                int right = query(ind*2 + 2 , mid + 1 , high , l , r);
                return min(left , right);
            }
        }
};
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    ST tree(n);
    tree.build(0,arr,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        int l , r;
        cin>>l>>r;
        if(type == 1){
            int ans = tree.query(0 , 0,n-1,l , r);
            cout<<"ans is : "<<ans<<endl;
        }
        else{
            int val;
            cin>>val;
            tree.update(0 , 0 , n-1,l , r, val);
        }
    }
    return 0;
}