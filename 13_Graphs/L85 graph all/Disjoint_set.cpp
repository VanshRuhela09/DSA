#include<bits/stdc++.h>
using namespace std;
class Disjoint{
    vector<int> parent;

    vector<int> rank;//this is used when we are doing union by rank.  
    
    vector<int> size; // this is used when we are doing union by size.
    public:
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        size.resize(n+1,1);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUltiParent(int k){
        if(parent[k]==k){
            return k;
        }
        return parent[k] = findUltiParent(parent[k]);
    } 

    void UnionByRank(int u , int v){
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);
        
        if(ultiParent_u==ultiParent_v){
            return;
        }

        if(rank[ultiParent_u]==rank[ultiParent_v]){
            parent[ultiParent_v] = ultiParent_u;
            rank[ultiParent_u]++;
            //here rank increase hogi ultimateParent of u ki 
        }
        else if(rank[ultiParent_u]>rank[ultiParent_v]){
            parent[ultiParent_v] = ultiParent_u;
            // yaha rank increase nahi hogi bcs yha chota rank vala badi rank ke sath connect ho raha hai
        }
        else{
            parent[ultiParent_u] = ultiParent_v;
        }
    }


    void UnionBySize(int u , int v){
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);

        if(ultiParent_u == ultiParent_v){
            return;
        }
        if(size[ultiParent_u] > size[ultiParent_v]){
            parent[ultiParent_v] = ultiParent_u;
            size[ultiParent_u] += size[ultiParent_v];
        }
        else{
            parent[ultiParent_u] = ultiParent_v;
            size[ultiParent_v] += size[ultiParent_u];
        }

    }
};  
int main(){
    Disjoint set(7);

    // set.UnionByRank(1,2);
    // set.UnionByRank(2,3);
    // set.UnionByRank(4,5);
    // set.UnionByRank(6,7);
    // set.UnionByRank(5,6);

    // they don't belong to same graph because we did't union of both graphs
    // if(set.findUltiParent(3) == set.findUltiParent(7)){
    //     cout<<"yes both belongs to same graph"<<endl;
    // }
    // else{
    //     cout<<"no they don't belongs to same graph"<<endl;
    // }

    // now union of both the graphs
    // set.UnionByRank(3,7);

    // if(set.findUltiParent(3) == set.findUltiParent(7)){
    //     cout<<"yes both belongs to same graph"<<endl;
    // }
    // else{
    //     cout<<"no they don't belongs to same graph"<<endl;
    // }


    set.UnionBySize(1,2);
    set.UnionBySize(2,3);
    set.UnionBySize(4,5);
    set.UnionBySize(6,7);
    set.UnionBySize(5,6);

    if(set.findUltiParent(3) == set.findUltiParent(7)){
        cout<<"yes both belongs to same graph"<<endl;
    }
    else{
        cout<<"no they don't belongs to same graph"<<endl;
    }


    set.UnionBySize(3,7);

    if(set.findUltiParent(3) == set.findUltiParent(7)){
        cout<<"yes both belongs to same graph"<<endl;
    }
    else{
        cout<<"no they don't belongs to same graph"<<endl;
    }
    return 0;
}