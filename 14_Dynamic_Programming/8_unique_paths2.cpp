/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 
*/

class Solution {
public:
    int find(int r , int c ,int m , int n , vector<vector<int>> &obstacleGrid , vector<vector<int>> &dp){

        if(obstacleGrid[m-1][n-1]==1) return 0;

        if(r==m-1 && c==n-1) return 1;

        // if(r==m || c == n) return 0; this is the base case we have handle seperately below

        if(obstacleGrid[r][c]==1){
            return 0;
        }
        if(dp[r][c]!=-1) return dp[r][c];

        int move_right = 0;
        if(c+1<n){ // or we can put this base case in top
            move_right = find(r,c+1,m,n,obstacleGrid,dp);
        }
        int move_down = 0;
        if(r+1<m){ //or we can put this base case on top
           move_down = find(r+1,c,m,n,obstacleGrid,dp);
        }
        return dp[r][c] = move_down + move_right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        if(obstacleGrid[m-1][n-1]!=1){
            dp[m-1][n-1] = 1;
        }
        else{
            return 0;
        }
        for(int r = m-1; r>=0; r--){
            for(int c = n-1; c>=0; c--){
                if(r==m-1 && c==n-1){  // this is becasue we have set the value os dp[m-1][n-1]
                    continue;
                }
                if(obstacleGrid[r][c]==1){
                    dp[r][c] = 0;
                    continue;
                }
                long long move_right = 0;
                if(c+1<n){
                    move_right = dp[r][c+1];
                }
                long long move_down = 0;
                if(r+1<m){
                move_down = dp[r+1][c];
                }
                dp[r][c] = move_down + move_right;
            }
        }
        // return find(0,0,m,n,obstacleGrid,dp);
        return dp[0][0];
    }
};