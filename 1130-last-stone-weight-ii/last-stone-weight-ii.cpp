class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum+=x;
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));

        for(int i =0 ; i < n ; i++) dp[i][0] = true;
        if(nums[0]<=sum)dp[0][nums[0]] = true;

        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 1 ; j <=sum ; j++ )
            {
                bool no = dp[i-1][j];
                bool take = false;
                if(nums[i]<=j) take = dp[i-1][j-nums[i]];

                dp[i][j] = no||take;
            }
        }

        int mini = 1e9;

        for(int k = 0 ; k <= sum ; k++)
        {
            if(dp[n-1][k])
            {
                mini = min(mini,abs(sum - 2*k));
            }
        }

        return mini;
    }
};