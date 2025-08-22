class Solution{
    public:

void DFS(int node , stack<int> &st , vector<bool> &visited, vector<vector<int>>& adj){
	    visited[node] = 1;
	    for(auto i : adj[node]){
	        if(!visited[i]){
	            DFS(i,st,visited,adj);
	        }
	    }
        st.push(node);
	}
	
	void DFS2(int node , stack<int> &st , vector<bool> &visited2 , unordered_map<int,list<int>> &adj2){
	    visited2[node] = 1;
	    for(auto i : adj2[node]){
	        if(!visited2[i]){
	            DFS2(i,st,visited2,adj2);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<bool> visited(V,0);
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                DFS(i,st,visited,adj);
            }
        }
     
        
        unordered_map<int,list<int>> adj2;
        for(int i = 0; i<V; i++){
            int u = i;
            for(auto j : adj[i]){
                int v = j;
                adj2[v].push_back(u);
            }
            
        }
        
        int count = 0;
        vector<bool> visited2(V,0);
        
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!visited2[top]){
                DFS2(top,st,visited2,adj2);
                count++;
            }
        }
        
        return count;
    }

    }