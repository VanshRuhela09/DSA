

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
    
    // dp[0][0] = 1;
    
    // if(arr[0] <= k){
    //     dp[0][arr[0]] = 1;
    // }
    
    
    // if(arr[0] == 0){
    //     dp[0][0] = 2;
    // }
    
    
    
    // for(int ind = 1; ind<n; ind++){
    //     for(int k1 = 0; k1<=k; k1++){
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


