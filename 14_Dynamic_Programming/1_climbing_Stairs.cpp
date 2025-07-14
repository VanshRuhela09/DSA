/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
*/
class Solution {
public:
    int climb(int k , vector<int> & dp){
        if(k==1 || k==2) return k;
        if(dp[k]!=-1){
            return dp[k];
        }
        return dp[k] = climb(k-1,dp) + climb(k-2,dp);

    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[1] = 1;
        if(n>=2) dp[2] = 2;
    
        for(int k = 3; k<=n; k++){
            dp[k] = dp[k-1] + dp[k-2];
        }
        return dp[n];
        // return climb(n,dp); this is for memoization
    }
};