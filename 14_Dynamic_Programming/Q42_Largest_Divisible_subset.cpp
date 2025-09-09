/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<int> ans , hash(n) , dp(n,1);

        int maxi = 0;
        int maxInd = 0;
        for(int i = 0; i<n; i++){
            hash[i] = i;
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        hash[i] = j;
                    }
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                maxInd = i;
            }
        }

        int i = maxInd;
        while(i != hash[i]){
            ans.push_back(nums[i]);
            i = hash[i];
        }
        
        ans.push_back(nums[i]);

        return ans;
    }
};