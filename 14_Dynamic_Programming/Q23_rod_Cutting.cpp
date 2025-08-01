/*
Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: n = size of price, and price[] is 1-indexed array.

Example:

Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
Output: 24
Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.
Input: price[] = [3]
Output: 3
Explanation: There is only 1 way to pick a piece of length 1.
*/

//1D dp
class Solution {
  public:
    int find(int n,vector<int>&price,vector<int>&dp)
    {
        if(n==0)
        {
            return 0;
        }
        
        if(dp[n]!=-1) return dp[n];
        int ans=-1e8;
        for(int i=1;i<=price.size();i++)
        {
            if(n-(i)>=0)
            {
                ans=max(ans,(price[i-1]+find(n-(i),price,dp)));
            }
        }
        return dp[n]= ans;
    }
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<int>dp(n+1,-1);
        return find(n,price,dp);
        
    }
};

//2D dp
class Solution {
  public:
    int find(int ind , int len , vector<int> &price , vector<vector<int>> &dp){
        if(len == 0) return 0;
        if(ind == 0){ // means cut the rod in length 1
            return len * price[ind];
        }
        
        if(dp[ind][len] != -1) return dp[ind][len];
        int ntake = find(ind-1,len,price,dp);
        int take = INT_MIN;
        if(len>=ind+1){
            take = price[ind] + find(ind,len - (ind+1) , price,dp);
        }
        return dp[ind][len] = max(ntake,take);
        
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        int len = n;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return find(n-1,len,price,dp);
    }
};