class Solution {
public:
    int solver(int i , int target , vector<int>& val , vector<vector<int>> &dp)
    {
        if(target==0) return 0;
        if(i==0){
            if(target%val[i] == 0) return target/val[0];

            return 1e9;
        } 
        if(dp[i][target] != -1) return dp[i][target];
        int notpick = solver(i-1,target,val,dp);
        int pick = 1e9;
        if(val[i]<=target) pick = 1+ solver(i,target-val[i],val,dp);

        return dp[i][target] = min(notpick,pick); 
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = solver(n-1,amount, coins,dp); 

        return (ans>=1e9 ? -1 : ans);

    }
};