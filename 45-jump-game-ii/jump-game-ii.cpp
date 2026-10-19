class Solution {
public:
    int helper(int i , vector<int> &nums , vector<int> & dp)
    {
        if(i==(nums.size() -1)) return 0;

        if(dp[i]!=-1) return dp[i];
        int mini = INT_MAX;

        for(int k = i+1 ; k<=min((int)nums.size()-1,nums[i]+i) ;k++)
        {
            int val = helper(k,nums,dp);
            if(val!=INT_MAX) mini = min(mini,1+val);
        }

        return dp[i] = mini;

    }
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,-1);

        return helper(0,nums,dp);
    }
};