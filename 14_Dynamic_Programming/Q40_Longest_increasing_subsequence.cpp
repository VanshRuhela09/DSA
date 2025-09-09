/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

//using Binary Search
class Solution {
public:
    int findLowerBound(vector<int> &arr , int elem){
        int n = arr.size();
        int l = 0;
        int h = n - 1;
        while(l <= h){
            int mid = (l+h)/2;
            if(elem > arr[mid]){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i<n; i++){
            if(nums[i] > temp[temp.size()-1]){
                temp.push_back(nums[i]);
            }
            else{
                int lowerBound = findLowerBound(temp,nums[i]);
                temp[lowerBound] = nums[i];
            }
        }
        return temp.size();
    }
};



//algorithm approach
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> dp(n,1);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i] , 1 + dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }

    

//tabulation + space optimization
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return find(0,-1,n,nums,dp);

        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> next(n+1,0) , curr(n+1,0);

        for(int ind = n-1; ind>=0; ind--){
            for(int prev = n-1; prev>=-1; prev--){
                int ntake = next[prev+1];
                int take = -1e8;
                if(prev == -1 || nums[ind] > nums[prev]){
                    take = 1 + next[ind+1];
                }
                curr[prev+1] = max(take,ntake);
            }
            next = curr;
        }
        return curr[-1+1];
    }




//memoization + tabulation
class Solution {
public:
    int find(int ind , int prev , vector<int>& nums ,  vector<vector<int>> &dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int ntake = find(ind+1,prev,nums,dp);
        int take = INT_MIN;
        if(prev==-1 || nums[ind]>nums[prev]){
            take = 1 + find(ind+1,ind,nums,dp);
        }
        return dp[ind][prev+1] = max(ntake , take);
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1) return 1;
        // vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0)); dp array for memoization.
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0)); // this is for tabulation
        
        for(int ind = nums.size()-1; ind>=0; ind--){
            for(int prev = ind-1; prev>=-1; prev--){
                int ntake = dp[ind+1][prev+1];
                int take = INT_MIN;
                if(prev==-1 || nums[ind]>nums[prev]){
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(ntake , take);
            }
        }
        // return find(0,-1,nums,dp);
        return dp[0][-1+1];
    }
};
