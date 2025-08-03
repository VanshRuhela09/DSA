/*
You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples:

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows in this case is 3, which is the largest among all possible ways.

Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows in this case is 4, which is the largest among all possible ways.

Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows in this case is 1, which is the largest among all possible ways.
*/

// User function Template for C++


class Solution {
  public:
    
    int find(vector<int> &stalls, int k , int cowsDist , int n){
        
        int prevCow = 0;
        int i = 1;
        k--;
        while(k && i<n){
            if(stalls[i] - stalls[prevCow] >= cowsDist){
                prevCow = i;
                i++;
                k--;
            }
            else{
                i++;
            }
        }
        
        if(k==0){
            return cowsDist;
        }
        else{
            return -1;
        }
        
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        
        int n = stalls.size();
        int minElem = stalls[0];
        int maxElem = stalls[n-1];
        
        int l = 1 , r = maxElem - minElem;
        int ans;
        while(l<=r){
            int mid = (l+r)/2;
            int a = find(stalls , k , mid , n);
            if(a == -1){
                r = mid - 1;
            }
            else{
                ans = a;
                l = mid + 1;
            }
        }
        return ans;
    }
};


