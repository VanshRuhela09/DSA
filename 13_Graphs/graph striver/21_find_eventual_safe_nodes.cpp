/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
*/

class Solution {
public:
    /*
        this is DFS code
        BFS (kahns algo) code is below this multiline comment
        
        class Solution {
public:
    bool dfs(vector<vector<int>>& graph , int node , vector<int> &vis , vector<int> &dfsVis , vector<int> &safe){
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]){
                bool check = dfs(graph,it,vis,dfsVis,safe);
                if(check){
                    safe[node] = 0;
                    return true;
                }
            }
            else if(dfsVis[it]){
                safe[node] = 0;
                return true;
            }
        }

        safe[node] = 1;  // marking this node as safe bcs if this node coplete the dfs properly that means the node is safe and if this node contain cycle then the flow will not reach here and return true ho jayega upar hi
        dfsVis[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v,0);
        vector<int> dfsVis(v,0);

        vector<int> safe(v,1);
        for(int i = 0; i<v; i++){
            if(!vis[i]){
                dfs(graph,i,vis,dfsVis,safe);
            }
        }
        vector<int> ans;
        for(int i = 0; i<v; i++){
            if(safe[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
*/

    //BFS solution (kahns algo)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> revGraph(v);

        //reversing the graph
        for(int i = 0; i<v; i++){
            for(auto it : graph[i]){
                revGraph[it].push_back(i);
            }
        }
        vector<int> indegree(v,0);
        //finding indegree of graph
        for(auto it : revGraph){
            for(auto it2 : it){
                indegree[it2]++;
            }
        }

        //applying simple kahns algo.
        queue<int> q;
        for(int i = 0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto it : revGraph[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        //if indegree of graph is 0 that is safe node
        for(int i = 0; i<v; i++){
            if(indegree[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};