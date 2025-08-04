/*
We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1], where n is the size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
Note: stations is in a strictly increasing order.

Example 1:

Input:
n = 10
stations[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
Example 2:

Input:
n = 10
stations[] = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95] 
k = 2 
Output: 14.00 
Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.
*/
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> space(n-1,0);
        priority_queue<pair<double,int>> pq;
        for(int i = 0; i<n-1; i++){
            int diff = stations[i+1] - stations[i];
            pq.push({diff,i});
        }
        for(int i = 0; i<k; i++){
            pair<int,int> top1 = pq.top();
            pq.pop();
            int ind = top1.second;
            double sp = top1.first; // no need of this space it is just to tell pq that in the whole array this space is max
            space[ind]++;
            int diffSpace = stations[ind+1] - stations[ind];
            double divide = (double)diffSpace/(space[ind]+1);
            pq.push({divide,ind});
        }
        return pq.top().first;
    }
};