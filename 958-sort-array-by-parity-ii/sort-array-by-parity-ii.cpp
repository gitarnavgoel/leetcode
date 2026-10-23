class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int k =0;
        vector<int> temp1;
        vector<int> temp2;

        for(int i =0 ; i < n; i++)
        {
            if(nums[i]&1) temp1.push_back(nums[i]);
            else temp2.push_back(nums[i]);
        }
        vector<int> ans;

        for(int i =0 ; i< (n/2); i++)
        {
            ans.push_back(temp2[k]);
            ans.push_back(temp1[k]);
            k++;
        }
        return ans;
    }
};