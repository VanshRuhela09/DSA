class Solution {
    private:
    int timer = 1;
    int child = 0;
    public:
    void DFS(int node , int parent , vector<int> &insert , vector<int> &low , vector<bool> &visited , vector<int> &mark , vector<int> adj[]){
        visited[node] = 1;
        insert[node] = low[node] = timer;
        timer++;
        for(auto neig : adj[node]){
            if(neig==parent) continue;  // this is because is we don't use this so jab (!vis[neig]) vali condition false hogi toh vo else me chala jayega and curr node ka lowInsert set kar dega
            if(!visited[neig]){
                DFS(neig,node,insert,low,visited,mark,adj);
                low[node] = min(low[node] , low[neig]);
                if(low[neig] >= insert[node] && parent!=-1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node] , insert[neig]);
            }
        }
        if(child>1 && parent==-1){
            mark[node] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> insert(V);
        vector<int> low(V);
        vector<bool> visited(V,false);
        vector<int> mark(V,0);
        vector<int> ans;
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                DFS(i,-1,insert,low,visited,mark,adj);
            }            
        }
        
        for(int i = 0; i<V; i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        
        if(ans.size()==0){
            return {-1};
        }
        return ans;
        
        
        
    }
};