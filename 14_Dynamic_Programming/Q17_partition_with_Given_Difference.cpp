/*
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.
*/
#include <bits/stdc++.h> 
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
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totalsum = 0;
    for(auto it : arr){
        totalsum += it;
    }
    if(totalsum-d < 0 || (totalsum-d)%2 !=0) return 0;
    int target = (totalsum-d)/2;
    vector<vector<int>> dp(n , vector<int>(target+1,-1));
    return find(n-1,target,arr,dp);
}