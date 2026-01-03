class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>& grid , int row , int col , vector<vector<bool>> &vis){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=true;
        while(!q.empty()){
            auto top = q.front();
            int i = top.first;
            int j = top.second;
            q.pop();
            for(int deltarow = -1 ; deltarow<=1; deltarow++){
                for(int deltacol = -1; deltacol<=1; deltacol++){
                    int nrow = i+deltarow;
                    int ncol = j+deltacol;
                    if((nrow>=0 && nrow<=grid.size()-1) && (ncol>=0 && ncol<=grid[0].size()-1) && (vis[nrow][ncol]==false) && (grid[nrow][ncol]=='1')){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=true;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};