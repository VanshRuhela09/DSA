#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u , int v, bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
 
    void print_graph(){
        for(auto i : adj){
            cout<<i.first<<" - ";
            for(auto j : i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

void BFS(vector<vector<int>> &adj , unordered_map<int , bool> &visited , vector<int> &ans , int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);

        for(auto i : adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    unordered_map<int , bool> visited;

    for(int i = 0; i<n; i++){
        if(!visited[i]){
            BFS(adj, visited, ans, i);
        }
    }
    return ans;

}

};


int main(){


    // solution of codestudio
    int n;
    cout<<"enter number of edges " ;
    cin>>n;
    Graph g;
    for(int i = 0; i<n; i++){
        int u , v;
        cout<<"enter u and v : ";
        cin>>u;
        cin>>v;
        g.addEdge(u,v,0);
    }

    g.print_graph();



    return 0;
}