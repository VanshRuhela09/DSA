/*
here frog can jump i + 1 , i+2 , i + 3 .... i + k
*/
#include <bits/stdc++.h> 

//memoization
int jump(int ind , vector<int> &arr , vector<int> &dp){
    if(ind==0){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int minsteps = INT_MAX;
    for(int j = 1; j<=k; j++){
        if(j-k>=0){
            int jumps = jump(ind-2,arr ,dp) + abs(arr[ind]-arr[ind-2]);
            minsteps = min(minsteps,jumps);
        }
    }
    return dp[ind] = minsteps;

}
int frogJump(int n, vector<int> &heights)
{
    // vector<int> dp(n,-1);
    // return jump(n-1,heights,dp);
    
    //tabulation
    dp[0] = 0;
    for(int ind = 1; ind<n; ind++){
        int minsteps = INT_MAX;
        for(int j = 1; j<=k; j++){
            if(j-k>=0){
                int jumps = dp[ind-2] + abs(arr[ind]-arr[ind-2]);
                minsteps = min(minsteps,jumps);
            }
        }
        dp[ind] = minsteps;
    }
    return dp[n-1];
}