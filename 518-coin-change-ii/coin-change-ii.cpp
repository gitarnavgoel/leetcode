class Solution {
public:
int solver(int i , int target , vector<int>& val , vector<vector<int>> &dp)
    {
        if(target==0) return 1;
        if(i==0){
            if(target%val[i] == 0) return 1;

            return 0;
        } 
        if(dp[i][target] != -1) return dp[i][target];
        int notpick = solver(i-1,target,val,dp);
        int pick = 0;
        if(val[i]<=target) pick =  solver(i,target-val[i],val,dp);

        return dp[i][target] = notpick+pick ;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return solver(n-1,amount,coins,dp);
    }
};