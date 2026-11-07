class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,1);
        vector<int> hash(n);
        for(int i = 0; i <n ; i++) hash[i] = i;

        sort(nums.begin(),nums.end());

        int maxi = 1;
        int lastidx = 0;
        for(int i =0 ; i < n ; i++)
        {
            for(int prev = 0 ; prev <i ; prev++)
            {
                if(nums[i]%nums[prev] == 0 && dp[i]<1+dp[prev])
                {
                    dp[i] = 1+dp[prev];
                    hash[i] =prev;
                }
            }
            if(dp[i]>maxi)
            {
                maxi = dp[i];
                lastidx = i;
            }
        }

        vector<int> ans;
        while(hash[lastidx]!=lastidx)
        {
            ans.push_back(nums[lastidx]);
            lastidx = hash[lastidx];
        }
        ans.push_back(nums[lastidx]);
        reverse(ans.begin(),ans.end());

        return ans;
    }
};