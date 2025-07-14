class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool cmp(pair<int,int> a , pair<int,int> b){
        return a.second < b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> ans;
        for(int i = 0; i<n; i++){
            ans.push_back(make_pair(start[i],end[i]));
        }
        sort(ans.begin() , ans.end() , cmp);
        int count = 1;
        int e = ans[0].second;
        for(int i = 1; i<n ; i++){
            if(ans[i].first>e){
                count++;
                e = ans[i].second;
            }
        }
        return count;
    }
};