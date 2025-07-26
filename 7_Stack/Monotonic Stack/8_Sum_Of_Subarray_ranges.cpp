/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
*/

class Solution {
public:
    vector<int> NSE(vector<int>&nums){
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){

            while(!st.empty() && nums[i]<= nums[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
                st.push(i);
            }
            else{
                nse[i] = st.top();
                st.push(i);
            }
        }
        return nse;
    }
    vector<int> PSEE(vector<int> &nums){
        int n = nums.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[i]<nums[st.top()]){
                st.pop();
            }
            if(st.empty()){
                psee[i] = -1;
                st.push(i);
            }
            else{
                psee[i] = st.top();
                st.push(i);
            }
        }
        return psee;
    }
    vector<int> NGE(vector<int> &nums){
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[i]>= nums[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nge[i] = n;
                st.push(i);
            }
            else{
                nge[i] = st.top();
                st.push(i);
            }
        }
        return nge;
    }
    vector<int> PGEE(vector<int> &nums){
        int n = nums.size();
        vector<int> pgee(n);
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[i]> nums[st.top()]){
                st.pop();
            }
            if(st.empty()){
                pgee[i] = -1;
                st.push(i);
            }
            else{
                pgee[i] = st.top();
                st.push(i);
            }
        }
        return pgee;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nse = NSE(nums);
        vector<int> psee = PSEE(nums);
        vector<int> nge = NGE(nums);
        vector<int> pgee = PGEE(nums);
        long long maxSum = 0;
        long long minSum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;
            minSum = minSum + left*right*nums[i];
        }
        for(int i = 0; i<n; i++){
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            maxSum = maxSum + left*right*nums[i];
        }

        return maxSum - minSum;

    }
};