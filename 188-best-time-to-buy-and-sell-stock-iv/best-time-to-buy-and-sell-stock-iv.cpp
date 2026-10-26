class Solution {
public:    
    int solver(int i , bool buy , int cap , vector<int>&prices , vector<vector<vector<int>>>& dp ,int profit)
    {
        if(i==prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy)
        {
            profit = max(-prices[i]+solver(i+1,0,cap,prices,dp,profit),
            solver(i+1,1,cap,prices,dp,profit));
            dp[i][buy][cap] = profit;
        }else{
            profit = max(prices[i]+solver(i+1,1,cap-1,prices,dp,profit),
            solver(i+1,0,cap,prices,dp,profit));
            dp[i][buy][cap] = profit;
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(k+1,-1)));

        return solver(0,true,k,prices,dp,0);
    }
};