/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/

class Solution {
    int memoization(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 && n == 0)
            return 1;
        if (m < 0 || n < 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        int l = memoization(m, n - 1, dp);
        int t = memoization(m - 1, n, dp);
        return dp[m][n] = l + t;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memoization(m - 1, n - 1, dp);
        dp[0][0] = 1;

        for(int m1 = 0; m1<m; m1++){
            for(int n1 = 0; n1<n; n1++){
                int l = 0 , t = 0;
                if(m1 == 0 && n1 == 0) continue;
                if(n1>0){ //handling the (n<0) basecase seperately or we can change the tabulation and put condition when the memoization function is calling
                    l = dp[m1][n1 - 1];
                }
                if(m1>0){//handling the (m<0) basecase seperately or we can change the tabulation and put condition when the memoization function is calling
                    t = dp[m1 - 1][n1];
                }
                dp[m1][n1] = l + t;
            }
        }
        return dp[m-1][n-1];
    }
};
