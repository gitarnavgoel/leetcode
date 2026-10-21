class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i : nums1) mp[i]++;

        unordered_set<int> ans;

        for(int x : nums2)
        {
            if(mp.count(x)) ans.insert(x);
        }

        return vector<int>(ans.begin(),ans.end());
    }
};