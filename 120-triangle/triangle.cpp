class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n  = tri.size();
        vector<int> dp = tri[n-1];

        for(int i = n-2 ; i>=0 ; i--)
        {
            for(int j = 0 ;j <=i ; j++)
            {
                dp[j] = tri[i][j] + min(dp[j],dp[j+1]);
            }
        }

        return dp[0];
    }
};