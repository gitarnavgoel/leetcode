class Solution {
public:
    int reverseBits(int n) {
        vector<bool> v(32,false);
        int i =0 ;
        while(n)
        {
            if(n&1) v[i] = true;
            i++;
            n>>=1;
        }
        int ans =0;

        for(int i =0 ; i < 32 ; i++)
        {
            ans<<=1;
            if(v[i])
            {
                ans|=1;
            }
        }
        return ans;
    }
};