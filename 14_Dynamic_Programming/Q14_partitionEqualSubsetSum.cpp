/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/
class Solution {
public:
    bool subsetSum(vector<int>& nums , int ind , int target , vector<vector<int>> &dp){
        if(ind==0){
            if(target==nums[0]){
                return true;
            }
            else{
                return false;
            }
        }
        if(target==0){
            return true;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        bool ntake = subsetSum(nums,ind-1,target,dp);
        bool take = false;
        if(target>=nums[ind]){
            take = subsetSum(nums,ind-1,target-nums[ind],dp);
        }
        return dp[ind][target] = ntake||take;
    }
    bool canPartition(vector<int>& nums) {
        int tsum = 0;
        for(auto i : nums){
            tsum+=i;
        }
        if(tsum%2!=0){
            return false;
        }

        int s = tsum/2;

        vector<vector<int>> dp(nums.size(),vector<int>(s+1,-1));
        return subsetSum(nums , nums.size()-1 , s ,dp);
    }
};