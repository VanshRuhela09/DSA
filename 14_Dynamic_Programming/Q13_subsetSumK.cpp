/*
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
*/
class Solution {
  public:
    bool find(int ind , vector<int> &arr , int sum , vector<vector<int>> &dp){
        if(sum==0){
            return true;
        }
        if(ind==0){
            if(arr[0]==sum){
                return true;
            }
            return false;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        bool ntake = find(ind-1,arr,sum,dp);
        bool take = false;
        if(sum>=arr[ind]){
            take = find(ind-1,arr,sum-arr[ind],dp);
        }
        return dp[ind][sum] = (take || ntake);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        //  vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        //  return find(n-1 , arr,sum,dp);
        
        vector<vector<int>> dp(n,vector<int>(sum+1,false));
        for(int ind = 0; ind<n; ind++){
            dp[ind][0] = true;
        }
        if (arr[0] <= sum) // this is not base case this is condition of out of bound
            dp[0][arr[0]] = true;  // this is the base case
        
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
        return dp[n-1][sum];
       
    }
};