class Solution {
public:
    int find(string &s , string &t , int i , int j , vector<vector<int>> &dp){

        if(j == 0) return 1; //if j is negative means we got the subsequence
        if(i == 0) return 0;  // means i is -ve and j >=0 means we haven't find the string so return 0

        if(dp[i][j] != -1) return dp[i][j];

        int take = 0;
        if(s[i-1] == t[j-1]){
            take = find(s,t,i-1,j-1,dp);
        }
        int ntake = find(s,t,i-1,j,dp);
        return dp[i][j] = take + ntake;

    }
    int numDistinct(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        // vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        // return find(s,t,n1,n2,dp);


        vector<vector<long long>> dp(n1+1,vector<long long>(n2+1,0));
        for(int i = 0; i<=n1; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i<n1+1; i++){
            for(int j = 1; j<n2+1; j++){
                int take = 0;
                if(s[i-1] == t[j-1]){
                    take = dp[i-1][j-1];
                }
                long long ntake = dp[i-1][j];
                dp[i][j] = take + ntake;
            }
        }
        return dp[n1][n2];
    }
};