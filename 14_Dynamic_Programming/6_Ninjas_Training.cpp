/*
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

Sample Input 1:
2
3
1 2 5 
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90
Sample Output 1:
11
210
Explanation of sample input 1:
For the first test case,
One of the answers can be:
On the first day, Ninja will learn new moves and earn 5 merit points. 
On the second day, Ninja will do running and earn 3 merit points. 
On the third day, Ninja will do fighting and earn 3 merit points. 
The total merit point is 11 which is the maximum. 
Hence, the answer is 11.

For the second test case:
One of the answers can be:
On the first day, Ninja will learn new moves and earn 70 merit points. 
On the second day, Ninja will do fighting and earn 50 merit points. 
On the third day, Ninja will learn new moves and earn 90 merit points. 
The total merit point is 210 which is the maximum. 
Hence, the answer is 210.
*/
int find(vector<vector<int>> &points , int day , int prevTask , vector<vector<int>> &dp){
    if(day == 0){
        int maxi = -1;
        for(int i = 0; i<3; i++){
            if(i!=prevTask){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][prevTask]!=-1) return dp[day][prevTask];

    int maxpoints = 0;
    for(int i = 0; i<3; i++){
        int point = 0;
        if(i != prevTask){
            point += points[day][i] + find(points,day-1,i,dp);
        }
        maxpoints = max(maxpoints,point);
    }
    return dp[day][prevTask] = maxpoints;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));
    // return find(points,n-1,3,dp);
    
    for(int task = 0; task<4; task++){
        int maxi = -1;
        for(int i = 0; i<3; i++){
            if(i!=task){
                maxi = max(maxi,points[0][i]);
            }
        }
        dp[0][task] = maxi;
    }
    for(int day = 1; day<n; day++){
        for(int prevTask = 0; prevTask<4; prevTask++){
            int maxpoints = 0;
            for(int i = 0; i<3; i++){
                int point = 0;
                if(i != prevTask){
                    point += points[day][i] + dp[day-1][i];
                }
                maxpoints = max(maxpoints,point);
            }
            dp[day][prevTask] = maxpoints;
        }
    }
    return dp[n-1][3];
}