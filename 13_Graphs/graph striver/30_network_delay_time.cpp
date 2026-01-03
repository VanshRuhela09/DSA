/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }

        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        int maxAns = INT_MIN;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto t = pq.top();
            int topW = t.first;
            int topN = t.second;
            pq.pop();
            for(auto it : adj[topN]){
                int vw = it.second;
                int v = it.first;
                if(topW + vw < dist[v]){
                    dist[v] = topW + vw;
                    pq.push({dist[v],v});
                }
            }
        }

        for(int i = 1; i<=n;i++){
            maxAns = max(dist[i],maxAns);
        }
        return maxAns==INT_MAX ? -1 : maxAns;

    }
};