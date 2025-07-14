
/*
Medium
Topics
premium lock icon
Companies
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

class Solution {
public:
    //recursive approch
    // bool jump(vector<int> &nums , int ind){
    //     if(ind==nums.size()-1){
    //         return true;
    //     }
    //         for(int i = 1; i<=nums[ind]; i++){
    //             int temp =  jump(nums,ind+i);
    //             if(temp){
    //                 return true;
    //             }
    //         }
    //     return false;
    // }
    bool canJump(vector<int>& nums) {
        // return jump(nums,0); recursive approch
        int targetIndex = nums.size()-1;
        for(int i = nums.size()-2; i>=0; i--){
            if(i + nums[i] >= targetIndex){
                targetIndex = i;
            }
        }
        return targetIndex==0;
    }
};