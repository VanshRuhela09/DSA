/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/


//ultra optimized approach
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> dp(n,1);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i] , 1 + dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }


//tabulation + space optimization
int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1) return 1;
        // vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0)); dp array for memoization.
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0)); // this is for tabulation
        for(int ind = nums.size()-1; ind>=0; ind--){
            for(int prev = ind-1; prev>=-1; prev--){
                int ntake = dp[ind+1][prev+1];
                int take = INT_MIN;
                if(prev==-1 || nums[ind]>nums[prev]){
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(ntake , take);
            }
        }
        // return find(0,-1,nums,dp);
        return dp[0][-1+1];
    }




//memoization + tabulation
class Solution {
public:
    int find(int ind , int prev , vector<int>& nums ,  vector<vector<int>> &dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int ntake = find(ind+1,prev,nums,dp);
        int take = INT_MIN;
        if(prev==-1 || nums[ind]>nums[prev]){
            take = 1 + find(ind+1,ind,nums,dp);
        }
        return dp[ind][prev+1] = max(ntake , take);
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1) return 1;
        // vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0)); dp array for memoization.
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0)); // this is for tabulation
        
        for(int ind = nums.size()-1; ind>=0; ind--){
            for(int prev = ind-1; prev>=-1; prev--){
                int ntake = dp[ind+1][prev+1];
                int take = INT_MIN;
                if(prev==-1 || nums[ind]>nums[prev]){
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(ntake , take);
            }
        }
        // return find(0,-1,nums,dp);
        return dp[0][-1+1];
    }
};
