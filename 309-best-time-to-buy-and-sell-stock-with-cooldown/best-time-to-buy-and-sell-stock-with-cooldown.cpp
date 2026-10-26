class Solution {
public:
    int solve(int i , bool buy , vector<int> &prices , vector<vector<int>>&dp )
    {
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit ;
        if(buy)
        {
            profit = max(-prices[i]+solve(i+1,0,prices,dp) , solve(i+1,1,prices,dp));
        }else{
            profit = max(prices[i]+solve(i+2,1,prices,dp) , solve(i+1,0,prices,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));

        return solve(0,true,prices,dp);
    }
};