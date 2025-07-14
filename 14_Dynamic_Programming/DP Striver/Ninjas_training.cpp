int ret(int prev , int n , vector<vector<int>> points , vector<vector<int>> &dp){
    if(n==0){
        int maxi = 0;
        for(int i =0; i<3; i++){
            if(i!=prev){
                maxi = max(maxi,points[n][i]);
            }
        }
        return maxi;
    }
    if(dp[n][prev]!=-1){
        return dp[n][prev];
    }
    int maxi = 0;
    for(int i =0; i<3; i++){
        if(prev!=i){
            int p = points[n][i] + ret(i,n-1,points,dp);
            maxi = max(p,maxi);
        }
    }
    return dp[n][prev] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n,vector<int>(4,-1));
   return ret(3,n-1,points, dp);
}

//        =================tabulation==============
// int ninjaTraining(int n, vector<vector<int>> &points) {
//     vector<vector<int>> dp(n,vector<int>(4,-1));
//     dp[0][0] = max(points[0][1],points[0][2]);
//     dp[0][1] = max(points[0][0],points[0][2]);
//     dp[0][2] = max(points[0][0],points[0][1]);
//     dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
//     for(int day =1; day<n; day++){
//         for(int last =0; last<4; last++){
//             dp[day][last] = 0;
//             for(int task=0; task<3; task++){
//                 if(task!=last){
//                     int p = points[day][task] + dp[day-1][task];
//                     dp[day][last] = max(p,dp[day][last]);
//                 }
//             }
//         }
//     }
//    return dp[n-1][3];
// }
