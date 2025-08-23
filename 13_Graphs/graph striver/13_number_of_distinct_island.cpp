/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = [[1, 1, 0, 0, 0],
            [1, 1, 0, 0, 0],
            [0, 0, 0, 1, 1],
            [0, 0, 0, 1, 1]]
Output: 1
Explanation:
grid[][] = [[1, 1, 0, 0, 0], 
            [1, 1, 0, 0, 0], 
            [0, 0, 0, 1, 1], 
            [0, 0, 0, 1, 1]]
Same colored islands are equal. We have 2 equal islands, so we have only 1 distinct island.

Example 2:

Input:
grid[][] = [[1, 1, 0, 1, 1],
            [1, 0, 0, 0, 0],
            [0, 0, 0, 0, 1],
            [1, 1, 0, 1, 1]]
Output: 3
Explanation:
grid[][] = [[1, 1, 0, 1, 1], 
            [1, 0, 0, 0, 0], 
            [0, 0, 0, 0, 1], 
            [1, 1, 0, 1, 1]]
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

*/

class Solution {
  public:
    void dfs(vector<vector<int>>& grid , vector<pair<int,int>> &temp , vector<vector<bool>> &vis , int r, int c , int m , int n , pair<int,int> &baseCoor){
        vis[r][c] = true;
        temp.push_back({r-baseCoor.first,c-baseCoor.second});
        int delr[] = {0,1,0,-1};
        int delc[] = {-1,0,1,0};
        for(int i = 0; i<4; i++){
            int nrow = r + delr[i];
            int ncol = c + delc[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==false && grid[nrow][ncol]==1){
                dfs(grid,temp,vis,nrow,ncol,m,n,baseCoor);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        set<vector<pair<int,int>>> st;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> temp;
                    pair<int,int> baseCoor = {i,j};
                    dfs(grid,temp,vis,i,j,m,n,baseCoor);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};

