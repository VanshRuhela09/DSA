/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
*/
class Solution {
public:
    int lcs(int n, int m, string str1, string str2) {
        // we considered 1 based indexing means we are assuming the length of
        // the strings not the indexes.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
        int minDistance(string word1, string word2) {
            int n1 = word1.length();
            int n2 = word2.length();
            int LCS = lcs(n1,n2,word1,word2);
            return n1 + n2 - 2*(LCS);
        }
    };