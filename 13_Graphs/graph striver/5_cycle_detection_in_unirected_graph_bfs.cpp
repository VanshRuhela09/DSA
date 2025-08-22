#include<unordered_map>
#include<queue>
#include<list>

bool checkCycleBFS(unordered_map<int,list<int>> &adj , unordered_map<int,bool> &visited , int node){
    unordered_map<int,int> parent;
    parent[node] = -1;
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neig : adj[front]){
            if(visited[neig]==true && neig != parent[front]){
                return true;
            }
            else{
                if(!visited[neig]){
                    q.push(neig);
                    visited[neig] = 1;
                    parent[neig] = front;
                }
            }
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