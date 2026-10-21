class Solution {
  public:
    int solver(int i , vector<int> &v , int diff , vector<vector<int>> & dp )
    {
        if(i==0)
        {
            if(diff==0 && v[0]==0) return 2;
            if(diff==0 || diff == v[0]) return 1;
            
            return 0;
        }
        
        if(dp[i][diff] !=-1) return dp[i][diff];
        int pick = 0;
        if(v[i]<=diff) pick = solver(i-1,v,diff-v[i],dp);
        int no = solver(i-1,v,diff,dp);
        
        return dp[i][diff] = pick+no;
    }
    int findTargetSumWays(vector<int>& arr, int diff) {
        // Code here
         int n = arr.size();
         int sum = 0;
         for(int x : arr) sum+=x;
         if(sum<abs(diff) || (sum+diff)%2 !=0) return 0;
         vector<vector<int>>dp(n,vector<int>(sum+1,-1));
         return solver(n-1,arr,(sum+diff)/2,dp);
    }
};