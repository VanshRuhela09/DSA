/*
HOUSE ROBBER(LEETCODE)
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.

Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11
Explanation to Sample Output 1:
In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer is 5.

In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]' and 'ARR[3]' is 10, and the sum of 'ARR[0]' and 'ARR[3]' is 11. So if we take the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.
Sample Input 2:
2
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9
Sample Output 2:
8
24
Explanation to Sample Output 2:
In test case 1, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]' and 'ARR[4]', i.e. 8, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

In test case 2, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]', 'ARR[4]', 'ARR[6]' and 'ARR[8]', i.e. 24 so, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.
*/

#include <bits/stdc++.h> 
int find(int ind , vector<int> &nums , vector<int> &dp){
    if(ind == 0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int take = nums[ind] + find(ind-2 , nums,dp);
    int ntake = find(ind-1,nums,dp);
    return dp[ind] = max(take,ntake);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    // return find(n-1,nums,dp);

    //base case
    //tabulation without space optimization
    // dp[0] = nums[0];
    // for(int ind = 1; ind<n; ind++){
    //     int take = nums[ind];
    //     if(ind>1) take += dp[ind-2];  //(base case)this is because if(i<=1) then dp[ind-2] will be out of bound
    //     int ntake = dp[ind-1];
    //     dp[ind] = max(take,ntake);
    // }
    // return dp[n-1];

    //tabulation with space optimization
    int prev1 = nums[0];
    int prev2;
    for(int ind = 1; ind<n; ind++){
        int take = nums[ind];
        if(ind>1) take += prev2;

        int ntake = prev1;
        int curr = max(take,ntake);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;

}