class Solution {
public:
    bool check(string s1 , string s2)
    {
        if(s2.size()+1 != s1.size()) return false;

        int first = 0;
        int second= 0;

        while(first<s1.size())
        {
            if(second<s2.size() && s1[first] == s2[second])
            {
                first++;
                second++;
            }else{
                first++;
            }
        }

        if(first == s1.size() && second == s2.size())return true;
        return false;
    }
    static bool compare(string &s1 , string &s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);

        sort(words.begin(),words.end(),compare);

        int maxi = 1;
        for(int i =0 ; i < n ; i++)
        {
            for(int prev = 0 ; prev <i ; prev++)
            {
                if(check(words[i],words[prev]) && dp[i]<1+dp[prev])
                {
                    dp[i] = 1+dp[prev];
                }
            }
            if(dp[i]>maxi)
            {
                maxi = dp[i];
            }
        }

        return maxi;
    }
};