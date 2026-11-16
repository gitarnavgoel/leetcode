class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        if(trust.size()==0) return -1;
        unordered_map<int,int> mp;
        for(int i =0 ; i < trust.size() ; i++)
        {
            mp[trust[i][1]]++;
        }
        int mx = 0;
        int head = -1;
        for(auto it : mp)
        {
            if(it.second>mx)
            {
                mx = it.second;
                head = it.first;
            }
        }
        if(mx!=n-1) return -1;
        for(int i =0 ; i < trust.size(); i++)
        {
            if(trust[i][0]==head) return -1;
        }
        return head;
    }
};