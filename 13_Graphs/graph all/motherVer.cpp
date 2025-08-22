class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int node , vector<bool> &vis , vector<int>adj[]){
        vis[node] = true;
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(i,vis,adj);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	   vector<bool> vis(V,false);
	   int v = 0;
	   for(int i =0; i<V; i++){
	       if(!vis[i]){
	           dfs(i,vis,adj);
	           v = i;
	       }
	   }
	   
	   fill(vis.begin(),vis.end(),false);
	   dfs(v,vis,adj);
	   
	   for(auto i : vis){
	       if(!i){
	           return -1;
	       }
	   }
	   return v;
	}

};