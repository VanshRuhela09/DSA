#include <bits/stdc++.h> 
int find(int ind1 , int ind2 , string & str1, string & str2 , vector<vector<int>> &dp ){
  if(ind1<0 || ind2<0){
    return 0;
  }
  if(dp[ind1][ind2]!=-1){
    return dp[ind1][ind2];
  }
  if(str1[ind1]==str2[ind2]){
    return dp[ind1][ind2] = 1 + find(ind1-1,ind2-1,str1,str2,dp);
  }
  else{
    return dp[ind1][ind2] = 0 + max(find(ind1-1,ind2,str1,str2,dp),find(ind1,ind2-1,str1,str2,dp));
  }
}
int getLengthOfLCS(string & str1, string & str2) {
  int ind1 = str1.length()-1;
  int ind2 = str2.length()-1;
  vector<vector<int>> dp(str1.length(),vector<int>(str2.length(),-1));
  return find(ind1,ind2,str1,str2,dp);
}

// =======tabulation========

#include <bits/stdc++.h> 
int getLengthOfLCS(string & str1, string & str2) {
  int ind1 = str1.length()-1;
  int ind2 = str2.length()-1;
  vector<vector<int>> dp(str1.length()+1,vector<int>(str2.length()+1,-1));
  for(int i = 0; i<=str1.length(); i++){
    dp[i][0] = 0;
  }
  for(int i = 0; i<=str2.length(); i++){
    dp[0][i] = 0;
  }

  for(int i = 1;i<=str1.length(); i++){
    for(int j = 1; j<=str2.length(); j++){
          if(str1[i-1]==str2[j-1]){
        dp[i][j] = 1 +dp[i-1][j-1];
        }
      else{
        dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
       }
    }
  }
  
  return dp[ind1+1][ind2+1];
}