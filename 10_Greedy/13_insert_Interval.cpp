/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;

        //here newInterval[0] shoule be > intervals[i][1] then only current interval is left non overlapping part
        while(i<n && newInterval[0] > intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }

        //here now when from above loop we got the first overlapping inverval or we get the position where we have to put the invterval then now check newinterval[1] must >= interals[i][0] then only it is overlapping part
        while(i<n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back({newInterval[0],newInterval[1]});

        //now we are left with the right non overlapping intervals
        while(i<n){
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        return ans;
    }
};