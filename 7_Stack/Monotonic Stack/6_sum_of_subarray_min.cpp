/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
*/

class Solution {
public:
    vector<int> nextsmallerElement(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
                st.push(i);
            }
            else{
                ans[i] = st.top();
                st.push(i);
            }
        }
        return ans;
    }

    vector<int> PSEElement(vector<int> &arr){  //previous smalles equal element
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
                st.push(i);
            }
            else{
                ans[i] = st.top();
                st.push(i);
            }
        }
        return ans;
    }


    int sumSubarrayMins(vector<int>& arr) {
        long long mod = 1e9+7;
        vector<int> nse = nextsmallerElement(arr);
        vector<int> psee = PSEElement(arr);
        long long sum = 0;
        for(int i = 0; i<arr.size(); i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;
            sum = (sum + (right*left*arr[i])%mod)%mod;
        }
        return sum;
    }
};