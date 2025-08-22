/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
*/
class Solution {
public:
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
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp = longestCommonSubsequence(str1 , str2);

        string ans = "";
        int m = str1.length() , n = str2.length();
        int i = m , j = n;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    ans += str2[j-1];
                    j--;
                }
                else{
                    ans += str1[i-1];
                    i--;
                }
            }
        }

        //adding those characters which we are left with
        while(i > 0){
            ans += str1[i-1];
            i--;
        }
        while(j > 0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};