/*
You are given two strings ‘s1’ and ‘s2’.

Return the longest common subsequence of these strings.

If there’s no such string, return an empty string. If there are multiple possible answers, return any such string.

Note:
Longest common subsequence of string ‘s1’ and ‘s2’ is the longest subsequence of ‘s1’ that is also a subsequence of ‘s2’. A ‘subsequence’ of ‘s1’ is a string that can be formed by deleting one or more (possibly zero) characters from ‘s1’.

Example:
Input: ‘s1’  = “abcab”, ‘s2’ = “cbab”

Output: “bab”

Explanation:
“bab” is one valid longest subsequence present in both strings ‘s1’ , ‘s2’.

*/
    //this function will return dp array of LCS
    vector<vector<int>> longestCommonSubsequence(string str1, string str2) {
        // we considered 1 based indexing means we are assuming the length of the strings not the indexes.
        int n = str1.length(),m = str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
               if(str1[i-1]==str2[j-1])
                   {
                     dp[i][j]= 1+dp[i-1][j-1];
                   }
               else
                   {
                     dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                   }
            }
        }
        
        return dp;
        
    }
string findLCS(int n, int m,string &s1, string &s2){
		vector<vector<int>> dp = longestCommonSubsequence(s1,s2);
        int i = n, j = m;
        string ans = "";
        for(int k = 0; k<dp[n][m]; k++){
            ans += "$";
        }
        int ind = ans.length()-1;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans[ind--] = s1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i = i-1;
                }
                else{
                    j = j-1;
                }
            }
        }
        return ans;
}