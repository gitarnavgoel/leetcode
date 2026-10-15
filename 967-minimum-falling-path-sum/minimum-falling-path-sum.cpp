class Solution {
public:
    int solver(int i , int j , vector<vector<int>> & dp , vector<vector<int>> & matrix, vector<vector<bool>> &vis)
    {
        if(j<0 || j>=matrix[0].size()) return 1e9;

        if(i==0) return matrix[i][j];

        if(vis[i][j]) return dp[i][j];

        int left = matrix[i][j] + solver(i-1,j-1,dp,matrix,vis);
        int up = matrix[i][j] + solver(i-1,j,dp,matrix,vis);
        int right = matrix[i][j] + solver(i-1,j+1,dp,matrix,vis);

        vis[i][j] = true;
        return dp[i][j] = min(left,min(up,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<bool>> vis(n ,vector<bool>(m,false));
        int ans = INT_MAX;

        for(int j = 0 ; j < m ; j++)
        {
            ans =  min(ans , solver(n-1,j,dp,matrix,vis));  
        }  
        return ans;

    }
};