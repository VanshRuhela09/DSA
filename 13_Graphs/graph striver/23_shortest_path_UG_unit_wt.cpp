// single scr shortest path (BFS) (we used distance array to store the distance from src node to all nodes)
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int v = adj.size();
        vector<int> dist(v,INT_MAX);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto it : adj[top]){
                if(dist[top] + 1 < dist[it]){
                    dist[it] = dist[top] + 1;
                    q.push(it);
                 }
            }
        }
        for(int i = 0; i<v; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }

        }
        return dist;
    }
};

//this is done using bfs and with parent array
// we will find the distance by parent array 
#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int,list<int>> adj;
	for(int i = 0; i<edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	parent[s] = -1;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto neig : adj[front]){
			if(!visited[neig]){
				q.push(neig);
				visited[neig] = 1;
				parent[neig] = front;
			}
		}
	}

	vector<int> ans;
	int current_node = t;
	ans.push_back(t);
	while(current_node!=s){
		current_node = parent[current_node];
		ans.push_back(current_node);
	}

	reverse(ans.begin() , ans.end());

	return ans;
}
