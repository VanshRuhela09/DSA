class Solution{

	public:
	  
	 int find(int arr[],int target,int ind , vector<vector<int>> &dp)
	 {
	     
	    if(ind==0)
	    {
	        if(target==0 && arr[0]==0){
	            return 2;
	        }
	        if(target==0 || arr[0]==target){
	            return 1;
	        }
	        return 0;
	    }
	    if(dp[ind][target]!=-1){
	        return dp[ind][target];
	    }
	     
	       int ntake= find(arr,target,ind-1,dp);
	       int take=0;
	       if(target>=arr[ind])
	       {
	            take= find(arr,target-arr[ind],ind-1,dp);
	       }
	       
	       return dp[ind][target] = take+ntake;
	     
	 }
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return find(arr,sum,n-1,dp);
	}
	  
};