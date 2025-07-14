class Solution {
public:
bool checkPath(vector<list<int>> &adj , int node , vector<bool> &vis , int dest){
    vis[node] = true;
    if(node==dest){
        return true;
    }
    for(auto i : adj[node]){
        if(!vis[i]){
            bool check = checkPath(adj,i,vis,dest);
            if(check){
                return true;
            }
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n,false);
        vector<list<int>> adj(n);
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return checkPath(adj,source,vis,destination);
    }
};