/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

class Solution {
public:
    int find(int ind ,int buy , int k , int n, vector<int> &prices , vector<vector<vector<int>>> &dp){
        if(k == 0) return 0;
        if(ind == n) return 0;

        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];

        int ntake = find(ind+1,buy,k,n,prices,dp);

        int take = -1e8;
        if(buy){
            take = -prices[ind] + find(ind+1,!buy,k,n,prices,dp);
        }
        else{
            take = prices[ind] + find(ind+1,!buy,k-1,n,prices,dp);
        }
        return dp[ind][buy][k] = max(take,ntake);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return find(0,1,k,n,prices,dp);
    }
};