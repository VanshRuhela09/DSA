/*
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :

Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
*/

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<vector<int>> meet(n,vector<int>(2));
        for(int i = 0; i<n; i++){
            meet[i][0] = end[i];
            meet[i][1] = start[i];
        }
        sort(meet.begin() , meet.end());
        int count = 1 , freetime = meet[0][0];
        for(int i = 1; i<n; i++){
            if(meet[i][1] > freetime){
                count++;
                freetime = meet[i][0];
            }
        }
        return count;
    }
};