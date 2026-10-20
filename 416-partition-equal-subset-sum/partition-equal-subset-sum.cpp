class Solution {
public:
    bool solver(int idx , int tar , vector<int>&nums,vector<vector<int>>&dp)
    {
        if(tar==0) return true;
        if(idx==0) return (nums[0]==tar);
        if(dp[idx][tar]!=-1) return dp[idx][tar];
        bool no = solver(idx-1,tar,nums,dp);
        bool yes = false;
        if(nums[idx]<=tar) yes = solver(idx-1,tar-nums[idx],nums,dp);

        return dp[idx][tar] = no||yes;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int x : nums) sum+=x;
        if(sum&1) return false;
        vector<vector<int>>dp(n,vector<int>(sum,-1));

        return solver(n-1,sum/2,nums,dp);
    }
};