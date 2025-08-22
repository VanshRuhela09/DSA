class Union{
    vector<int> parent;
    vector<int> rank;
    pubilc:
    Union(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0 ;i<n; i++){
            parent[i] = i;
        }
    }
	
    int findUlti(int a){
        if(parent[a]==a){
            return a;
        }
        return parent[a] = findUlti(parent[a]);
    }
	
	void UnionByRank(int u , int v){
	   int Ulti_u = findUlti(u);
	   int Ulti_v = findUlti(v);
	   if(Ulti_u == Ulti_v){
	       return;
	   }
	   else if(rank[Ulti_u]==rank[Ulit_v]){
	       parent[Ulti_v] = Ulti_u;
	       rank[Ulti_u]++;
	   }
	   else if(rank[Ulti_u]>rank[Ulti_v]){
	       parent[Ulti_v] = Ulti_u;
	   }
	   else{
	       parent[Ulti_u] = Ulti_v;
	   }
	}
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0; i<V; i++){
            int u = adj[i][0];
            int v = adj[i][1];
            int w = adj[i][2];
            
            edges[i].push_back({w,{u,v}});
        }
        
        sort(edges.begin(),edges.end());
        int wt = 0;
        Union o1(V);
        for(auto i : edges){
            int u = i.second.first;
            int v = i.second.second;
            int w = i.first;
            if(o1.findUlti(u)!=o1.findUlti(v)){
                wt = wt + w;
                UnionByRank(u,v);
            }
            
        }
        return wt;
        
        
    }
};