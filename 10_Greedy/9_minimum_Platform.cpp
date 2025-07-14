/*
You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.

Examples:

Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
Output: 3
Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.
*/

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size();
        int count = 0;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int p1 = 0;
        int p2 = 0;
        int ans =0;
        while(p1 <n ){ // here p1<n bcs arrval time phele khatam hoga so yaha tak pata chal jayega max count
            if(arr[p1] <= dep[p2]){
                p1++;
                count++;
            }
            else if(arr[p1] > dep[p2]){
                p2++;
                count--;
            }
            // when both are equal means ek ne leave kia and ek ne arrive kia so no change in count
            ans = max(ans,count);            
        }
        return ans;
    }
};
