/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        //here we are not taking the priority queue so we may put wt in the queue bcs we can find the dist by dist[topnode]
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        int d = INT_MAX;

        // we have taken -1 stops bcs there will be 0 stops between src and adj of src so that (-1 + 1 = 0) so 0 stops
        q.push({-1,{src,0}});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int stops = top.first;
            int node = top.second.first;
            int topWt = top.second.second;

            if(stops > k){
                break;  //break here bcs now either we get answer in d or we get d = INT_MAX as it is
            }
            else if(node == dst){
                d = min(d,topWt); // store the ans bcs may be we will get some rotue having stops < k with less wt
            }

            for(auto it : adj[node]){
                int v = it.first;
                int vw = it.second;
                if(topWt + vw < dist[v]){
                    dist[v] = topWt + vw;
                    q.push({stops+1,{v,dist[v]}});
                }
            }
        }
        return d==INT_MAX?-1:d;
    }
};