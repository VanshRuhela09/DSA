/*
Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr[] = [2, 4, 6, 9], if we rotate it by 2 times it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

Examples:

Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.
Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.
*/


class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        int n = nums.size();
        int l = 0 , r = n-1;
        int mini = INT_MAX;
        int miniInd = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(mini>nums[mid]){
                mini = nums[mid];
                miniInd = mid;
            }
            if(nums[mid]>nums[r]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
 
        }
        return miniInd;
    }
};