class Solution{
public:
    int find(int i , int j, int arr[] , vector<vector<int>> &dp){
        if(i==j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int k = i; k<=j-1; k++){
            int operations = arr[i-1] * arr[k] * arr[j] +  find(i,k,arr,dp) + find(k+1,j,arr,dp);
            mini = min(operations,mini);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N , vector<int>(N,-1));
        return find(1,N-1,arr,dp);
        
    }
};

// =============tabulation===========
// class Solution{
// public:
//     int matrixMultiplication(int N, int arr[])
//     {
//         vector<vector<int>> dp(N , vector<int>(N,-1));
//         for(int i = 0; i<N; i++){
//             for(int j = 0; j<N; j++){
//                 if(i==j){
//                     dp[i][j] = 0;
//                 }
//             }
//         }
        
//         for(int i = N-1; i>=1; i--){
//             for(int j = i+1; j<N; j++){
//                     int mini = INT_MAX;
//                     for(int k = i; k<=j-1; k++){
//                         int operations = arr[i-1] * arr[k] * arr[j] +  dp[i][k] + dp[k+1][j];
//                         mini = min(operations,mini);
//                     }
//                     dp[i][j] = mini;
//             }
//         }
        
//         return dp[1][N-1];
        
//     }
// };