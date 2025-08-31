/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
class Solution {
public:
    int find(int len1 , int len2 , string &word1, string &word2 , vector<vector<int>> &dp){

        if (len1 == 0) return len2; // Need to insert all characters of word2
        if (len2 == 0) return len1; // Need to delete all characters of word1

        if(dp[len1][len2] !=-1 ) return dp[len1][len2];
        
        if(word1[len1-1]==word2[len2-1]){
            return dp[len1][len2] =  find(len1-1,len2-1,word1,word2,dp);
        }
        else{
            int del = 1 + find(len1-1,len2,word1,word2 , dp);
            int rep = 1 + find(len1-1,len2-1,word1,word2 , dp);
            int ins = 1 + find(len1,len2-1,word1,word2 , dp);
            return dp[len1][len2] = min(del,min(rep,ins));
        }
    }
    int minDistance(string word1, string word2) {
        
        int n1 = word1.length();
        int n2 = word2.length();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));

        for(int i = 0; i<=n1; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i<=n2; i++){
            dp[0][i] = i;
        }

        for(int len1 = 1; len1<=n1; len1++){
            for(int len2 = 1; len2<=n2; len2++){

                if(word1[len1-1]==word2[len2-1]){
                dp[len1][len2] =  dp[len1-1][len2-1];
                }
                else{
                int del = 1 + dp[len1-1][len2];
                int rep = 1 + dp[len1-1][len2-1];
                int ins = 1 + dp[len1][len2-1];
                dp[len1][len2] = min(del,min(rep,ins));
                    }  
                    
            }
        }
        return dp[n1][n2];
        // return find(n1,n2,word1,word2 , dp);
    }
};