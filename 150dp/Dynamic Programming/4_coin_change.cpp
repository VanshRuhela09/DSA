/*

 You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 
*/
//1d dp
class Solution {
public:
    int find(vector<int>& coins, int amount,vector<int>&dp){
        if(amount == 0) return 0;

        if(dp[amount]!=-1) return dp[amount];
        int coi = 1e8;
        for(auto it : coins){
            if(amount >= it){
                int sub = 1 + find(coins,amount - it,dp);
                coi = min(sub,coi);
            }
        }
        return dp[amount] = coi;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        // int ans = find(coins,amount,dp);
        // if(ans == 1e8) return -1;
        // return ans;

        dp[0] = 0;
        for(int i = 1; i<=amount; i++){
            int coi = 1e8;
            for(auto it : coins){
                if(i >= it){
                    int sub = 1 + dp[i - it];
                    coi = min(sub,coi);
                }
            }
            dp[i] = coi;
        }

        if(dp[amount]==1e8) return -1;
        return dp[amount];
    }
};

//2d dp
class Solution {
public:
    int find(int i,vector<int>&coins,int am,int n,vector<vector<int>>&dp)
    {
        if(am==0) return 0;
        else if(i==n) return 1e8;

        if(dp[i][am]!=-1) return dp[i][am];
        int ntake=find(i+1,coins,am,n,dp);
        int take=1e8;
        if(am>=coins[i])
        {
            take=1+find(i,coins,am-coins[i],n,dp);
        }
        return dp[i][am]= min(take,ntake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= find(0,coins,amount,n,dp);
        if(ans==1e8) return -1;
        else return ans;
    }
};