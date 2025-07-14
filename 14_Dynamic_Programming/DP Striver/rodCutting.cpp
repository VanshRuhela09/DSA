class Solution{
  public:
    int find(int price[] , int n , vector<int> &dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int maxi = INT_MIN;
        for(int i= 1; i<=n;i++){
            maxi = max(maxi,price[i-1]+find(price,n-i,dp));
        }
        return dp[n] = maxi;
    }
    int cutRod(int price[], int n) {
        vector<int> dp(n+1,-1);
        return find(price,n,dp);
    }
};

//======tabulation========
// class Solution{
//   public:
//     int find(int price[] , int n , vector<int> &dp){
//         if(n==0){
//             return 0;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         int maxi = INT_MIN;
//         for(int i= 1; i<=n;i++){
//             maxi = max(maxi,price[i-1]+find(price,n-i,dp));
//         }
//         return dp[n] = maxi;
//     }
//     int cutRod(int price[], int n) {
//         vector<int> dp(n+1,-1);
//         int maxi = INT_MIN;
//         dp[0]=0;
//         for(int j = 1; j<=n; j++){
//             for(int i= 1; i<=j;i++){
//             maxi = max(maxi,price[i-1]+dp[j-i]);
//         }
//         dp[j] = maxi;
//         }
//         return dp[n];
//     }
// };