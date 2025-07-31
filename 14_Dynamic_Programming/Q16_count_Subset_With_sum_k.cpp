/*
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Examples:

Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.
Input: arr[] = [5, 7, 8], target = 3
Output: 0
Explanation: There are no subsets of the array that sum up to the target 3.
Input: arr[] = [35, 2, 8, 22], target = 0
Output: 1
Explanation: The empty subset is the only subset with a sum of 0.
*/
class Solution {
  public:
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
    return dp[ind][k] = take + ntake;
}


int perfectSum(vector<int>& arr, int k)
{
	// Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return find(n-1,k,arr,dp);

    // vector<vector<int>> dp(n,vector<int> (k+1,0));
    // for(int ind = 0; ind<n; ind++){
    //     dp[ind][0] = 1;
    // }

    // if(arr[0]<=k)
    //     dp[0][arr[0]] = 1;
    
    // for(int ind = 1; ind<n; ind++){
    //     for(int k1 = 1; k1<=k; k1++){
    //         int ntake = dp[ind-1][k1];
    //         int take = 0;
    //         if(k1 >= arr[ind]){
    //             take = dp[ind-1][k1-arr[ind]];
    //         }
    //         dp[ind][k1] = take + ntake;
    //     }
    // }
    // return dp[n-1][k];
}

};