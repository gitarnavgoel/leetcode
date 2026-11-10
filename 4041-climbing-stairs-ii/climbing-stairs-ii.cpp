class Solution {
public:
    int solver(int i , vector<int>&costs , vector<int>&dp)
    {
        if(i<0) return 1e9;
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];

        int onestep = costs[i-1] +1 + solver(i-1,costs,dp);
        int twostep = costs[i-1] +4 + solver(i-2,costs,dp);
        int threestep = costs[i-1] +9 + solver(i-3,costs,dp);

        return dp[i] = min(onestep,min(twostep,threestep));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);

        return solver(n,costs,dp);
    }
};