/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return arr[0];
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];

        int l = 1 , r = n-2;
        int ans;
        while(l<=r){
            int mid = (l+r)/2;
            if(mid%2==0){
                if(arr[mid]==arr[mid+1]){
                    l = mid+1;
                }
                else{
                    ans = arr[mid]; // only updating the anser when the mid is even because the single element will always be on even index
                    r = mid-1;
                }
            }
            else{
                if(arr[mid]==arr[mid-1]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return ans;
    }
};