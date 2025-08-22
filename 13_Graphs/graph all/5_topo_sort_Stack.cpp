#include <bits/stdc++.h> 
void sort(int node , stack<int> &st , unordered_map<int,list<int>> &adj , vector<bool> &visited){
    visited[node] = true;

    for(auto neig : adj[node]){
        if(!visited[neig]){
        sort(neig , st,adj,visited);
        }
        
    }
            st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;
    for(int i = 0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }


    vector<int> ans;
    stack<int> st;
    vector<bool> visited(v,0);
    for(int i =0; i<v; i++){
        if(!visited[i]){
            sort(i,st,adj,visited);
        }
    }

    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;


}