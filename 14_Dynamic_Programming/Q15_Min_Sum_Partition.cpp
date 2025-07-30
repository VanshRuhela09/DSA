/*
Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.

Examples:

Input: arr[] = [1, 6, 11, 5]
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 
Hence, minimum difference is 1.  
Input: arr[] = [1, 4]
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4
Hence, minimum difference is 3.
Input: arr[] = [1]
Output: 1
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {}, sum of Subset2 = 0
Hence, minimum difference is 1.
*/

class Solution {

  public:
  vector<vector<int>> isSubsetSum(vector<int>&arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,false));
        for(int ind = 0; ind<n; ind++){
            dp[ind][0] = true;
        }
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            for(int sum1 = 1; sum1<=sum; sum1++){
                bool ntake = dp[ind-1][sum1];
                bool take = false;
                if(sum1>=arr[ind]){
                    take = dp[ind-1][sum1-arr[ind]];
                }
                dp[ind][sum1] = (take || ntake);
            }
        }
        return dp;
       
    }
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        vector<vector<int>> dp = isSubsetSum(nums,sum);
        int mini = INT_MAX;
        for(int i = 0; i<=sum; i++){
            if(dp[n-1][i] == true){
                int s1 = i;
                int s2 = sum - s1;
                mini = min(mini , abs(s1-s2));
            }
        }
        return mini;
    }
};
