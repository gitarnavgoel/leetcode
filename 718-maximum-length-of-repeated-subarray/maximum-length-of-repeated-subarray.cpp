class Solution {
public:
    int solver(int i , int j , vector<vector<int>> &dp , vector<int> &nums1,vector<int>&nums2)
    {
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(nums1[i]==nums2[j])return  dp[i][j] =  1+ solver(i-1,j-1,dp,nums1,nums2);

        return dp[i][j] = 0;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        int ans =0;
        for(int i=0  ; i <n1 ; i++)
        {
            for(int j = 0 ; j <n2 ; j++)
            {
                ans = max(ans,solver(i,j,dp,nums1,nums2));
            }
        }
        return ans;
    }
};