#include<bits/stdc++.h>
using namespace std;
void make_list(unordered_map<int,list<int>> &adj , vector<vector<int>> &edges){
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(unordered_map<int,list<int>> &adj , vector<int> &component , unordered_map<int,bool> &visited , int node){
    component.push_back(node);
    visited[node] = 1;

    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(adj,component,visited,i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj;
    make_list(adj , edges);

    vector<vector<int>> ans;

    unordered_map<int,bool> visited;
    //for disconnected graph
    for(int i = 0; i<V; i++){
        if(!visited[i]){
        vector<int> component;
            dfs(adj , component , visited , i);
        ans.push_back(component);
        }

    }

    return ans;

    
}


int main(){
    // solution of codestudio
}