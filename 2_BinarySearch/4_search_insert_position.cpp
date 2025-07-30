/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // O(logn)
        // by lowerBound
        int n = nums.size();
        int l = 0 , h = n-1;
        int ans = n;  //expected if lower bound not found then it will be n
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]>=target){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;        
        // O(n)
        // for(int i = 0; i<nums.size(); i++){
        //     if(target<=nums[i]){
        //         return i;
        //     }
        // }
        // return nums.size();

        //O{logn}
        // int n = nums.size();
        // int l = 0 , r = n-1;
        // while(l<=r){
        //     int mid = (l+r)/2;
        //     if(nums[mid] == target){
        //         return mid;
        //     }
        //     else if(target > nums[mid]){
        //         l = mid+1;
        //     }
        //     else{
        //         r = mid-1;
        //     }
        // }
        // return r + 1;
    }
};