class Solution {
public:
    int solver(int r , int c , int row,int column,vector<vector<int>> &dp )
    {
        if(r==row-1 && c==column-1) return 1;
        if(r>=row || c>=column) return 0;

        if(dp[r][c] != -1) return dp[r][c];

        int right = solver(r +1 , c , row,column,dp);
        int down = solver(r , c+1 , row,column,dp);

        return dp[r][c] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solver(0,0,m, n,dp);
    }
};