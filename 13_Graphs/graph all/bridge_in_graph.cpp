class Solution {
    private:
    int timer = 1;
public:
    void DFS(int node , int parent , vector<int> &insert , vector<int> &lowInsert ,  vector<bool> &visited , vector<vector<int>> &ans , unordered_map<int,list<int>> &adj){
        visited[node] = 1;
        insert[node] = timer;
        lowInsert[node] = timer;
        timer++;
        
        for(auto neig : adj[node]){  
            if(neig==parent) continue;  // this is because is we don't use this so jab (!vis[neig]) vali condition false hogi toh vo else me chala jayega and curr node ka lowInsert set kar dega
            if(!visited[neig]){
                DFS(neig , node , insert , lowInsert , visited , ans , adj);
                lowInsert[node] = min(lowInsert[node] , lowInsert[neig]);
                if(lowInsert[neig] > insert[node]){
                    ans.push_back({neig,node});
                }
            }
            else{
                lowInsert[node] = min(lowInsert[node] , lowInsert[neig]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>> adj;
        for(int i = 0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> insert(n);
        vector<int> lowInsert(n);
        vector<bool> visited(n,0);
        vector<vector<int>> ans;
        DFS(0,-1,insert,lowInsert,visited,ans,adj);
        return ans;
        
    }
};