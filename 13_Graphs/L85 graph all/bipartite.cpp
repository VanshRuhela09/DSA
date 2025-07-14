#include<bits/stdc++.h>
using namespace std;
    bool isBipartite(vector<list<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false);
        vector<int> col(n,0);
        queue<int> q;
        for(int k = 0; k<n;k++){
            if(!vis[k]){
                q.push(k);
                vis[k]=true;
                col[k]=0;
            }
            while(!q.empty()){
                int i = q.front();
                q.pop();
                    for(auto j : graph[i]){
                        if(!vis[j]){
                            if(col[i]==0){
                                col[j]=1;
                            }
                            else{
                                col[j]=0;
                            }
                            vis[j]=true;
                            q.push(j);
                        }
                        else{
                            if(col[j]==col[i]){
                                return false;
                            }
                        }
                    }
                 }

        }
        return true;
    }
int main(){

    int n;
    cout<<"enter number of vertices : ";
    cin>>n;
    vector<vector<int>> g(n,vector<int>(n));
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            cin>>g[i][j];
        }
    }
    vector<list<int>> graph(n);
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            if(g[i][j]!=0){
                graph[i].push_back(j);
            }
        }
    }
    
    if(isBipartite(graph)){
        cout<<"Graph is bipartite"<<endl;
    }
    else{
        cout<<"Graph is not partitie"<<endl;
    }

    return 0;
}

/*
0 1 1 0 0 
1 0 1 1 1
1 1 0 1 0
0 1 1 0 1
0 1 0 1 0
*/