class Solution{   
public:
    bool check(int ind , vector<int> &arr, int sum , vector<vector<int>> &dp){
        if(sum==0){
            return 1;
        }
        if(ind==0){
            if(sum==arr[0]){
                return 1;
            }
            return 0;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        bool notTake = check(ind-1,arr,sum , dp);
        bool take = 0;
        if(sum>=arr[ind]){
            take = check(ind-1,arr,sum-arr[ind] , dp);
        }
        if(take||notTake){
            return dp[ind][sum] = 1;
        }
        else{
            return dp[ind][sum] = 0;
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
        return check(arr.size()-1,arr,sum , dp);        
    }
};


//=================tabulation=======================
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<bool>> dp(arr.size(),vector<bool>(sum+1,false));
        
        for(int i =0 ;i<arr.size(); i++){
            dp[i][0] = true; // for all index when sum is 0 means target is found.
        }
        dp[0][arr[0]] = true; // when ind==0 and jo bhi us time pe target hai vo 0 index ke element ke equal is true
        for(int ind = 1; ind<arr.size(); ind++){
            for(int j = 1; j<sum+1; j++){
                bool notTake = dp[ind-1][j];
                bool take = false;
                if(j>=arr[ind]){
                    take = dp[ind-1][j-arr[ind]];
                }
                dp[ind][j] = (take || notTake);
                    }
                }
        
        return dp[arr.size()-1][sum];        
    }
};