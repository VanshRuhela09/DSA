class Solution {
public:
    int count(int ind , vector<int>& coins , int target ,  vector<vector<int>> &dp){
        if(ind==0){
            if(target%coins[0]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int ntake = count(ind-1,coins,target,dp);
        int take = 0;
        if(target>=coins[ind]){
            take = count(ind,coins,target-coins[ind],dp);
        }
        return dp[ind][target] =  take + ntake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return count(coins.size()-1,coins,amount,dp);
    }
};

// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
//         for(int i=0; i<amount+1; i++){
//             if(i%coins[0]==0){
//                 dp[0][i]=1;
//             }
//             else{
//                 dp[0][i]=0;
//             }
//         }

//         for(int ind = 1; ind<coins.size(); ind++){
//             for(int target=0; target<amount+1; target++){
//                 int ntake = count(ind-1,coins,target,dp);
//                 int take = 0;
//                 if(target>=coins[ind]){
//                     take = count(ind,coins,target-coins[ind],dp);
//                 }
//                 dp[ind][target] =  take + ntake;
//             }
//         }
//         return dp[coins.size()-1][amount];
//     }
// };