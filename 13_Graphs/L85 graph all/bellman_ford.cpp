class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e8);
        dist[S] = 0;
        for(int i = 0; i<V-1; i++){
            for(auto i : edges){
                int u = i[0];
                int v = i[1];
                int w = i[2];
                // this != 1e8 because no change in distace array if dist[u] is infinite or we can use continue; statement here to skip this iteration
                if(dist[u] != 1e8 && dist[u]+w < dist[v]){
                    dist[v] = dist[u] + w;
                }
                
            }
        }
        // this is nth iteration agar isme if condition chali toh negative cycle is present return {-1};
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            if(dist[u] != 1e8 && dist[u] + w <dist[v]){
                return {-1};
            }
        }
        
        return dist;
        
    }
};