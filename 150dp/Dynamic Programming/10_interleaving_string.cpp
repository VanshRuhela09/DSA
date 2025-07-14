/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/
class Solution {
public:
    bool check(int i , int j , string &s1, string &s2, string &s3 , vector<vector<int>> &dp){

        if(i==s1.length()){
            string sub3 = s3.substr(i+j,s3.length()-(i+j));
            string sub2 = s2.substr(j,s2.length()-j);
            if(sub3==sub2) return true;
            else return false;
        }
        else if(j==s2.length()){
            string sub3 = s3.substr(i+j,s3.length()-(i+j));
            string sub1 = s1.substr(i,s1.length()-i);
            if(sub3==sub1) return true;
            else return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int k = i+j;
        bool first = false;
        if(s1[i]==s3[k]){
            first = check(i+1,j,s1,s2,s3,dp);
        }
        bool second = false;
        if(s2[j]==s3[k]){
            second = check(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j] = first || second;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length() , n2 = s2.length(), n3 = s3.length();
        // vector<vector<int>> dp(n1,vector<int>(n2,-1));
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1,false)); // dp for tabulation
        if(n1+n2!=n3) return false; // this is because when n1+n2>n3 then problem is occuring to calculate substring in tabulation only.
        for(int j = 0; j<=n2; j++){
            string sub2 = s2.substr(j,n2-j);
            string sub3 = s3.substr(j+n1,n3-(n1+j));
            if(sub3==sub2){
                dp[n1][j]=true;
            }
            else{
                dp[n1][j]=false;
            }
        }
        
        for(int i = 0; i<=n1; i++){
            string sub1 = s1.substr(i,n1-i);
            string sub3 = s3.substr(i+n2,n3-(n2+i));
            if(sub3==sub1) dp[i][n2]=true;
            else dp[i][n2]=false;
        }
        for(int i = n1-1; i>=0; i--){
            for(int j = n2-1; j>=0; j--){
                int k = i+j;
                bool first = false;
                if(s1[i]==s3[k]){
                    first = dp[i+1][j];
                }
                bool second = false;
                if(s2[j]==s3[k]){
                    second = dp[i][j+1];
                }
                 dp[i][j] = first || second;
            }
        }
        // return check(0,0,s1,s2,s3,dp);
        return dp[0][0];
    }
};