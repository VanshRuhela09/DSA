/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int> , int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }

        int time = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            if(tm>time) time = tm; // if we get more time than previous
            for(int delrow = -1; delrow<=1; delrow++){
                for(int delcol = -1; delcol<=1; delcol++){
                    if(abs(delrow)!=abs(delcol)){
                        int nrow = r + delrow;
                        int ncol = c + delcol;
                        if((nrow>=0 && ncol >=0) && (nrow <n && ncol<m) && vis[nrow][ncol]!=2 && grid[nrow][ncol] == 1){
                            q.push({{nrow,ncol} , tm + 1}); // the time will +1 
                            vis[nrow][ncol] = 2;
                        }
                    }
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]!=2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};