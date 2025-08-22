#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
  for(int i = 0; i<edges.size(); i++){
    int u = edges[i].first - 1;
    int v = edges[i].second - 1;

    adj[u].push_back(v);
  }


  vector<int> indegree(n);
  for(auto i : adj){
    for(auto j : i.second){
      indegree[j]++;
    }
  }

  int count = 0;
  queue<int> q;
  for(int i = 0; i<n; i++){
    if(indegree[i]==0){
      q.push(i);
    }
  }

  while(!q.empty()){
    int front = q.front();
    q.pop();
    count++;
    for(auto i : adj[front]){
      indegree[i]--;
      if(indegree[i]==0){
        q.push(i);
      }
    }

  }
  if(count==n){
    return false;
  }
  else{
    return true;
  }

}