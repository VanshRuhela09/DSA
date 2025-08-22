#include <bits/stdc++.h>  
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i = 0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    vector<int> key(n+1);
     priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    for(int i = 1; i<=n; i++){
        mst[i] = false;
        parent[i] = -1;
        key[i] = INT_MAX;
    }

    pq.push({0,1});
    key[1] = 0;
    parent[1] = -1;

        while(!pq.empty()){

        // int mini = INT_MAX;
        int u;

        // finding the smallest from the key array

        auto t = pq.top();
        pq.pop();
        u = t.second;
        mst[u] = true;
        for(auto neig : adj[u]){
            int v = neig.first;
            int w = neig.second;
            // if(mst[v]==false) means loop nahi hona chiye
            if(mst[v]==false && w<key[v]){
                pq.push({w,v});  // this and below line is for the same work 
                key[v] = w; //
                parent[v] = u;
            }
        }

    }
    

    vector<pair<pair<int, int>, int>> ans;
    
    // we start i=2 bcs 0th index(node) nahi hai graph me and 1th node ka parent -1 hai
    for(int i = 2; i<=n; i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;



}