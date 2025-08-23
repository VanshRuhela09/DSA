/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

class Solution {
public:
    bool canDo(int i ,  vector<bool> &dfsVis ,  vector<bool> &vis , vector<vector<int>> &adj){
        vis[i]=true;
        dfsVis[i]=true;
        for(auto neig : adj[i]){
            if(!vis[neig]){
                bool isCycle = canDo(neig,dfsVis,vis,adj);
                if(isCycle) return true;
            }
            else if(dfsVis[neig]==true){
                return true;
            }
        }
        dfsVis[i]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        if(prerequisites.size()==0) return true;
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> dfsVis(numCourses,false);
        for(int i = 0; i<prerequisites.size(); i++){
            if(!vis[prerequisites[i][0]]){
                bool check = canDo(prerequisites[i][0],dfsVis,vis,adj);
                if(check) return false;
            }
        }
        return true;
    }
};