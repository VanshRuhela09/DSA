/*
Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Examples :

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
*/

class Solution {
  public:
    static bool cmp(pair<int,int> a , pair<int,int> b){
        double a1 = (double)a.first/a.second;
        double a2 = (double)b.first/b.second;
        return a1 > a2;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>> vec;
        int n = val.size();
        for(int i = 0; i<n; i++){
            vec.push_back({val[i],wt[i]});
        }
        
        sort(vec.begin(),vec.end() , cmp);
        double ans = 0.0;
        
        for(int i = 0; i<n; i++){
            if(capacity >= vec[i].second){
                capacity -= vec[i].second;
                ans += vec[i].first;
            }
            else{
                ans += ((double)vec[i].first/vec[i].second)*capacity;
                break;
            }
        }
        return ans;
    }
};
