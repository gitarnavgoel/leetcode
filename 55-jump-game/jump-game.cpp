class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);

        dp[0]= true;

        for(int i= 0 ;i < n; i++)
        {
            if(!dp[i]) continue;

            else{
                int m = min(n-1 , nums[i]+i);

                for(int j = i+1 ; j<=m ; j++)
                {
                    dp[j] = true;
                }
            }
        }
        return dp[n-1];
    }
};