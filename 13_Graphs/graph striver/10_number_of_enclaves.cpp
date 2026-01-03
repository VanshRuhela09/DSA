/*
you are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
*/
class Solution {
public:
    void dfs(vector<vector<int>> &grid , vector<vector<bool>> &vis , int r , int c , int m , int n){
        vis[r][c] = true;
        int delr[] = {1,0,-1,0};
        int delc[] = {0,-1,0,1};
        for(int i = 0; i<4; i++){
            int nrow = r + delr[i];
            int ncol = c + delc[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                dfs(grid,vis,nrow,ncol,m,n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1 && (i==0 || i==m-1 || j==0 || j==n-1) && vis[i][j]==false){
                    dfs(grid,vis,i,j,m,n);
                }
            }
        }

        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    count++;
                }
            }
        }
        return count;
    }
};