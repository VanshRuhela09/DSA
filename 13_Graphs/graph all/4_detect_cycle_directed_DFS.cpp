#include<bits/stdc++.h>
bool DFSDetectCycle(int node , unordered_map<int,bool> &visited , unordered_map<int,bool> &DFSvisited , unordered_map<int,list<int>> &adj){
    visited[node] = true;
    DFSvisited[node] = true;

    for(auto neig : adj[node]){
      if(!visited[neig]){
        bool cycledet = DFSDetectCycle(neig,visited,DFSvisited,adj);
        if(cycledet==true){
          return true;
        }
      }
      else if(DFSvisited[neig]==true) {
          return true;
      }
    }
    DFSvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
  for(int i = 0; i<n; i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> DFSvisited;


  for(int i =1; i<=n; i++){

    if(!visited[i]){
      bool detect = DFSDetectCycle(i,visited,DFSvisited,adj);
      if(detect){
        return true;
      }
    }

  }
  return false;
  
}