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
        dp[m-1][n-1] = 1;
        
        for(int i = m-1 ; i>=0 ; i--)
        {
            for(int j = n-1 ; j>=0 ; j--)
            {
                if(i==m-1 && j==n-1) continue;
                else{
                    int right = 0;
                    int down = 0;
                    if(i+1 < m)right = dp[i+1][j];
                    if(j+1 <n ) down = dp[i][j+1];

                    dp[i][j]=right+down;
                }
            }
        }
        return dp[0][0];
    }
};