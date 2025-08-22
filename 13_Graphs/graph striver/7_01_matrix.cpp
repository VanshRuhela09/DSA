/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<vector<int>> ans(m,vector<int>(n,0));


        //below pushing whem mat[i][j] == 0 bcs hum 0 ko scr node consider kar rahe hai and 0 to 1 ki taraf jaa rahe hai
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({0,{i,j}});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int row = top.second.first;
            int col = top.second.second;
            int d = top.first;
            ans[row][col] = d;  // storing ansewer here when we poping the element bcs when we are poping toh every element will come here so store here
            int delr[] = {-1,0,1,0};
            int delc[] = {0,1,0,-1};
            for(int i = 0; i<4; i++){
                int nrow = row + delr[i];
                int ncol = col + delc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] == false){ // here no need to check mat[nrow][ncol]==0 bcs 1 vale toh humne push kar diye so aab saare 0 vale hi bache honge
                    q.push({d+1,{nrow,ncol}});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return ans;
    }
};