/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:
Input: matrix = [["1"]]
Output: 1
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int maxArea = 0;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                int topInd = st.top();
                st.pop();
                int psIndex = st.empty()? -1 : st.top();
                int nsIndex = i;
                maxArea = max(maxArea,arr[topInd]*(nsIndex - psIndex - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nsIndex = n;
            int topInd = st.top();
            st.pop();
            int psIndex = st.empty()? -1 : st.top();
            maxArea = max(maxArea,arr[topInd]*(nsIndex-psIndex-1));
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> prifixsum(r,vector<int>(c));
        for(int j = 0; j<c; j++){
            for(int i = 0; i<r; i++){
                if(i==0){
                    prifixsum[i][j] = matrix[i][j] - '0';
                }
                else{
                    if(matrix[i][j]=='1'){
                        prifixsum[i][j] = prifixsum[i-1][j] + 1;
                    }
                    else{
                        prifixsum[i][j] = 0;
                    }
                }
            }
        }

        int maxArea = 0;
        for(int i = 0; i<r; i++){
            int maxar = largestRectangleArea(prifixsum[i]);
            maxArea = max(maxArea,maxar);
        }
        return maxArea;
    }
};