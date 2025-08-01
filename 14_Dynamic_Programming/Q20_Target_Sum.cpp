/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1

*/

//code is same as partition with given difference
class Solution {
public:
int mod = 1e9+7;
int find(int ind , int k ,vector<int>& arr , vector<vector<int>>& dp ){
    if(ind == 0){
        if(k == 0 && arr[0] == 0) return 2;
        if(k == 0 || k == arr[0]) return 1;
        return 0;
    }
    if(dp[ind][k] != -1) return dp[ind][k];
    int ntake = find(ind-1,k,arr,dp);
    int take = 0;
    if(k >= arr[ind]){
        take = find(ind-1,k-arr[ind],arr,dp);
    }
    return dp[ind][k] = (take + ntake)%mod;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int d = target;
        int n = nums.size();
        int totalsum = 0;
        for(auto it : nums){
            totalsum += it;
        }
        if(totalsum-d < 0 || (totalsum-d)%2 !=0) return 0;
        int t = (totalsum-d)/2;
        vector<vector<int>> dp(n , vector<int>(t+1,-1));
        return find(n-1,t,nums,dp);
        }
};