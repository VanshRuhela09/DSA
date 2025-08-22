/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 
Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
*/

//can be done by bfs and dfs by building proper graph
class Solution {
public:
int findParent(int u , vector<int> &parent){
    if(parent[u]==u) return u;
    return findParent(parent[u],parent);
}
void union1(int u , int v , vector<int> &parent , vector<int> &rank){
    int p1 = findParent(u,parent);
    int p2 = findParent(v,parent);
    if(p1==p2) return;
    else{
        if(rank[p1]>rank[p2]){
            parent[p2] = p1;
        }
        else if(rank[p1]<rank[p2]){
            parent[p1] = p2;
        }
        else{
            parent[p1] = p2;
            rank[p1]++;
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<int> nodes;
        int n = isConnected.size();
        vector<int> rank(n,0);
        vector<int> parent(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]==1){
                    union1(i,j,parent,rank);
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(i==parent[i]){
                ans++;
            }
        }
        return ans;
    }
};