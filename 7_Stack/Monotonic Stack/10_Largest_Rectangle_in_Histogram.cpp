/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:
Input: heights = [2,4]
Output: 4
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int maxArea = 0;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                int topInd = st.top();
                st.pop();
                int psIndex = st.empty()? -1 : st.top();   // previos smaller index of top element
                int nsIndex = i;  // next smaller index of top element

                // we are finding the nse and pse for the top element of the array.
                maxArea = max(maxArea,arr[topInd]*(nsIndex - psIndex - 1));
            }
            st.push(i);
        }

        //the below while loop if for the element present in stack
        // and these element in stack are those element whose nse is not present hence consider their nse as n
        while(!st.empty()){
            int nsIndex = n;
            int topInd = st.top();
            st.pop();
            int psIndex = st.empty()? -1 : st.top();
            maxArea = max(maxArea,arr[topInd]*(nsIndex-psIndex-1));
        }
        return maxArea;
    }
};