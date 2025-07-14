#include <bits/stdc++.h> 
int jump(int ind , vector<int> &arr , vector<int> &dp){
    if(ind==0){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int left = jump(ind-1,arr , dp) + abs(arr[ind] - arr[ind-1]);
    int right=INT_MAX;
    if(ind>1){
        right = jump(ind-2,arr ,dp) + abs(arr[ind]-arr[ind-2]);
    }
    return dp[ind] = min(left,right);

}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
    return jump(n-1,heights,dp);
}