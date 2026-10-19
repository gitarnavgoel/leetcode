class Solution {
public:
    int solver(int idx , vector<int>&cost , vector<int> & dp)
    {
        if(idx<0) return 1e9;
        if(idx==0 || idx==1) return cost[idx];
        if(dp[idx]!=-1) return dp[idx];

        int prev = cost[idx] + solver(idx-1,cost,dp);
        int sprev = cost[idx] + solver(idx-2,cost,dp);

        return dp[idx] = min(prev,sprev);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);

        return min(solver(n-1,cost,dp),solver(n-2,cost,dp));
    }
};