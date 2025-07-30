/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/
class Solution {
public:
    int findLeft(int l , int r, vector<int> &nums, int target){
        int leftInd = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                leftInd = mid;
                r = mid-1;
            }
            else if(target > nums[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return leftInd;
    }

    int findRight(int l , int r, vector<int> &nums, int target){
        int rightInd = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                rightInd = mid;
                l = mid+1;
            }
            else if(target > nums[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return rightInd;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int leftInd = findLeft(0,n-1,nums,target);
        int rightInd = findRight(0,n-1,nums,target);
        return {leftInd,rightInd};
    }
};