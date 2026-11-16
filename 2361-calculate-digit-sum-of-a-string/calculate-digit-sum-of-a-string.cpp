class Solution {
public:
    void change(string &s , int k)
    {
        int n = s.size();
        string ans = "";
        for(int i =0 ; i <n ; i+=k)
        {
            int temp= 0;
            int copy = k;
            int j = i;
            while(j<n)
            {
                temp+=(s[j]-'0');
                copy--;
                if(!copy) break;
                j++;
            }
            ans+=(to_string(temp));
        }
        s = ans;
        return;
    }
    string digitSum(string s, int k) {
        int n = s.size();

        while(s.size()>k)
        {
            change(s,k);
        }
        return s;
        
    }
};