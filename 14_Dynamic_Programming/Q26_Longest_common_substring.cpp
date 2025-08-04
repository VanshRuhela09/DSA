/*
You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" with a length of 4.
Input: s1 = "abc", s2 = "acb"
Output: 1
Explanation: The longest common substrings are "a", "b", "c" all having length 1.
Input: s1 = "YZ", s2 = "yz"
Output: 0
*/
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int m = s1.length() , n = s2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int maxi = 0;
        for(int i = 1; i<m+1; i++){
            for(int j = 1; j<n+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxi = max(maxi,dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return maxi;
    }
};