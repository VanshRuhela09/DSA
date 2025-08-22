#include<unordered_map>
#include<queue>
#include<list>


bool isCycleDFS(int src,int parent ,unordered_map<int,bool> &visited , unordered_map<int,list<int>> &adj){
    visited[src] = true;

    for(auto neig : adj[src]){
        if(!visited[neig]){
            bool cycle = isCycleDFS(neig, src, visited, adj);
            if(cycle){
                return true;
            }
        }
        else if(neig!=parent){
            return true;
        }
    }
    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{

    //making list
    unordered_map<int,list<int>> adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            // bool ans = checkCycleBFS(adj , visited , i);
            bool ans = checkCycleDFS(adj , -1 ,visited , i);
            if(ans==true){
                return "Yes";
            }
        }
    }
    return "No";

    
}

int main(){
    //codestudio question
}