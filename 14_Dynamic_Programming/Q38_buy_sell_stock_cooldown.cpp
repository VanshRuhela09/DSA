/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
*/
class Solution {
public:
    int find(int ind , int buy , int n , vector<int> &prices , vector<vector<int>> &dp){
        if(ind >= n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int ntake = find(ind+1 , buy , n , prices , dp);

        int take = -1e8;
        if(buy){
            take = -prices[ind] + find(ind+1 , !buy , n , prices , dp);
        }
        else{
            take = prices[ind] + find(ind+2 , !buy , n , prices , dp);
        }
        return dp[ind][buy] = max(take , ntake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return find(0,1,n,prices,dp);
    }
};