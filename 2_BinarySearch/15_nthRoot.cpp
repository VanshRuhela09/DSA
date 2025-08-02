/*
You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

Examples :

Input: n = 3, m = 27
Output: 3
Explanation: 33 = 27
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
Input: n = 4, m = 625
Output: 5
Explanation: 54 = 625
*/
class Solution {
  public:
    
    int fun(int mid,int n,int m)
    {
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*mid;
            if(ans>m) return 1;
        }
        if(ans==m) return 0;
        return 2;
        
    }
  
    int nthRoot(int n, int m) {
      int l=1,r=m;
      while(l<=r)
      {
          int mid=(l+r)/2;
          // we don't used the power function here because it can lead to overflow for large values of n and m.
          // Instead, we calculate the power manually using a loop.
          if(fun(mid,n,m)==0)
          {
              return mid;
          }
          if(fun(mid,n,m)==2)
          {
              l=mid+1;
          }
          else
          {                                                                                        
              r=mid-1;
          }
      }
      return -1;
    }
};