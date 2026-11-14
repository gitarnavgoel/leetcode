class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int lsize, int rsize) {
        int ans = 1e9;
        int n = nums.size();
        // int l =0 , r= 0;
        // int curr =0;
        
        for(int i = 0 ;i < n ; i++)
        {
            int sum =0;
            for(int j =i ; j < n && (j-i+1)<=rsize ; j++)
            {
                int len = j-i+1;
                sum+=nums[j];
                if(len>=lsize && sum>0 )
                {
                    ans = min(ans,sum);
                }
            }
        }

        if(ans==1e9) return -1;
        return ans;
    }
};