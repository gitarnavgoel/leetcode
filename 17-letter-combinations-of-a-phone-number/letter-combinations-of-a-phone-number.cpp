class Solution {
public:
    void solver(int idx , string &dig , vector<string>&ans , unordered_map<char,vector<char>> &mp,string curr)
    {
        if(idx<0) 
        {
            reverse(curr.begin(),curr.end());
            ans.push_back(curr);
            return;
        }
        vector<char> temp = mp[dig[idx]];
        for(char c : temp)
        {
            curr+=c;
            solver(idx-1,dig,ans,mp,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string dig) {
        if(dig.empty()) return{};
        unordered_map<char,vector<char>>mp = {{'2' , {'a','b','c'}} , 
                                            {'3' , {'d','e','f'}} ,
                                            {'4' , {'g','h','i'}} ,
                                            {'5' , {'j','k','l'}} ,
                                            {'6' , {'m','n','o'} },
                                            {'7' , {'p','q','r','s'}} ,
                                            {'8' , {'t','u','v'}} ,
                                            {'9' , {'w','x','y','z'}} ,
                                            };
        int n = dig.size();
        vector<string> ans;
        string curr = "";
        solver(n-1,dig,ans,mp,curr);

        return ans;
        
    }
};