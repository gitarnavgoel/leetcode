class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        vector<int> temp;

        for(int i = 0 ;i <nums.size() ; i++)
        {
            if(nums[i]&1)
            {
                temp.push_back(nums[i]);
            }else ans.push_back(nums[i]);
        }

        ans.insert(ans.end(),temp.begin(),temp.end());
        return ans;
    }
};