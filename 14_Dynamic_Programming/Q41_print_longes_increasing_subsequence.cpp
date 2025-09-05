/*
You are given an array of integers arr[], return the Longest Increasing Subsequence (LIS) of the given array.
LIS is the longest subsequence where each element is strictly greater than the previous one.
Note: If multiple LIS of the same maximum length exist, return the one that appears first based on the lexicographical order of their indices (i.e., the earliest combination of positions from the original sequence).

Examples:

Input: arr[] = [10, 20, 3, 40]
Output: [10, 20, 40]
Explanation: [10, 20, 40] is the longest subsequence where each number is greater than the previous one, maintaining the original order.
Input: arr[] = [10, 22, 9, 33, 21, 50, 41, 60, 80]
Output: [10, 22, 33, 50, 60, 80]
Explanation: There are multiple longest Increasing subsequence of length 6, that is [10, 22, 33, 50, 60, 80] and [10 22 33 41 60 80]. The first one has lexicographic smallest order of indices.
*/

class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        
        int n = arr.size();
        
        vector<int> dp(n,1) , hash(n);
        vector<int> ans;
        
        int maxi = 0;
        int maxInd = 0;
        for(int i = 0; i<n; i++){
            hash[i] = i;
            for(int j = 0; j<i; j++){
                if(arr[j] < arr[i]){
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        hash[i] = j;
                    }
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                maxInd = i;
            }
        }
        
        int i = maxInd;
        
        while(i != hash[i]){
            ans.push_back(arr[i]);
            i = hash[i];
        }
        ans.push_back(arr[i]);

        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};