#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int open , close , full;
    Node(){
        open = 0;
        close = 0;
        full = 0;
    }
    Node(int o , int c , int f){
        open = o;
        close = c;
        full = f;
    }
};

Node merge(Node leftTree , Node rightTree){
    Node node;
    node.full = leftTree.full + rightTree.full + min(leftTree.open , rightTree.close);
    node.open = leftTree.open + rightTree.open - min(leftTree.open, rightTree.close);
    node.close = leftTree.close + rightTree.close - min(leftTree.open , rightTree.close);
    return node;
}

void build(Node seg[] , int ind , string &s , int low , int high){
    if(low == high){
        seg[ind] = Node(s[low] == '(' , s[low] == ')' , 0);
        return;
    }

    int mid = (low + high)/2;
    build(seg,ind*2 + 1 , s , low , mid);
    build(seg,ind*2 + 2 , s , mid+1,high);

    seg[ind] = merge(seg[ind*2+1] , seg[ind*2+2]);
}

Node query(Node seg[] , int ind , int low , int high , int l , int r){
    if(l > high || r < low){
        return Node(0,0,0);
    }
    else if(low >= l && high <= r){
        return seg[ind];
    }
    else{
        int mid = (low + high)/2;
        Node left = query(seg,ind*2+1,low , mid , l , r);
        Node right = query(seg , ind*2+2 , mid+1,high , l , r);
        return merge(left , right);
    }
}
int main(){
    string s;
    cin>>s;
    int q;
    cin>>q;

    int n = s.length();
    Node seg[4*n];

    build(seg,0,s,0,n-1);

    while(q--){
        int l , r;
        cin>>l>>r;
        Node ans = query(seg,0,0,n-1,l-1,r-1);
        cout<<"ans is "<<ans.full*2<<endl;
    }
    return 0;
}