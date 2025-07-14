class Solution {
public:
    bool subsetSum(vector<int>& nums , int ind , int target , vector<vector<int>> &dp){
        // we can do tabulation here also.
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