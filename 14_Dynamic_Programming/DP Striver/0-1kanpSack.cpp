class Solution
{
    public:
    int func(int ind , int W , int wt[] , int val[] , vector<vector<int>> &dp){
        if(ind==0){
            if(W>=wt[0]){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[ind][W]!=-1){
            return dp[ind][W];
        }
        int notTake = func(ind-1,W,wt,val,dp);
        int take = INT_MIN;
        if(W>=wt[ind]){
            take = val[ind] + func(ind-1,W-wt[ind],wt,val,dp);
        }
        
        return dp[ind][W] = max(take,notTake);
    }
    int knapSack(int W, int wt[], int val[], int n)
    { 
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        
       return func(n-1,W,wt,val,dp);
    }
};

//============tabulation=============
// class Solution
// {
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n)
//     { 
//         vector<vector<int>> dp(n,vector<int>(W+1,0));
//         for(int i = wt[0]; i<=W; i++){
//             dp[0][i] = val[0];
//         }
//         for(int i = 1; i<n; i++){
//             for(int w = 0; w<=W; w++){
//                 int notTake = 0 + dp[i-1][w];
//                 int take = INT_MIN;
//                 if(w>=wt[i]){
//                     take = val[i] + dp[i-1][w-wt[i]];
//                 }
                
//                 dp[i][w] = max(take,notTake);
//             }
//         }
        
//        return dp[n-1][W];
//     }
// };