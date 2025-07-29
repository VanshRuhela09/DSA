/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
*/
class Solution {
public:
    int findMinPath(int i , int j , int n , vector<vector<int>>& matrix , vector<vector<int>> &dp){
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans1 = 1e8;
        // or we can made seperate call for each of 3 situation
        for(int r = -1; r<2; r++){
            int newJ = j + r;
            if(newJ >=0 && newJ <n ){
                int temp = matrix[i][j] + findMinPath(i + 1, newJ , n , matrix , dp);
                ans1 = min(ans1 , temp);
            }
        }
        return dp[i][j] = ans1;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = 1e8;
        int n = matrix.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // for(int k = 0; k<n; k++){
        //     ans = min(ans,findMinPath(0,k,n,matrix,dp));
        // }

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        // this is base case or we can initialize the dp array by 0
        for(int j = 0; j<=n; j++){
            dp[n][j] = 0;
        }

            for(int i = n-1; i>=0; i--){
                for(int j = n-1; j>=0; j--){
                    int ans1 = 1e8;
                    for(int r = -1; r<2; r++){ //this is constant loop
                        int newJ = j + r;
                        if(newJ >=0 && newJ <n ){
                            int temp = matrix[i][j] + dp[i + 1][newJ];
                            ans1 = min(ans1 , temp);
                        }
                    }
                    dp[i][j] = ans1;
                }
            }
        //this is outer for loop to finding the minimum of the first row of dp where ans are stored
        for(int k = 0; k<n; k++){
            ans = min(ans,dp[0][k]);
        }

        return ans;
    }
};