/*
Given a row-wise sorted matrix mat[][] where the number of rows and columns is always odd. Return the median of the matrix.

Examples:

Input: mat[][] = [[1, 3, 5], 
                [2, 6, 9], 
                [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
Input: mat[][] = [[2, 4, 9],
                [3, 6, 7],
                [4, 7, 10]]
Output: 6
Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
Input: mat = [[3], [4], [8]]
Output: 4
Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
*/
class Solution {
  public:
    int upperbound(vector<int> &arr , int elem){
        int low = 0 , high = arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]<=elem){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
    int blackbox(vector<vector<int>> &mat , int mid){
        int count = 0;
        for(int i = 0; i<mat.size(); i++){
            count += upperbound(mat[i],mid);
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i = 0; i<m; i++){
            low = min(low,mat[i][0]);
            high = max(high,mat[i][m-1]);
        }
        int req = (m*n)/2;
        while(low<=high){
            int mid = (low+high)/2;
            int smallEq = blackbox(mat,mid);
            if(smallEq > req){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};