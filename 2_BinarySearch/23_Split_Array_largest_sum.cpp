/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
*/
class Solution {
public:
    int find(vector<int>& nums , int maxsum){
        int prevsum = nums[0];
        int subArraycount = 1;
        for(int i = 1; i<nums.size(); i++){
            if(prevsum + nums[i] > maxsum){
                subArraycount++;
                prevsum = nums[i];
            }
            else{
                prevsum += nums[i];
            }
        }
        return subArraycount;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        
        int high = sum;
        while(low <= high){
            int mid = (low + high)/2;
            int subarray = find(nums,mid);
            if(subarray > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};