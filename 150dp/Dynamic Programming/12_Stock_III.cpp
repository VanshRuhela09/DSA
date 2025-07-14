/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 
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
        int profit = 0; // we can take any value of profit because it will update below.
            if(buy){
                profit = max( -(prices[ind]) + find(ind+1,0,cap,prices , dp) , find(ind+1,1,cap,prices , dp));
            }
            else{
                profit = max( prices[ind] + find(ind+1,1,cap-1,prices , dp) ,find(ind+1,0,cap,prices , dp));
            }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        for(int i = 0; i<n; i++){
            for(int buy = 0; buy<2; buy++){
                dp[i][buy][0] = 0;
            }
        }

        for(int buy = 0; buy<2; buy++){
            for(int cap = 1; cap<3; cap++){
                if(buy==0){  
                    dp[n-1][buy][cap] =  prices[n-1];
                }
                else{
                    dp[n-1][buy][cap] = 0;
                }
            }
        }

        for(int ind = n-2; ind>=0; ind--){
            for(int buy=0; buy<2;buy++){
                for(int cap = 1; cap<3; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max( -(prices[ind]) + dp[ind+1][0][cap] , dp[ind+1][1][cap]);
                    }
                    else{
                        profit = max( prices[ind] + dp[ind+1][1][cap-1] ,dp[ind+1][0][cap]);
                    }
                dp[ind][buy][cap] = profit;
                }
            }
        }

        // return find(0,1,2,prices,dp);
        return dp[0][1][2];
    }
};

/*

class Solution {
public:
    int f(int i , int j , vector<int>& prices){
        int maxProf = 0;
        while(i<prices.size() && j<prices.size()){
             int prof = prices[j] - prices[i];
            if(prof>=0){
                if(prof>maxProf){
                    maxProf = prof;
                }
                j++;
            }
            else{
                i = j;
                j++;
            }

        }
        return maxProf;
    }
    int find(int i , int j , vector<int>& prices){

        if(i==prices.size() || j==prices.size()){
            return 0;
        }
        vector<int> temp;
        for(int k = i; k<=j; k++){
            temp.push_back(prices[k]);
        }
        int prof1= f(i,i+1,temp);
        int prof2 = f(j+1,j+2,prices);


        int currProf = prof1 + prof2;
        
        int p1 = find(i+1,j+1,prices);
        int p2 = find(i,j+1,prices);
        return max(currProf , max(p1,p2));

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        return find(0,1,prices);
    }
};

*/