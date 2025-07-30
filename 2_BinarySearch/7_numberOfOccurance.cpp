/*
Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

Examples :

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.
Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.
*/

class Solution {
  public:
    int findLeft(vector<int> &arr , int target){
        int n = arr.size();
        int l = 0  , r = n-1;
        int leftInd = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(target==arr[mid]){
                leftInd = mid;
                r = mid-1;
            }
            else if(target>arr[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return leftInd;
    }
    
    int findRight(vector<int> &arr , int target){
        int n = arr.size();
        int l = 0  , r = n-1;
        int rightInd = n;
        while(l<=r){
            int mid = (l+r)/2;
            if(target==arr[mid]){
                rightInd = mid;
                l = mid+1;
            }
            else if(target>arr[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return rightInd;
    }
    
    
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int leftInd = findLeft(arr,target);
        int rightInd = findRight(arr,target);
        if(leftInd <0 || rightInd==n) return 0;
        return rightInd - leftInd + 1;
    }
};


