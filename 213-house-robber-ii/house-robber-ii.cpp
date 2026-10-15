class Solution {
public:
int helper(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n;i++)
        {
            int take = nums[i]+prev2;
            int nottake = prev;

            int cur = max(take,nottake);

            prev2 = prev;
            prev = cur;
        }

        return prev;
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> v1(nums.begin(),nums.end()-1);
        vector<int> v2(nums.begin()+1,nums.end());
        int a1 = helper(v1);
        int a2 = helper(v2);
        return max(a1,a2);
    }
};