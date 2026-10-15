class Solution {
public:
    int solver(int i  ,int j , vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(i<0 || j<0) return 0;
        if(grid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
  
        int up = solver(i-1, j , grid,dp);

        int left = solver(i , j-1 , grid,dp);

        return dp[i][j]= up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        return solver(row-1,col-1,grid,dp);
    }
};