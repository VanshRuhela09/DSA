/*
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 
*/

class Solution {
public:
    bool isPalindrome(int i , int j , string &s){
        if(i>=j) return true;

        if(s[i]==s[j]){
            return isPalindrome(i+1,j-1,s);
        }
        else{
            return false;
        }
    }
    string longestPalindrome(string s) {
        int maxLen = INT_MIN;
        int sp = 0;
        int n = s.length();
        // vector<vector<bool>> dp(n,vector<bool>(n,false));
        // for(int i = 0; i<n; i++){
        //     for(int j =i; j<n; j++){
        //         if(isPalindrome(i,j,s)==true){
        //            if(j-i+1>maxLen){
        //             maxLen = j-i+1;
        //             sp = i;
        //            }
        //         }
        //     }
        // }
        // return s.substr(sp,maxLen);
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        for(int i = 0; i<n+1; i++){
            dp[i][i]=true;
        }
        for(int l = 2; l<=n; l++){
            for(int i = 0; i<n-l+1; i++){
                int j = i+l-1;
                    if(s[i]==s[j] && l==2){
                        dp[i][j] = true;
                        if(maxLen<l){
                            maxLen = l;
                            sp = i;
                        }
                    }
                    if(s[i]==s[j] && dp[i+1][j-1]==true){
                        dp[i][j] = true;
                        if(maxLen<l){
                            maxLen = l;
                            sp = i;
                        }
                    }
                    else{
                        dp[i][j]=false;
                    }
            }
        }
        return s.substr(sp,maxLen);
    }
};


// class Solution {
// public:
//     bool isPalindrome(string &str){
//         int i = 0 , j = str.length()-1;
//         while(i<j){
//             if(str[i]!=str[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
//     string find(int i , int j , string &s , vector<vector<string>> &dp){
//         if(i>j) return "";
//         string sub = s.substr(i,j-i+1);
//         if(isPalindrome(sub)){
//             return sub;
//         }
//         if(dp[i][j]!="-1") return dp[i][j];
//         string s1 = find(i+1,j,s,dp);
//         string s2 = find(i,j-1,s,dp);
//         return dp[i][j] = s1.length()>s2.length() ? s1 : s2;
//     }
//     string longestPalindrome(string s) {
//         int n = s.length();
//         vector<vector<string>> dp(n,vector<string>(n,"-1"));
//         return find(0,n-1,s,dp);
//     }
// };