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
    int find(int ind , int buy , int cap , vector<int>& prices , vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(ind==prices.size()-1){
            if(!buy){
                return prices[ind]; // means abhi sell karna hai jo buy kia hua hai
            }
            else{
                return 0; // means koi buy nahi kia hua hai to return 0 profit.
            }
        }
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit = 0;
            if(buy){
                profit = max( -(prices[ind]) + find(ind+1,0,cap,prices , dp) , find(ind+1,1,cap,prices , dp));
            }
            else{
                profit = max( prices[ind] + find(ind+1,1,cap-1,prices , dp) ,find(ind+1,0,cap,prices , dp));
            }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k , vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));

        // for(int i = 0; i<n; i++){
        //     for(int buy = 0; buy<2; buy++){
        //         dp[i][buy][0] = 0;
        //     }
        // }

        // for(int buy = 0; buy<2; buy++){
        //     for(int cap = 1; cap<3; cap++){
        //         if(buy==0){
        //             dp[n-1][buy][cap] =  prices[n-1];
        //         }
        //         else{
        //             dp[n-1][buy][cap] = 0;
        //         }
        //     }
        // }

        // for(int ind = n-2; ind>=0; ind--){
        //     for(int buy=0; buy<2;buy++){
        //         for(int cap = 1; cap<3; cap++){
        //             int profit = 0;
        //             if(buy){
        //                 profit = max( -(prices[ind]) + dp[ind+1][0][cap] , dp[ind+1][1][cap]);
        //             }
        //             else{
        //                 profit = max( prices[ind] + dp[ind+1][1][cap-1] ,dp[ind+1][0][cap]);
        //             }
        //         dp[ind][buy][cap] = profit;
        //         }
        //     }
        // }

        return find(0,1,k,prices,dp);
        // return dp[0][1][2];
    }
};
