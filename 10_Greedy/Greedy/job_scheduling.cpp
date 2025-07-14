/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int max = INT_MIN;
        for(int i = 0; i<n; i++){
            if(arr[i].dead > max){
                max = arr[i].dead;
            }
        }
        
        sort(arr,arr+n,cmp);
        
        vector<int> check(max+1, -1);
        int count = 0 , Tprofit = 0;
        for(int i = 0; i<n; i++){
            int j = arr[i].dead;
            while(j>0){
                if(check[j]==-1){
                    Tprofit += arr[i].profit;
                    check[j] = 1;
                    count++;   
                    break;
                }
                else
                    j--;
            }
        }
        return {count,Tprofit};   
    } 
};