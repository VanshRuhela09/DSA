#include<bits/stdc++.h>
using namespace std;
class ST{
        vector<int> seg , lazy;
    public:
        ST(int n){
            seg.resize(4*n);
            lazy.resize(4*n);
        }
        void build(int ind , int low , int high , int arr[]){
            if(low == high){
                seg[ind] = arr[low];
                return;
            }
            int mid = (low + high)/2;
            build(ind*2 + 1 , low , mid , arr);
            build(ind*2 + 2 , mid + 1, high , arr);
            seg[ind] = seg[ind*2 + 1] + seg[ind*2 + 2];
        }

        void update(int ind , int l , int r , int low , int high){
            if(lazy[ind]!=0){
                seg[ind] = (high - low + 1) - seg[ind];
                if(low != high){
                    lazy[ind*2 + 1] = !lazy[ind*2+1];
                    lazy[ind*2 + 2] = !lazy[ind*2+2];
                }
                lazy[ind] = 0;
            }

            if(l > high || r < low){
                return;
            }
            else if(low >= l && high <= r){
                seg[ind] = (high - low + 1) - seg[ind];

                if(low != high){
                    lazy[ind*2+1] = !lazy[ind*2+1];
                    lazy[ind*2+2] = !lazy[ind*2+2];
                }
                return;
            }
            else{
                int mid = (low + high)/2;
                update(ind*2+1,l,r,low,mid);
                update(ind*2+2,l,r,low,high);
                seg[ind] = seg[ind*2+1] + seg[ind*2+2];
            }
        }

        int query(int ind , int l , int r , int low , int high){
            if(lazy[ind]!=0){
                seg[ind] = (high - low + 1) - seg[ind];
                if(low != high){
                    lazy[ind*2 + 1] = !lazy[ind*2+1];
                    lazy[ind*2 + 2] = !lazy[ind*2+2];
                }
                lazy[ind] = 0;
            }
            if(l > high || r < low){
                return 0;
            }
            else if(low >= l && high <= r){
                return seg[ind];
            }
            else{
                int mid = (low + high)/2;
                int left = query(ind*2+1,l,r,low,mid);
                int right = query(ind*2+2,l,r,mid+1,high);
                return left + right;
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
    tree.build(0,0,n-1,arr);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        int l , r;
        cin>>l>>r;
        if(type == 1){
            int ans = tree.query(0,l,r,0,n-1);
            cout<<"ans is : "<<ans<<endl;
        }
        else{
            tree.update(0,l,r,0,n-1);
        }
    }
    return 0;
}
